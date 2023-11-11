#include <stdio.h>

int NacitajMaticu(char *subor, int matica[10][10]) {
    FILE *soubor;
    int i, j;

    soubor = fopen(subor, "r");
    if (soubor == NULL) {
        return 0;
    }

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (fscanf(soubor, "%d", &matica[i][j]) != 1) {
                fclose(soubor);
                return 0;
            }
        }
    }

    fclose(soubor);

    return 1;
}

int AnalyzujMaticu(int m[10][10], int *zaporne, int *neparne) {
    int maximum = m[0][0];
    *zaporne = 0;
    *neparne = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (m[i][j] < 0) {
                (*zaporne)++;
            }

            if (m[i][j] % 2 != 0) {
                (*neparne)++;
            }

            if (m[i][j] > maximum) {
                maximum = m[i][j];
            }
        }
    }

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

        printf("Matica:\n");
        VypisMaticu(m);
        printf("\n");
        printf("Zaporne: %d, Neparne: %d, Maximum: %d\n", zaporne, neparne, max);
    } else {
        printf("Citanie sa nepodarilo.\n");
    }

    return 0;
}
