#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    char priezvisko_meno[100];
    int rocnik;
    float priemer;
} STUDENT;

STUDENT *nacitajPole(char *subor, int *nacitane) {
    FILE *file = fopen(subor, "r");
    if (file == NULL) {
        printf("Chyba pri otvarani suboru.\n");
        return NULL;
    }

    int pocet;
    fscanf(file, "%d\n", &pocet);

    STUDENT *pole = (STUDENT *)malloc(pocet * sizeof(STUDENT));
    if (pole == NULL) {
        printf("Chyba pri alokacii pamate.\n");
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < pocet; ++i) {
        fgets(pole[i].priezvisko_meno, 100, file);

        fscanf(file, "%d\n%f\n", &pole[i].rocnik, &pole[i].priemer);
    }

    fclose(file);
    *nacitane = pocet;
    return pole;
}

void vypisPole(STUDENT *studenti, int pocet) {
    for (int i = 0; i < pocet; ++i) {
        printf("%s;", studenti[i].priezvisko_meno);
        printf("%d;%.1f\n", studenti[i].rocnik, studenti[i].priemer);
    }
}

STUDENT *najlepsiPole(STUDENT *studenti, int pocet, int rocnik) {
    STUDENT *najlepsi = NULL;
    float max_priemer = -1.0;

    for (int i = 0; i < pocet; ++i) {
        if (studenti[i].rocnik == rocnik && studenti[i].priemer > max_priemer) {
            max_priemer = studenti[i].priemer;
            najlepsi = &studenti[i];
        }
    }

    return najlepsi;
}

int main() {
    STUDENT *pole, *naj;
    int pocet;
    pole = nacitajPole("../subory/ziaci.txt", &pocet);
    if (pole == NULL) {
        printf("Nepodarilo sa nacitat a naplnit pole.\n");
        return -1;
    }

    vypisPole(pole, pocet);

    naj = najlepsiPole(pole, pocet, 3);
    if (naj == NULL) {
        printf("V rocniku nie je ziaden student.\n");
        free(pole);
        return -2;
    }

    printf("Najlepsi student je %s", naj->priezvisko_meno);

    free(pole);
    return 0;
}

