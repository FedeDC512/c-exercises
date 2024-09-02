#include <stdio.h>

int main()
{
    int a, b;
    printf("Inserisci il primo numero ");
    scanf("%d", &a);
    printf("Inserisci il secondo numero ");
    scanf("%d", &b);
    if (a==b) {
        printf("I numeri sono uguali, la somma e' %d", a*2);
        }
    else if (a>=b) {
        printf("Il numero piu' grande e' %d", a);
        }
    else {
        printf("Il numero piu' grande e' %d", b);
        }
    
    return 0;
}
