#include <stdio.h>
#include <string.h>

int analyzuj(char *subor, int *riadky, int *medzery, int *cisla) {
    FILE *file = fopen(subor, "r");
    if (file == NULL) {
        return -1; // Nepodarilo sa otvori súbor
    }

    int pocet_riadkov = 0;
    int pocet_medzier = 0;
    int pocet_cislic = 0;
    int velkost = 0;

    char znak;
    while ((znak = fgetc(file)) != EOF) {
        velkost++;
        if (znak == '\n') {
            pocet_riadkov++;
        } else if (znak == ' ') {
            pocet_medzier++;
        } else if (znak >= '0' && znak <= '9') {
            pocet_cislic++;
        }
    }

    fclose(file);

    *riadky = pocet_riadkov;
    *medzery = pocet_medzier;
    *cisla = pocet_cislic;

    return velkost;
}

char *sifruj_a_odsifruj(char *sprava, char *heslo, int sifrovat) {
    int dlzka_spravy = strlen(sprava);
    int dlzka_hesla = strlen(heslo);

    for (int i = 0; i < dlzka_spravy; i++) {
        if (sprava[i] >= 'A' && sprava[i] <= 'Z') {
            int offset = heslo[i % dlzka_hesla] - 'A'+1;
            if (sifrovat) {
                sprava[i] = 'A' + (sprava[i] - 'A' + offset) % 26;
            } else {
                sprava[i] = 'A' + (sprava[i] - 'A' - offset + 26) % 26;
            }
        }
    }

    return sprava;
}

void bonuscv1() {
    char retazec[100];
    printf("Zadajte retazec: ");
    scanf("%s", retazec);

    int i, j = 0;

    while (retazec[i] != '\0') {
        if (retazec[i] == '*') {
            printf("**");
        } else if (retazec[i] != '.') {
            printf("%c", retazec[i]);
        }
        i++;
    }

    printf("\n");
}

void bonuscv2() {
    const char *inputFileName = "../subory/input.txt";
    const char *outputFileName = "../subory/output.txt";

    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Nepodarilo sa otvorit subor.\n");
        return;
    }

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Nepodarilo sa otvorit subor.\n");
        fclose(inputFile);
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        int len = 0;
        while (line[len] != '\0') {
            len++;
        }
        for (int i = len - 2; i >= 0; i--) {
            fputc(line[i], outputFile);
        }
        fputc('\n', outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Subor s obratenymi riadkami bol vytvoreny.\n");
}


int main() {
    char sprava[100];
    char heslo[100];
    printf("Zadajte text na sifrovanie: ");
    scanf("%s", sprava);
    printf("Zadajte sifru / heslo: ");
    scanf("%s", heslo);

    char *zasifrovana_sprava = sifruj_a_odsifruj(sprava, heslo, 1);
    printf("Vystup sifrovania: %s\n", zasifrovana_sprava);

    char *odsifrovana_sprava = sifruj_a_odsifruj(zasifrovana_sprava, heslo, 0);
    printf("Vystup desifrovania: %s\n", odsifrovana_sprava);

    int riadky, medzery, cisla, velkost;
    velkost = analyzuj("../subory/vstup.txt", &riadky, &medzery, &cisla);

    if (velkost == -1) {
        printf("Subor sa nepodarilo otvorit!\n");
    } else {
        printf("Subor ma znakov %d, pocet riadkov %d, medzier: %d a cisla %d\n", velkost, riadky, medzery, cisla);
    }



    bonuscv1();
    bonuscv2();
    return 0;
}
