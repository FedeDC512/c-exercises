/* lez16es10
Scrivere un programma che prende in input un numero di 4 cifre e 
lo scompone in unità, decine, centinaia, migliaia, e visualizza 
la scomposizione separata da spazi. Ad esempio, dato 7543, 
in output deve esser stampato ‘7M, 5C, 4D, 3C’. */

#include <stdio.h>
void main()
{
    int a;
    printf("Inserisci il numero da scomporre:\n");
    scanf("%d",&a);
    printf("%dM ", a/1000);
    printf("%dC ", (a/100)%10);
    printf("%dD ", (a/10)%10);
    printf("%dU", a%10);
}