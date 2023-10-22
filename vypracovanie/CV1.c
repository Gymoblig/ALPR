#include <stdio.h>
#include <math.h>

int cvicenie1()
{
    printf("\"\tSu vsetky tieto [*,&,/,\\,$,%%,'] znaky specialne?\"\n");
    printf("Mas 100%% pravdu. \n/ a \\ su rozdielne znaky.\nZnak \" je problematicky!\n");
}

int cvicenie2()
{
    int cislo1;
    int cislo2;
    int cislo3;
    printf("Zadaj 3 cele cisla: ");
    scanf("%d %d %d",&cislo1,&cislo2,&cislo3);
    int objem = cislo1 * cislo2 * cislo3;
    int povrch = 2*(cislo1 * cislo2) + 2*(cislo1 * cislo3) + 2*(cislo2 * cislo3);
    printf("Objem %d x %d x %d je %d\n",cislo1,cislo2,cislo3,objem);
    printf("Povrch 2x(%d x %d) + 2x(%d x %d) + 2x(%d x %d) je %d\n",cislo1,cislo2,cislo1,cislo3,cislo2,cislo3,povrch);
}
int cvicenie3()
{
    float polomer;
    printf("Zadaj polomer kruhu (realne cislo): ");
    scanf("%f",&polomer);
    float obvod = 2*M_PI*polomer;
    float obsah = M_PI*pow(polomer,2);
    printf("Kruh s polomerom %.2f: obvod = %.2f, obsah = %.2f\n",polomer,obvod,obsah);
}

int cvicenie4()
{
    float x,y,z;
    printf("Zadaj 3 realne cisla: ");
    scanf("%f %f %f",&x,&y,&z);
    float priemer = (x+y+z)/3;
    printf("Priemer cisel %.2f, %.2f a %.2f je: %.2f \n",x,y,z,priemer);
}

int cvicenie5()
{
    float cislo;
    printf("Zadaj cislo: ");
    scanf("%f",&cislo);
    float dan = (cislo*0.2)+cislo;
    printf("Cena bez dane %.2f \nPredajna cena s danou 20%%: %.2f \n", cislo,dan);
}
int cvicenie6()
{
    float vyska;
    float hmostnost;
    printf("Zadajte vysku v centimetroch: ");
    scanf("%f",&vyska);
    printf("Zadjate hmostnost v kilogramoch: ");
    scanf("%f",&hmostnost);
    float vyska_m = vyska/100;
    float BMI = hmostnost/pow(vyska_m,2);
    printf("BMI: %.3f\n",BMI);
}
int cvicenie7()
{
    float cisielko;
    printf("Zadaj cislo: ");
    scanf("%f",&cisielko);
    printf("Vystup:\n%.0f\n%.1f\n%.2f\n%.3f\n",cisielko,cisielko,cisielko,cisielko);
}
int main()
{
    cvicenie1();
    cvicenie2();
    cvicenie3();
    cvicenie4();
    cvicenie5();
    cvicenie6();
    cvicenie7();
    getch();
    return 0;
}
