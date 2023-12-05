#include <stdio.h>

typedef struct student {
    char priezvisko_meno[100];
    int rocnik;
    float priemer;
    struct student *dalsi;
} STUDENT;

STUDENT *nacitajSpajany(char *subor) {
    int nacitane;
    STUDENT *prvy = NULL, *posledny = NULL, *akt;
    FILE *f = fopen(subor, "r");
    if (f == NULL) return NULL;

    fscanf(f, "%d\n", &nacitane);
    if (nacitane < 1) return NULL;

    int i;
    for (i = 0; i < nacitane; i++) {
        akt = (STUDENT *)malloc(sizeof(STUDENT));
        fgets(akt->priezvisko_meno, 100, f);
        akt->priezvisko_meno[strlen(akt->priezvisko_meno) - 1] = '\0';
        fscanf(f, "%d\n", &akt->rocnik);
        fscanf(f, "%f\n", &akt->priemer);
        akt->dalsi = NULL;

        if (prvy == NULL) prvy = akt;
        if (posledny != NULL) posledny->dalsi = akt;
        posledny = akt;
    }

    fclose(f);
    return prvy;
}

void vypisSpajany(STUDENT *studenti) {
    while (studenti != NULL) {
        printf("%s;%d;%.1f\n", studenti->priezvisko_meno, studenti->rocnik, studenti->priemer);
        studenti = studenti->dalsi;
    }
}

STUDENT *najlepsiSpajany(STUDENT *studenti, int rocnik) {
    STUDENT *naj = NULL;
    float najpriem = 5.0;
    while (studenti != NULL) {
        if (studenti->rocnik == rocnik) {
            if (naj == NULL) naj = studenti;
            else if (studenti->priemer < naj->priemer) naj = studenti;
        }
        studenti = studenti->dalsi;
    }
    return naj;
}

void uvolniSpajany(STUDENT *studenti) {
    STUDENT *f;
    while (studenti != NULL) {
        f = studenti;
        studenti = studenti->dalsi;
        free(f);
    }
}

int main() {
    STUDENT *s, *naj;

    s = nacitajSpajany("../subory/ziaci.txt");
    if (s == NULL) {
        printf("nepodarilo sa nacitat a naplnit pole");
        return -1;
    }
    vypisSpajany(s);
    naj = najlepsiSpajany(s, 3);
    if (naj == NULL) {
        printf("v rocniku nieje student");
        return -2;
    }
    printf("najlepsi student je %s", naj->priezvisko_meno);
    uvolniSpajany(s);
    return 0;
}
