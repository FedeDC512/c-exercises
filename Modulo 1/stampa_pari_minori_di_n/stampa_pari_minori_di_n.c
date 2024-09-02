/* lez18es4
Dato N un numero intero positivo, generare e visualizzare in ordine crescente i numeri pari minori o uguali a N. */

#include <stdio.h>
void main()
{
    int n, c;
    c=0;
    printf("Inserisci il valore: ");
    scanf("%d",&n);
    while (c!=n+1){
    if (c%2==0) printf("%d ", c);
    c=c+1;
    }
}