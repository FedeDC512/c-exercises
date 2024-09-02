// Utilizza un ciclo for per realizzare un algoritmo che esegua la somma e la media n numeri inseriti da tastiera con n acquisito a sua volta da tastiera

#include <stdio.h>

int main()
{
    int a=0, c=0, b=0;
    float media=0;
    printf("Inserisci quanti numeri hai intenzione di scrivere ");
    scanf("%d", &a);
    for (int i=0; i<a; i++) {
    printf("Inserisci il %d numero e premi invio: ", i+1);
    scanf("%d", &c);
    b=b+c;
    }
    printf("La somma dei numeri e' %d\n", b);
    media=(float)b/a;
    printf("La media dei numeri e' %f", media);
    
    return 0;
}