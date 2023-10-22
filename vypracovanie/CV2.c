#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>


int cv1()
{
    long x,y,vyssie;
    printf("Zadaj dve cisla oddelene medzerou: ");
    scanf("%ld %ld",&x,&y);
    vyssie = (x>y) ? x : y;
    printf("a) vacsie z cisel %ld a %ld je %ld\n",x,y,vyssie);
    if (x>y){
        printf("b) mensie z cisel %ld a %ld je %ld\n",x,y,y);
    }
    else {
        printf("b) mensie z cisel %ld a %ld je %ld\n",x,y,x);
    }
}

int cv2()
{
    char znak,*vysledok;
    printf("Zadaj jeden znak: ");
    znak = getchar();

    if (znak >= 65 && znak <= 90) {
        vysledok = "velke pismeno";
    }
    else if (znak >= 97 && znak <= 122) {
        vysledok = "male pismeno";
    }
    else if (znak >= 48 && znak <= 57) {
        vysledok = "cislo";
    }
    else {
        vysledok = "iny znak";
    }
    printf("na vstupe je: %s\n",vysledok);

}

int cv3()
{
    char pismeno,new_p;

    printf("Zadaj jeden znak: ");
    pismeno = getchar();
    printf("znak %c na vstupe ma ASCII hodnotu %d, alebo aj %x Hexa\n",pismeno,pismeno,pismeno);
    if (pismeno >= 97 && pismeno <= 122){
        new_p = pismeno - 32;
        printf("male pismeno bolo zmenene na velke %c,\nktore ma ASCII hodnotu %d, alebo aj %x Hexa\n",new_p,new_p,new_p);

    }
}

int bonuscv1()
{
    long far,cel;
    printf("Zadajte teplotu vo Fahrenheitoch: ");
    scanf("%ld",&far);
    cel = ((far-32)*5)/9;
    printf("Tepolota v stupnoch celzia: %.2ld\n",cel);
    if (cel>=100){
        printf("Vrie\n");
    }
    else if (cel<=0){
        printf("Mrzne\n");
    }
}

int bonuscv2()
{
    int cislo1,cislo2,cislo3,vysledok;

    printf("Zadajte 3 cisla: ");
    scanf("%d %d %d",&cislo1,&cislo2,&cislo3);

    if (cislo1<= cislo2 && cislo1<=cislo3){
        vysledok = cislo1;
    }
    else if (cislo2<=cislo1 && cislo2<=cislo3){
        vysledok = cislo2;
    }
    else{
        vysledok = cislo3;
    }
    printf("Najmensie cislo z %d %d %d je: %d\n",cislo1,cislo2,cislo3,vysledok);
}


int bonuscv3()
{
    int cislo1,cislo2,cislo3,pom_premenna;

    printf("Zadajte 3 cisla: ");
    scanf("%d %d %d",&cislo1,&cislo2,&cislo3);

    if (cislo1>=cislo2){
        pom_premenna = cislo1;
        cislo1= cislo2;
        cislo2= pom_premenna;
    }
    if (cislo1>=cislo3){
        pom_premenna = cislo1;
        cislo1= cislo3;
        cislo3= pom_premenna;
    }
    if (cislo2>=cislo3){
        pom_premenna = cislo2;
        cislo2= cislo3;
        cislo3= pom_premenna;
    }
    printf("Usporiadany vysledok: %d %d %d\n",cislo1,cislo2,cislo3);
}

int bonuscv4()
{
    char pismeno1,pismeno2,pismeno3;
    printf("Zadaj 3 pismena: ");
    scanf("%c %c %c",&pismeno1,&pismeno2,&pismeno3);
    if (pismeno1 == pismeno2 && pismeno1==pismeno3){
        printf("Vsetky pismena su rovnake\n");
    }
    else if (pismeno1 == pismeno2 || pismeno1 == pismeno3 || pismeno2 == pismeno3){
        printf("Dve pismena su rovnake\n");
    }
    else{
        printf("Vsetky pismena su rozne\n");
    }
}

int bonuscv5()
{
    float vyska,hmostnost;
    printf("Zadajte vysku v centimetroch: ");
    scanf("%f",&vyska);
    printf("Zadjate hmostnost v kilogramoch: ");
    scanf("%f",&hmostnost);
    float vyska_m = vyska/100;
    float BMI = hmostnost/pow(vyska_m,2);
    printf("BMI: %.3f\n",BMI);
    if (BMI<=18.5){
        printf("Podvaha");
    }
    else if (BMI>=18.5 && BMI<=25){
        printf("Normalna vaha\n");
    }
    else if (BMI>=30){
        printf("Obezita\n");
    }
    else{
        printf("Nadvaha\n");
    }
}



void clearbuffer()
{
    while ((getchar()) != '\n');
}

void pauza()
{
    sleep(3);
    system("cls");
}



int main()
{
    int vyber= 0;

    while (true){
        printf("1) Porovnanie cisel\n");
        printf("2) Vypis druhu znaku\n");
        printf("3) Vypis ASCII a Hexa hodnot\n");
        printf("4) Prevodnik teploty\n");
        printf("5) Urcovanie najmensieho cisla\n");
        printf("6) Zoradenie cisel\n");
        printf("7) Porovnanie pismen\n");
        printf("8) BMI\n");
        printf("Zadajte cislo: ");
        scanf("%d",&vyber);
        system("cls");


        switch (vyber)
        {
            case 1:
                cv1();
                pauza();
                break;
            case 2:
                cv2();
                pauza();
                break;
            case 3:
                cv3();
                pauza();
                break;
            case 4:
                bonuscv1();
                pauza();
                break;
            case 5:
                bonuscv2();
                pauza();
                break;
            case 6:
                bonuscv3();
                pauza();
                break;
            case 7:
                bonuscv4();
                pauza();
                break;
            case 8:
                bonuscv5();
                pauza();
                break;
            //case q:
                //break;
        }
    }


    getch();
    return 0;
}
