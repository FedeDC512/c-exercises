/* lez15es2
Dato un intero positivo minore di 100 stampare: A se il numero è >= 90
B se il numero è >= 80 e < 90
C se il numero è >= 70 e < 80
D se il numero è >= 60 e < 70 F per tutti gli altri casi. */

#include <stdio.h>
void main()
{
    int a1;
    scanf("%d",&a1);
    if (a1>=90){
        printf("A");
    }
    else if (a1>=80){
        printf("B");
        }
    else if (a1>=70){
        printf("C");
    }
    else if (a1>=60){
        printf("D");
    }
    else printf("F");
}