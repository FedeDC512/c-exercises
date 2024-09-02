/* lez18es6
Dato un numero N calcolare e visualizzare tutte le coppie di numeri che danno per prodotto il numero stesso. */

#include <stdio.h>
#include <math.h>
void main()
{
    int n, s1=1, r=1;
    printf("Inserisci il valore: ");
    scanf("%d",&n);
    while (r<=sqrt(n)){
    if (n%r==0) printf("%d e %d\n", r, n/r);
    r++;
    }
}