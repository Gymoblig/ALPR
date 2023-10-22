#include <stdio.h>

void clearbuffer() {
    while ((getchar()) != '\n');
}

int cv2_prva() {
  int a, b, c;
  printf("zadaj dve cisla oddelene medzerou:\n");
  scanf("%d %d", &a, &b);

  printf("a) vacsie z cisel %d a %d je %d\n", a, b, (a>b)?a:b );
  if (a<b) c=a;
  else c=b;
  printf("b) mensie z cisel %d a %d je %d\n", a, b, c);
  return 0;
}

int cv2_druha() {
  int ch;
  printf("zadaj jeden znak: ");

  ch = getchar();

  printf("na vstupe je: ");
  if (ch>='a' && ch<='z') printf("male pismeno");
  else if (ch>='A' && ch<='Z') printf("velke pismeno");
  else if (ch>='0' && ch<='9') printf("cislo");
  else printf("iny znak");
  printf("\n"); // aby to bolo pekne tak enter

  return 0;
}

int cv2_tretia() {
  int ch;
  printf("zadaj jeden znak: ");

  ch = getchar();

  printf("znak %c na vstupe ma ASCII hodnotu %d, alebo aj %x hexa\n", ch, ch, ch);
  if (ch>='a' && ch<='z') {
    ch+=('A'-'a');
    printf("male pismeno bolo zmenene na velke %c.\n", ch);
    printf("ktore ma ASCII hodnotu %d, alebo aj %x hexa\n", ch, ch);
  }

  return 0;
}

int cv2_stvrta() {
  float f;
  printf("Zadajte teplotu F: ");
  scanf("%f", &f);
  f = (f-32)*5.0/9.0;
  printf("Teplota v stupnoch celzia:: %.2f\n", f);

  if (f <= 0.0) printf("mrzne");
  else if (f >= 100.0) printf("vrie");
  printf("\n"); // aby to bolo pekne tak enter
}

int cv2_piata() {
  int a,b,c,m;
  printf("Zadajte 3 cisla: ");
  scanf("%d %d %d", &a, &b, &c);

  if (a<b && a<c)
    m = a;
  else if (b<a && b<c)
    m = b;
  else
    m = c;
  printf("Najmensie cislo z %d %d %d je: %d\n", a, b, c, m);
}

int cv2_piata_lepsie() {
  int a,b,c,m;
  printf("Zadajte 3 cisla: ");
  scanf("%d %d %d", &a, &b, &c);
  m=a;
  if (b<m) m=b;
  if (c<m) m=c;
  printf("Najmensie cislo z %d %d %d je: %d\n", a, b, c, m);
}

// VZDY to urobi maximalne na tri porovnania
int cv2_siesta_najlepsie() {
  int a,b,c;
  printf("Zadajte 3 cisla: ");
  scanf("%d %d %d", &a, &b, &c);

  printf("Usporiadany vysledok: ");
  if (a<b)
    if (b<c)
        printf("%d %d %d", a,b,c);
    else // b je vacsie ako c
      if (a<c)
        printf("%d %d %d", a,c,b);
      else // a je vacsie ako c
        printf("%d %d %d", c,a,b);
  else // a je vacsie ako b
    if (b>c)
      printf("%d %d %d", c,b,a);
    else //b je mensie ako c
      if (a<c)
        printf("%d %d %d", b,a,c);
      else // a je vacsie ako c
        printf("%d %d %d", b,c,a);

  printf("\n");
}

// toto riesenie pre situaciu C, B, A urobi 7 porovani
// skuste zistit PRECO, ktore to presne su
int cv2_siesta_prehladnejsie() {
  int a,b,c;
  printf("Zadajte 3 cisla: ");
  scanf("%d %d %d", &a, &b, &c);

  printf("Usporiadany vysledok: ");
  if (a<b && b<c)
    printf("%d %d %d", a,b,c);
  else if (a<c && c<b)
    printf("%d %d %d", a,c,b);
  else if (b<a && a<c)
    printf("%d %d %d", b,a,c);
  else if (b<c && c<a)
    printf("%d %d %d", b,c,a);
  else if (c<a && a<b)
    printf("%d %d %d", c,a,b);
  else
    printf("%d %d %d", c,b,a);
  printf("\n");
}

int cv2_siedma() {
  char a,b,c;
  printf("Zadajte 3 pismena: ");
  scanf("%c %c %c", &a, &b, &c);

  printf("Hodnotenie: ");
  if (a==b && a==c && b==c)
    printf("Vsetky pismena su rovnake");
  else if (a!=b && a!=c && b!=c)
    printf("Vsetky pismena su rozne");
  else
    printf("Dve pismena su rovnake");
  printf("\n");
}

int cv2_osma() {
  float  vyska, vaha, BMI;
  printf("Zadajte vysku v centimetroch: ");
  scanf("%f", &vyska);
  printf("Zadajte hmotnost v kilogramoch: ");
  scanf("%f", &vaha);

  BMI = vaha / (vyska*vyska/10000.0);
  printf("BMI je: %.2f\n", BMI );

  if (BMI <= 18.5) printf("podvaha");
  // uvedomte si ze ked sa program dostane sem do tohoto else
  // plati ze BMI>18.5 a tak spodnu hranicu nemusime testovat
  else if (BMI < 25) printf("Normalna hmotnost");
  // zase .. tu sme lebo BMI je viac ako 25 ...
  else if (BMI < 30) printf("Nadvaha");
  // no a tu sme nad 30 ...
  else printf("Obezita");
  // zaver.. toto je trosku chytak. lebo zlozena podmienka tu nie je treba
  // bude fungovat.. ale optimalne riesenie ju NEPOTREBUJE
  return 0;
}

int main() {

    cv2_prva();
    clearbuffer();
    cv2_druha();
    clearbuffer();
    cv2_tretia();
    clearbuffer();
    cv2_stvrta();
    cv2_piata();
    cv2_piata_lepsie();
    cv2_siesta_najlepsie();
    cv2_siesta_prehladnejsie();
    cv2_siedma();
    cv2_osma();
}
