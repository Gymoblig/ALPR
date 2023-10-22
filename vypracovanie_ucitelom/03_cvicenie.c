#include <stdio.h>

void clearbuffer() {
    while ((getchar()) != '\n');
}

int cv3_prva() {
  int n, i, pocetZ = 0, pocetS = 0;
  float cislo, sucetZ = 0.0, max = 0.0;

  printf("zadajte pocet realnych cisel: ");
  scanf("%d", &n);

  for (i=1;i<=n;i++) {
    printf("Zadajte %d.: ", i);
    scanf("%f", &cislo);
    if (cislo < 0) { sucetZ += cislo; pocetZ++; }
    else if (cislo > max) max = cislo;
    if (cislo >= -5.5 && cislo <= 5.5) pocetS++;
  }

  printf("Priemer zapornych je %.2f\n", (pocetZ==0)?0:sucetZ/pocetZ );
  printf("Maximum z kladnych je %.2f\n", max );
  printf("Pocet v rozsahu -5.5 a 5.5 je %d\n", pocetS );
  return 0;
}

int cv3_druha() {
  int ch, male = 0, velke = 0, cisla = 0 ;
  printf("zadajte retazec: ");

  while ((ch = getchar()) != '\n') {
    if (ch>='0' && ch<='9') cisla++;
    else if (ch>='a' && ch<='z') male++;
    else if (ch>='A' && ch<='Z') velke++;
  }

  printf("Male: %d\n", male );
  printf("Velke: %d\n", velke );
  printf("Cisla: %d\n", cisla );

  return 0;
}

int cv3_tretia() {
  int zaciatok, koniec, delitel, cislo;
  printf("zadajte hranice intervalu a delitel: ");

  scanf("%d %d %d", &zaciatok, &koniec, &delitel);

  printf("V itervale <%d, %d> su delitelne cislom %d cisla: ", zaciatok, koniec, delitel);
  for (cislo=zaciatok; cislo <= koniec; cislo++) {
    if (!(cislo % delitel)) printf(" %d", cislo);
  }
  printf("\n");
  return 0;
}

int cv3_stvrta() {
  int n;
  printf("zadajte cislo - velkost stvorca: ");
  scanf("%d", &n);

  for (int riadok=1; riadok <= n; riadok++) {
    for (int stlpec=1; stlpec <= n; stlpec++) {
        printf("* ");
    }
    printf("\n");
  }
}

int cv3_piata() {
  int n;
  printf("zadajte cislo - velkost stvorca: ");
  scanf("%d", &n);

  for (int riadok=1; riadok <= n; riadok++) {
    for (int stlpec=1; stlpec <= n; stlpec++) {
        if ((riadok == 1) || (riadok == n) || (stlpec == 1) || (stlpec == n)) printf("+ ");
        else printf("* ");
    }
    printf("\n");
  }
}

int cv3_siesta() {
  int n;
  printf("zadajte cislo - velkost stvorca: ");
  scanf("%d", &n);

  for (int riadok=1; riadok <= n; riadok++) {
    for (int stlpec=1; stlpec <= n; stlpec++) {
        if ( (riadok % 2) &&  (stlpec % 2) || // neparny riadok a neparny stlpec
            !(riadok % 2) && !(stlpec % 2)    // parny riadok a parny stlpec
           ) printf("* ");
        else printf("+ ");
    }
    printf("\n");
  }
}

int main() {

    //cv3_prva();
    //clearbuffer();
    //cv3_druha();
    //clearbuffer();
    //cv3_tretia();
    //cv3_stvrta();
    //cv3_piata();
    cv3_siesta();
}
