/* lez15es4
Implementare in C un programma che effettua lo scambio senza utilizzare una variabile 
di comodo (versione SOMMA e XOR). Lo xor in C si esegue tramite l’operatore "^". */

#include <stdio.h>
void main()
{
    int a, b;
    scanf("%d %d",&a, &b);
    a = a^b;
    b = a^b;
    a = a^b;
    printf("a: %d\nb: %d\n", a, b);
    a = a+b;
    b = a-b;
    a = a-b;
    printf("a: %d\nb: %d", a, b);
}
