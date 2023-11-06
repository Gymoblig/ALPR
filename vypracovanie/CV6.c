#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void clearbuffer()
{
    while ((getchar()) != '\n');
}

char *otoc(char *vstup) {
    int dlzka = strlen(vstup);
    for (int i = 0; i < dlzka / 2; i++) {
        char temp = vstup[i];
        vstup[i] = vstup[dlzka - i - 1];
        vstup[dlzka - i - 1] = temp;
    }
    return vstup;}

void cv1() {
    char retezec[] = "Skuska";
    printf("Povodny retezec: %s\n", retezec);

    otoc(retezec);

    printf("Otoceny retezec: %s\n", retezec);
    }

void cv2() {
    char *input = (char *)malloc(501);
    if (input == NULL) {
        printf("Nepodarilo sa alokovat pamat.\n");
        return 1;
    }

    printf("Zadaj retazec: ");
    gets(input);

    char *readPtr = input;
    char *writePtr = input;
    while (*readPtr) {
        if (*readPtr != ' ') {
            *writePtr = *readPtr;
            writePtr++;
        }
        readPtr++;
    }
    *writePtr = '\0';

    readPtr = input;
    while (*readPtr) {
        if (*readPtr >= '0' && *readPtr <= '9') {
            *readPtr = '*';
        }
        readPtr++;
    }

    char *start = input;
    char *end = start + strlen(input) - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    printf("Otoceny retazec: %s\n", input);
    free(input);
    }
void cv3() {
    FILE *vstup;
    FILE *vystup;
    char riadok[1001];
    int riadok_cislo = 1;

    vstup = fopen("vstup.txt", "r");
    vystup = fopen("vystup.txt", "w");

    if (vstup == NULL || vystup == NULL) {
        printf("Nepodarilo sa otvorit subory.\n");
        return 1;
    }

    while (fgets(riadok, sizeof(riadok), vstup) != NULL) {
        int dlzka = strlen(riadok);

        if (riadok_cislo % 2 == 1) {
            for (int i = 0; i < dlzka / 2; i++) {
                if (riadok[i] != '\n') {
                    riadok[i] = '*';
                }
            }
        } else {
            for (int i = dlzka / 2; i < dlzka; i++) {
                if (riadok[i] != '\n') {
                    riadok[i] = '-';
                }
            }
        }

        fputs(riadok, vystup);
        riadok_cislo++;
    }

    fclose(vstup);
    fclose(vystup);
}

    int main()
    {

     cv1();
     clearbuffer();
     cv2();
     clearbuffer();
     cv3();
     clearbuffer();
    }
