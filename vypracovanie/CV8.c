#include <stdio.h>

int NacitajMaticu(char *subor, int matica[10][10]) {
    FILE *soubor;
    int i, j;

    // a. Otvor�me s�bor
    soubor = fopen(subor, "r");
    if (soubor == NULL) {
        // Nepodarilo sa otvori� s�bor
        return 0;
    }

    // b. ��tame zo s�boru ��sla
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (fscanf(soubor, "%d", &matica[i][j]) != 1) {
                // ��tanie zlyhalo (napr. nie je dostato�n� po�et ��sel)
                fclose(soubor);
                return 0;
            }
        }
    }

    // Zatvor�me s�bor
    fclose(soubor);

    // c. �spe�n� na��tanie maticy
    return 1;
}


int AnalyzujMaticu(int m[10][10], int *zaporne, int *neparne) {
    int maximum = m[0][0]; // Predpoklad�me, �e prv� ��slo je najv��ie
    *zaporne = 0;
    *neparne = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            // Po��tame z�porn� ��sla
            if (m[i][j] < 0) {
                (*zaporne)++;
            }

            // Po��tame nep�rne ��sla
            if (m[i][j] % 2 != 0) {
                (*neparne)++;
            }

            // H�ad�me najv��ie ��slo
            if (m[i][j] > maximum) {
                maximum = m[i][j];
            }
        }
    }

    // Vr�time najv��ie ��slo v matici
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

        // V�pis matice
        printf("Matica:\n");
        VypisMaticu(m);
        printf("\n");
        // V�pis v�sledkov anal�zy
        printf("Zaporne: %d, Neparne: %d, Maximum: %d\n", zaporne, neparne, max);
    } else {
        printf("Citanie sa nepodarilo.\n");
    }

    return 0;
}
