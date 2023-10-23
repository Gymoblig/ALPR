#include <stdio.h>
void cv1()
{
    int N = 7;
    for (int i=1;i<=N;i++){
        for (int j =1;j<=i;j++){
            if ((j%2)==0){
                printf("A");}
            else printf("B");
            }
            printf("\n");
    }
}

void cv2()
{
    int N =7;
    for (int i =1;i<=N;i=i+2){
        for (int j =1;j<=N;j++){
            if (j>3){
                printf("A");
            }
            else printf("B");
        }
        printf("\n");
    }
}

void cv3()
{
    int i,j;
    int N=7;
    for (i=1;i<=N;i++){
        for (j=1;j<=i;j++){
            if ((j%3)==0)printf("A");
            else printf("B");
        }
        if ((i%2)==1) printf("\n");
    }
}
int main()
{
    cv1();
    printf("\n");
    cv2();
    printf("\n");
    cv3();
    return 0;
}
