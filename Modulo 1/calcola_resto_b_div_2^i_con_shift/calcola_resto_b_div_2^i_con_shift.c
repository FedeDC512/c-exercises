/* lez15es7
Dato un intero b a 32 bit, e un altro intero i positivo e minore o uguale a 31, 
implementare in C un programma che calcola quoziente e resto della divisione intera b:2^i. 
Risolvere il problema SENZA fare uso delle operazioni prodotto, elevazione a potenza e divisione 
(suggerimento: riflettere sull’effetto degli shift su un intero). */

#include <stdio.h>
void main()
{
    long b, i;
    printf("Inserisci b: ");
    scanf("%d",&b);
    printf("Inserisci i: ");
    scanf("%d",&i);
    if (i<=31){
        printf("La soluzione e' %d", b>>i);
    }
    else printf("NON FINITO"); 
}
