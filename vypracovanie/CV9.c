#include <stdio.h>
#include <stdlib.h>


//Implementovanie z prednasky ()
int **create(int riadky, int stlpce) {
    int **p, i;
    p = (int **)malloc(riadky * sizeof(int *));
    for (i = 0; i < riadky; i++)
        p[i] = (int *)malloc(stlpce * sizeof(int));
    return p;
}




//Uloha prva
int **AlokujNapln(int *riadky, int *stlpce) {
    FILE *subor;
    //cast A
    subor = fopen("../subory/vstup_matice.txt", "r");

    if (subor == NULL) {
        printf("Subor sa nepodarilo otvorit.\n");
        return NULL;
    }
    //cast B
    if (fscanf(subor, "%d %d", riadky, stlpce) != 2) {
        printf("Chybny format suboru pre rozmery tabulky.\n");
        fclose(subor);
        return NULL;
    }
    //cast C
    int **pole = create(*riadky, *stlpce);
    //cast D,E a F
    for (int i = 0; i < *riadky; i++) {
        for (int j = 0; j < *stlpce; j++) {
            if (fscanf(subor, "%d", &pole[i][j]) != 1) {
                printf("Chybny format suboru pre obsah tabulky.\n");
                Uvolni(pole, *riadky);
                fclose(subor);
                return NULL;
            }
        }
    }

    fclose(subor);
    return pole;
}




//Uloha Druha
void Uvolni(int **p, int riadky) {
    for (int i = 0; i < riadky; i++)
        free(p[i]);
    free(p);
}




//Uloha Tretia
void Vypis(int **pole, int riadky, int stlpce) {
    printf("Obsah tabulky:\n");
    for (int i = 0; i < riadky; i++) {
        for (int j = 0; j < stlpce; j++) {
            printf("%d ", pole[i][j]);
        }
        printf("\n");
    }
}




//Uloha Stvrta
int NajdiMax(int **pole, int riadky, int stlpce, int *max_riadok, int *max_stlpec) {
    int max = pole[0][0];
    *max_riadok = 0;
    *max_stlpec = 0;

    for (int i = 0; i < riadky; i++) {
        for (int j = 0; j < stlpce; j++) {
            if (pole[i][j] > max) {
                max = pole[i][j];
                *max_riadok = i;
                *max_stlpec = j;
            }
        }
    }

    return max;
}

int main() {
    int **pole;
    int riadky, stlpce, max, max_riadok, max_stlpec;

    pole = AlokujNapln(&riadky, &stlpce);
    if (pole == NULL) {
        printf("Pole sa nepodarilo naplnit.\n");
        return 1;
    }

    Vypis(pole, riadky, stlpce);

    max = NajdiMax(pole, riadky, stlpce, &max_riadok, &max_stlpec);
    printf("Maximum pola [%d] sa naslo na suradnici [%d, %d]\n", max, max_riadok, max_stlpec);

    Uvolni(pole, riadky);
    return 0;
}
