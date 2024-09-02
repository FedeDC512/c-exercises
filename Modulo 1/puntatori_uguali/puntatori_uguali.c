/* Dichiarare due variabili intere, e due puntatori coerenti. Puntare a tali variabili, quindi
verificare che i due indirizzi sono differenti fra loro, mediante un semplice confronto fra i puntatori. */

#include <stdio.h>
void main (){
    int a=0, b=0;
    int *aptr=&a, *bptr=&a;
    printf("%d %d", *aptr, *bptr);
    printf ("\n");
    printf("%d %d", aptr, bptr);
    printf ("\n");
    if (aptr == bptr) printf ("I due indirizzi sono uguali");
    else printf ("I due indirizzi sono diversi");

}