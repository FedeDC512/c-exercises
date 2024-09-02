/* Scrivere un programma in C che legge un
vettore di interi di dimensione fissata e ne
stampa la somma */

#include <stdio.h>
void main (){
    int numeri[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int somma=0;
    for (int i=0; i<10; i++){
        somma += numeri[i];
    }
    printf("%d", somma);
}