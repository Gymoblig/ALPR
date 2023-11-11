#include <stdio.h>

int NacitajMaticu(char *subor, int matica[10][10]) {
    FILE *soubor;
    int i, j;

    // a. Otvoríme súbor
    soubor = fopen(subor, "r");
    if (soubor == NULL) {
        // Nepodarilo sa otvori súbor
        return 0;
    }

    // b. Èítame zo súboru èísla
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (fscanf(soubor, "%d", &matica[i][j]) != 1) {
                // Èítanie zlyhalo (napr. nie je dostatoènı poèet èísel)
                fclose(soubor);
                return 0;
            }
        }
    }

    // Zatvoríme súbor
    fclose(soubor);

    // c. Úspešné naèítanie maticy
    return 1;
}


int AnalyzujMaticu(int m[10][10], int *zaporne, int *neparne) {
    int maximum = m[0][0]; // Predpokladáme, e prvé èíslo je najväèšie
    *zaporne = 0;
    *neparne = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            // Poèítame záporné èísla
            if (m[i][j] < 0) {
                (*zaporne)++;
            }

            // Poèítame nepárne èísla
            if (m[i][j] % 2 != 0) {
                (*neparne)++;
            }

            // H¾adáme najväèšie èíslo
            if (m[i][j] > maximum) {
                maximum = m[i][j];
            }
        }
    }

    // Vrátime najväèšie èíslo v matici
    return maximum;
}



void VypisMaticu(int m[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%5d ", m[i][j]);
        }
        printf("\n");
    }
}



int main() {
    int m[10][10], zaporne, neparne, max;

    if (NacitajMaticu("../subory/matica.txt", m)) {
        max = AnalyzujMaticu(m, &zaporne, &neparne);

        // Vıpis matice
        printf("Matica:\n");
        VypisMaticu(m);
        printf("\n");
        // Vıpis vısledkov analızy
        printf("Zaporne: %d, Neparne: %d, Maximum: %d\n", zaporne, neparne, max);
    } else {
        printf("Citanie sa nepodarilo.\n");
    }

    return 0;
}
