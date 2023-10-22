#include <stdio.h>
#include <stdlib.h>

void clearbuffer()
{
    while ((getchar()) != '\n');
}

void cv1() {
    printf("CVICENIE 1\n");
    FILE *subor = fopen("../subory/vystup.txt", "w");
    if (subor == NULL) {
        printf("Nepodarilo sa otvorit subor.\n");
        return;
    }

    int c;
    printf("Zadajte retazec: ");
    while (1) {
        c = getchar();

        if (c == EOF || c == '.') {
            break;
        }

        if (c >= 'A' && c <= 'Z') {
            c = c + 32;
        } else if (c >= 'a' && c <= 'z') {
            c = '.';
        } else if (c >= '0' && c <= '9') {
            c = '-';
        } else if (c == '\n') {
        } else {
            c = '*';
        }

        fputc(c, subor);
    }

    fclose(subor);
}

void cv2()
{
    printf("CVICENIE 2\n");
    FILE *subor = fopen("../subory/cisla1.txt", "r");
    if (subor == NULL) {
        printf("Nepodarilo sa otvorit subor cisla.txt.\n");
        return;
    }

    int pole[100];
    int pocet = 0;
    int cislo;

    while (fscanf(subor, "%d", &cislo) != EOF) {
        pole[pocet] = cislo;
        pocet++;
    }

    for (int i = pocet - 1; i >= 0; i--) {
        if (pole[i] % 2 == 0) {
            printf("%d ", pole[i]);
        }
    }

    fclose(subor);
}


void cv3()
{
    printf("CVICENIE 3\n");
    float cislo;
    printf("Zadaj cislo: ");
    scanf("%f",&cislo);
    FILE *subor = fopen("../subory/nasobky.txt", "w");
    if (subor == NULL) {
        printf("Nepodarilo sa otvorit subor.\n");
        return;
    }
    for (int i = 1; i <= 10; i++){
        fprintf(subor,"%2d:%8.2f,%8.2f,%8.2f\n",i,i*cislo,i*cislo*2,i*cislo*cislo);
    }
    fclose(subor);
}

void cv4()
{
    printf("CVICENIE 4\n");
    FILE *vstupSubor = fopen("../subory/znak.txt", "r");
    if (vstupSubor == NULL) {
        printf("Nepodarilo sa otvorit subor ZNAK.TXT\n");
        return 1;
    }
    printf("Zadajte znak: ");
    int znak = getchar();

    if (znak == 's') {
        FILE *vystupSubor = fopen("../subory/novy.txt", "w");
        if (vystupSubor == NULL) {
            printf("Nepodarilo sa otvorit subor NOVY.TXT\n");
            return 1;
        }

        int c;
        while ((c = fgetc(vstupSubor)) != EOF) {
            fputc(c, vystupSubor);
        }

        fclose(vystupSubor);
    } else {
        int c;
        while ((c = fgetc(vstupSubor)) != EOF) {
            putchar(c);
        }
    }

    fclose(vstupSubor);

}

void cv5() {
    printf("CVICENIE 5\n");
    FILE *subor1 = fopen("../subory/prvy.txt", "r");
    FILE *subor2 = fopen("../subory/druhy.txt", "r");

    if (subor1 == NULL || subor2 == NULL) {
        printf("Nepodarilo sa otvorit subory.\n");
        return;
    }

    int rozne = 0;
    int i = 0;
    char znak1, znak2;

    while (1) {
        znak1 = fgetc(subor1);
        znak2 = fgetc(subor2);

        if (znak1 == EOF && znak2 == EOF) {
            break;
        }

        if (znak1 != znak2) {
            rozne++;
        }

        i++;
    }

    long dlzka_prvy = ftell(subor1);
    long dlzka_druhy = ftell(subor2);
    long vysledok = dlzka_prvy - dlzka_druhy;
    vysledok = abs(vysledok);
    rozne = rozne-vysledok;

    fclose(subor1);
    fclose(subor2);

    if (rozne == 0) {
        printf("Subory su identicke\n");
    } else {
        printf("Pocet roznych znakov: %d\n", rozne);
        if (vysledok > 0) {
            printf("Jeden zo suborov je dlhsi o %d znakov\n", vysledok);
        }
    }
}

void cv6()
{
    printf("CVICENIE 6\n");
    FILE *vstup = fopen("../subory/vstup.txt", "r");
    FILE *cisla = fopen("../subory/cisla2.txt", "a");
    if (vstup == NULL || cisla == NULL) {
        return 1;
    }

    int znak;
    int pocet_malych_pismen = 0;

    while ((znak = fgetc(vstup)) != EOF) {
        fputc(znak, cisla);

        if (znak >= 'a' && znak <= 'z') {
            pocet_malych_pismen++;
        }

        if (znak == '\n') {
            fprintf(cisla, "%d\n", pocet_malych_pismen);
            pocet_malych_pismen = 0;
        }
    }

    fclose(vstup);
    fclose(cisla);
}

void cv7() {
    printf("CVICENIE 7\n");
    FILE *soubor = fopen("../subory/text.txt", "r");

    if (soubor == NULL) {
        printf("Nepodarilo sa otvorit subor.\n");
        return;
    }

    int znak;
    int pocet_medzier = 0;

    while ((znak = fgetc(soubor)) != EOF) {
        if (znak == 'x' || znak == 'X') {
            printf("Precital som X\n");
        } else if (znak == 'y' || znak == 'Y') {
            printf("Precital som Y\n");
        } else if (znak == '#' || znak == '$' || znak == '&') {
            printf("Precital som riadiaci znak\n");
        } else if (znak == '*') {
            printf("Koniec\n");
            break;
        } else if (znak == ' ') {
            pocet_medzier++;
        }
    }

    fclose(soubor);
    printf("Pocet precitanych medzier: %d\n", pocet_medzier);
}

void cv8() {
    printf("CVICENIE 8\n");
    int cislo1, cislo2;
    int sucet = 0;

    printf("Zadajte dve cele cisla oddelene medzerou a ukoncene enterom: ");
    scanf("%d %d", &cislo1, &cislo2);

    if (cislo1 > cislo2) {
        int temp = cislo1;
        cislo1 = cislo2;
        cislo2 = temp;
    }

    for (int i = cislo1+1; i <= cislo2-1; i++) {
        sucet += i;
    }

    if (cislo1 <= cislo2) {
        printf("%d\n", sucet);
    } else {
        printf("Neda sa vypocitat\n");
    }
}
void cv9()
{
    printf("CVICENIE 9\n");
    int cislo,vysledok=1;
    printf("Zadaj cislo: ");
    scanf("%d",&cislo);
    for (int i =1;i<=cislo;i++){
        vysledok *=i;
    }
    printf("Vysledok je: %d\n",vysledok);

}

void cv10() {
    printf("CVICENIE 10\n");
    int p, k;
    printf("Zadaj dve cele cisla p a k (0 < p, k < 100): ");
    scanf("%d %d", &p, &k);

    if (p <= 0 || p >= 100 || k <= 0 || k >= 100) {
        printf("Zle zadane cisla\n");
        return;
    }

    for (int i = 1; i <= p; i++) {
        if (i % k != 0) {
            printf("%2d ", i);
        } else {
            printf("-- ");
        }
    }

    printf("\n");
}
int main() {
    cv1();
    clearbuffer();
    cv2();
    clearbuffer();
    cv3();
    clearbuffer();
    cv4();
    clearbuffer();
    cv5();
    clearbuffer();
    cv6();
    clearbuffer();
    cv7();
    clearbuffer();
    cv8();
    clearbuffer();
    cv9();
    clearbuffer();
    cv10();
    clearbuffer();
    return 0;
}
