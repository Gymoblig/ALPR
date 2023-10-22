#include <stdio.h>

int cv1_hello_word() {
  printf("Hello World!\n");
  return 0;
}

int cv1_priklad1() {
  printf("\"\tSu vsetky tieto [*,&,/,\\,$,%%,\'] znakyy specialne ?\"\n");
  return 0;
}

int cv1_priklad2() {
  int a, b, c;   
  printf("Zadaj 3 cele cisla: ");
  scanf("%d %d %d", &a, &b, &c);

  printf("Objem %d x %d x %d je %d\n", a, b, c, a*b*c);
  printf("Povrch 2 x %d x %d + 2 x %d x %d + 2 x %d x %d je %d\n", 
    a, b, a, c, b, c, 2*a*b + 2*a*c + 2*b*c);
  return 0;
}

int cv1_priklad3() {
  float r;   
  printf("Zadaj polomer kruhu (realne cislo): ");
  scanf("%f", &r);

  printf("Kruh s polomerom %.2f: obvod = %.2f, obsah = %.2f\n", r, 2*3.14*r, 3.14*r*r);  
  return 0;
}

int cv1_primemer() {
  float x,y,z;   
  printf("Zadaj 3 realne cisla: ");
  scanf("%f %f %f", &x, &y, &z);

  printf("Priemer cisel %f %f %f je: %f\n", x, y, z, (x+y+z) / 3.0);  
  return 0;
}

int cv1_DPH() {
  float cena;   
  printf("Zadaj cislo: ");
  scanf("%f", &cena);

  printf("Cena bez dane: %f\n", cena);
  printf("Predajna cena s danou %.2f\n", 1.2*cena);  
  return 0;
}

int cv1_BMI() {
  float  vyska, vaha;     
  printf("Zadajte vysku v centimetroch: ");
  scanf("%f", &vyska);
  printf("Zadajte hmotnost v kilogramoch: ");
  scanf("%f", &vaha);
  
  printf("BMI: %.2f\n", vaha / (vyska*vyska/10000.0) );  
  return 0;
}

int cv1_cisloformat() {
  float  cislo;     
  printf("Zadajte desatinne cislo: ");
  scanf("%f", &cislo);
  printf("%.0f\n", cislo);
  printf("%.1f\n", cislo);
  printf("%.2f\n", cislo);
  printf("%.3f\n", cislo);  
  return 0;
}

int main() {
    cv1_hello_word();
    cv1_priklad1();
    cv1_priklad2();
    cv1_priklad3();
    cv1_primemer();
    cv1_DPH();
    cv1_BMI();
	cv1_cisloformat();
}
