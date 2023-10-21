#include <stdio.h>


void clearbuffer()
{
    while ((getchar()) != '\n');
}

int cv1()
{
    int n;

    printf("Zadajte pocet riadkov Floydovho trojuholnika od 1 do 10: ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Nespravny vstup\n");
        return 1;
    }

    FILE *subor = fopen("floyd.txt", "w");

    int cislo = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            fprintf(subor, "%d", cislo);

            if (j < i) {
                fprintf(subor, " ");
            }

            cislo++;
        }
        fprintf(subor, "\n");
    }

    fclose(subor);
}

void cv2(const char *subor) {
    FILE *files = fopen(subor, "r");
    if (files == NULL) {
        printf("Nepodarilo sa otvorit subor.\n");
        return;
    }

    int riadky, stlpce;
    int nacitane = fscanf(files, "%d %d", &riadky, &stlpce);

    fclose(files);

    for (int i = 1; i <= riadky; i++) {
        printf("%d: ", i);
        for (int j = 1; j <= stlpce; j++) {
            if (j <= stlpce - i + 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}


void bonuscv1()
{
    int n;
    printf("Zadajte pocet riadkov od 1 do 15: ");
    scanf("%d", &n);
    if (n < 1 || n > 15) {
        printf("Cislo nie je z daneho intervalu\n");
        return;
    }

    for (int i = 1; i <= n; i++) {
        printf("%d: ", i);
        for (int j = 1; j <= n - i + 1; j++) {
            printf("%2d", j);
            if (j < n - i + 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}



void bonuscv2()
{
    int n;
    printf("Zadajte pocet riadkov od 1 do 15: ");
    scanf("%d", &n);
    if (n < 1 || n > 15) {
        printf("Cislo nie je z daneho intervalu\n");
        return;
    }

    FILE *subor = fopen("cisla.txt", "w");
    if (subor == NULL) {
        printf("Nepodarilo sa otvorit subor pre zapis.\n");
        return;
    }

    for (int i = 1; i <= n; i++) {
        fprintf(subor, "%d: ", i);
        for (int j = n; j >= i; j--) {
            fprintf(subor, "%2d", j);
            if (j > i) {
                fprintf(subor, " ");
            }
        }
        fprintf(subor, "\n");
    }

    fclose(subor);
    printf("Hodnoty boli zapisane do suboru CISLA.TXT\n");
}


void bonuscv3()
{
    int n;
    printf("Zadajte cele cislo n: ");
    scanf("%d", &n);
    for (int k = 1; k <= n; k++) {
        int sucet = 0;
        for (int i = 1; i <= k; i++) {
            sucet += i;
        }
        if (sucet % 3 == 0) {
            printf("%d ", k);
        }
    }
    printf("\n");
}

void bonuscv4()
{
    int n;
    printf("Zadajte neparne cislo od 1 do 15: ");
    scanf("%d", &n);
    if (n < 1 || n > 15 || n % 2 == 0) {
        printf("Zly vstup\n");
        return;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        for (int j = i + 1; j <= n; j++) {
            printf("-");
        }
        printf("\n");
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        for (int j = i + 1; j <= n; j++) {
            printf("-");
        }
        printf("\n");
    }
}

void bonuscv5()
{
    int n;
    printf("Zadajte cele cislo n: ");
    scanf("%d", &n);
    if (n < 1 || n > 15 || n % 2 == 0) {
        printf("Zly vstup\n");
        return;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == i || j == n - i + 1 || i == n / 2 + 1) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}


void bonuscv6()
{
    int n,v;
    printf("Zadajte cele cisla \"n\" a \"v\" : ");
    scanf("%d %d", &n,&v);
    if (n < 1 || n > 15 || n % 2 == 0 || v > 5 || v<1 ) {
        printf("Zly vstup\n");
        return;
    }
    for (int x =1; x<=v; x++){
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (j == i || j == n - i + 1 || i == n / 2 + 1) {
                    printf("*");
                } else {
                    printf("-");
                }
            }
            printf("\n");
        }
    }
}

void bonuscv7()
{
    int n, s;
    printf("Zadajte cele cisla \"n\" a \"s\" : ");
    scanf("%d %d", &n, &s);

    if (n < 1 || n > 15 || n % 2 == 0 || s > 5 || s < 1) {
        printf("Zly vstup\n");
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int x = 1; x <= s; x++) {
            for (int j = 1; j <= n; j++) {
                if (j == i || j == n - i + 1 || i == n / 2 + 1) {
                    printf("*");
                } else {
                    printf("-");
                }
            }
            if (x < s) {
                printf(" "); // Toto robí medzeru medzi tvarmi
            }
        }
        printf("\n");
    }
}
int main()
{
    cv1();
    clearbuffer();
    cv2("rozmery.txt");
    clearbuffer();
    bonuscv1();
    clearbuffer();
    bonuscv2();
    clearbuffer();
    bonuscv3();
    clearbuffer();
    bonuscv4();
    clearbuffer();
    bonuscv5();
    clearbuffer();
    bonuscv6();
    clearbuffer();
    bonuscv7();
}
