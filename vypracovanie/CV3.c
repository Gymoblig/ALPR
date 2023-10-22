#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


void clearbuffer()
{
    while ((getchar()) != '\n');
}

void cv1() {
    int n;
    printf("Zadajte pocet realnych cisel: ");
    scanf("%d", &n);
    double zaporne = 0;
    double kladne_max = 0;
    int rozsah = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        double cislo;
        printf("Zadaj %d.: ", i + 1);
        scanf("%lf", &cislo);

        if (cislo < 0) {
            zaporne += cislo;
            j++;
        }
        if (cislo > 0 && cislo > kladne_max) {
            kladne_max = cislo;
        }
        if (cislo >= -5.5 && cislo <= 5.5) {
            rozsah++;
        }
    }
    printf("Priemer zapornych: %.2lf\n", (j > 0) ? (zaporne / j) : 0);
    printf("Maximum z kladnych: %.2lf\n", kladne_max);
    printf("Pocet v rozsahu -5.5 a 5.5: %d\n", rozsah);
}

void cv2() {

    int male = 0, velke = 0, cisla = 0;
    char znak;
    printf("Zadajte retazec: ");

    while (1) {
        znak = getchar();
        if (znak == '\n') {
            break;
        }
        if (islower(znak)) {
            male++;
        } else if (isupper(znak)) {
            velke++;
        } else if (isdigit(znak)) {
            cisla++;
        }
    }
    printf("Male: %d\n", male);
    printf("Velke: %d\n", velke);
    printf("Cisla: %d\n", cisla);

}

void cv3() {
    int F, G, D;

    printf("Zadajte hranice intervalu a delitel: ");
    scanf("%d %d %d", &F, &G, &D);
    printf("V intervale <%d,%d> su delitelne cislo %d cisla: ", F, G, D);

    for (int i = F; i <= G; i++) {
        if (i % D == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void bonuscv1() {
    int N;
    printf("Zadajte cislo N: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void bonuscv2() {
    int N;
    printf("Zadajte cislo N: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || i == N - 1 || j == 0 || j == N - 1) {
                printf("+ ");
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

void bonuscv3() {
    int N;
    printf("Zadajte cislo N: ");
    scanf("%d", &N);

     for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || i == N - 1 || j == 0 || j == N - 1) {
                printf("+ ");
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int main() {
    /*cv1();
    clearbuffer();
    cv2();
    clearbuffer();
    cv3();
    clearbuffer();
    bonuscv1();
    clearbuffer();
    bonuscv2();
    clearbuffer();*/
    bonuscv3();
    clearbuffer();
    return 0;
}
