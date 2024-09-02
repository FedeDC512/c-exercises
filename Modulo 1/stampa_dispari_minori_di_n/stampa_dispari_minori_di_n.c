/* lez18es3
Dato N un numero intero positivo, generare e visualizzare in ordine crescente i numeri dispari minori o uguali a N. */

#include <stdio.h>
void main()
{
    int n, c;
    c=0;
    printf("Inserisci il valore: ");
    scanf("%d",&n);
    while (c!=n+1){
    if (c%2==1) printf("%d ", c);
    c=c+1;
    }
}