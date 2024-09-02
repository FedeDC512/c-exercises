/* lez18es5
Dato un numero positivo N calcolare e visualizzare tutte le coppie di numeri positivi che danno per somma il numero stesso. */

#include <stdio.h>
void main()
{
    int n, s1, s2;
    printf("Inserisci il valore: ");
    scanf("%d",&n);
    s1=0, s2=n;
    while (s1!=(n+2)/2){
    if (s1+s2==n) printf("%d e %d\n", s1, s2);
    s1=s1+1, s2=s2-1;
    }
}