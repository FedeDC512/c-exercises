/* lez18es7 
Scrivere un programma che, dati in ingresso due numeri positivi x e y visualizza in ordine decrescente la sequenza di numeri interi
compresi tra x e y che sono divisibili per il minore tra x e y. Ad esempio, se x = 5 e y = 38, la sequenza è 35,30,25,20,15,10,5. */

#include <stdio.h>
#include <math.h>
void main()
{
   int x, y, z;
    printf("Inserisci i valori: ");
    scanf("%d %d",&x, &y); 
    if (y<x){
        x = x+y;
        y = x-y;
        x = x-y;
    }
    while (y!=1){
        if (y%x==0) printf("%d\n", y);
        y--;
    }
}