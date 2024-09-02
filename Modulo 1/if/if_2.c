/* Scrivi un algoritmo che inseriti due numeri interi da tastiera esegua:
A) La loro somma se uno dei due è pari
B) Il loro prodotto se tutti e due sono pari
C) La loro divisione se nessuno dei due è pari */

#include <stdio.h>

int main()
{
    int a, b;
    printf("Inserisci il primo numero: ");
    scanf("%d", &a);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &b);
    if (a%2==0 && b%2==0) {
        printf("Entrambi i numeri sono pari, il loro prodotto e' %d", a*b);
    }
    else if (a%2==0 || b%2==0) {
        printf("Uno dei numeri e' pari, la loro somma e' %d", a+b);
    }
    else {
        printf("Entrambi i numeri sono dispari, la loro divisione e' %f", (float)a/b);
    }
    return 0;
}
