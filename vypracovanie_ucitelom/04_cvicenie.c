#include <stdio.h>

int cv4_floyd() {
  int i,j,n,k=0;
  FILE *f;

  printf("zadajte pocet riadkov (Floyd) od 1 do 10: ");
  scanf("%d", &n);
  if (n<1 || n>10) {
    printf("nespravny vstup\n");
    return -1;
  }

  if ((f = fopen("floyd.txt", "w")) == NULL) {
    printf("nepodarilo sa otvorit subor\n");
    return -2;
  }
  for (i=1; i<=n; i++) {
    for (j=1; j<=i; j++) {
        fprintf(f, "%d ", ++k);
        printf("%d ", k); // len naviac, na vizualnu kontrolu
    }
    fprintf(f, "\n");
    printf("\n");
  }

  fclose(f);
  return 0;
}

int cv4_hviezdicky() {
  FILE *f;
  int riadky, stlpce, r, s;

  if ((f = fopen("rozmery.txt", "r")) == NULL) {
    printf("nepodarilo sa otvorit subor\n");
    return -1;
  }

  if (fscanf(f, "%d %d", &riadky, &stlpce) < 2) {
    printf("nepodarilo sa nacitat rozmery\n");
    return -2;
  }

  for (r=1; r<=riadky; r++) {
    printf("%d: ", r);
    for (s=1; s<=stlpce; s++) {
        printf("*");
    }
    printf("\n");
    if (stlpce > 0) stlpce--;
  }

  fclose(f);


  return 0;
}

int cv4_dalsie_1() {
  int i,j,n;

  printf("zadajte pocet riadkov od 1 do 15: ");
  scanf("%d", &n);
  if (n<1 || n>15) {
    printf("nespravny vstup\n");
    return -1;
  }

  for (i=1; i<=n; i++) {
    printf("%d: ", i);
    for (j=1; j<=(n+1-i); j++) {
        printf("%3d", j);
    }
    printf("\n");
  }
  return 0;
}

int cv4_dalsie_2() {
  int i,j,n;

  printf("zadajte pocet riadkov od 1 do 15: ");
  scanf("%d", &n);
  if (n<1 || n>15) {
    printf("nespravny vstup\n");
    return -1;
  }

  for (i=1; i<=n; i++) {
    printf("%d: ", i);
    for (j=(n+1-i); j>=1; j--) {
        printf("%3d", j);
    }
    printf("\n");
  }
  return 0;
}

int cv4_dalsie_3() {

  int i,j,n;

  printf("zadajte cislo: ");
  scanf("%d", &n);

  int sucet = 0;
  for (i=1; i<=n; i++) {
    sucet += i;
    if (sucet % 3 == 0) printf("%2d", i);
  }
}

int cv4_dalsie_4() {

  int i,j,n;

  printf("zadajte NEPARNE cislo od 1 do 15: ");
  scanf("%d", &n);
  if (n < 1 || n > 15 || n%2== 0) {
    printf("nespravny vstup\n");
    return -1;
  }

  int sucet = 0;
  // toto riesenie pouziva jediny riadkovy cyklus
  // kto nerozumie.. vzdy je moznost kreslit to do polovice riadkov
  // a potom dalsim cyklom kreslit spodnu cast
  for (i=1; i<=2*n-1; i++) {
    if (i<=n) // toto kresli hornu polovicu + stred
      for (j=1; j<=n; j++) {
          // toto je este lahne.. tolko hviezdiciek kolky riadok
          if (j<=i) printf("*");
          else printf("-");
      }
    else // toto kresli spodnu polovicu
      for (j=1; j<=n; j++) {
          // toto je horsie odvodit.. pozrite sa na obrazok zo spodu..
          // uvedomte si kolko je i
          if (j<=2*n-i) printf("*");
          else printf("-");
      }
    printf("\n");
  }
}


int main() {

    //cv4_floyd();
    //cv4_hviezdicky();
    //cv4_dalsie_1();
    //cv4_dalsie_2();
    //cv4_dalsie_3();
    cv4_dalsie_4();
}
