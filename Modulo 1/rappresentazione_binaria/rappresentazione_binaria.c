/* lez18es2
Dato un numero intero positivo decimale N, visualizzare la sua rappresentazione binaria. */

#include <stdio.h>
void main()
{
    int n, bin, c, r;
    c=1;
    bin=0;
    printf("Inserisci il valore da convertire: ");
    scanf("%d",&n);
    while (n!=0){
    r=n%2;
    c=c*10;
    bin=bin+(c*r)/10;
    n=n>>1;
    }
    printf("Il valore binario e' %d", bin);
}