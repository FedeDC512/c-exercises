// Scrivi un programma che riceva in imput 10 numeri e stampi come output i 10 numeri inseriti in ordine inverso

#include <stdio.h>

int main()
{
    int a [10];
    for (int i=0; i<10; i++) {
        printf("Inserisci il %d valore ", i+1);
        scanf("%d", &a[i]);
    }
    for (int i=9; i>=0; i--) {
    printf("\nIl valore alla posizione %d e' ", i+1);
    printf("%d", a[i]);
    }
    return 0;
}
