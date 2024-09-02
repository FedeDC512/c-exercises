#include <stdio.h>
#include <stdlib.h>

int fattorialer(int n);
int fibonaccir(int n);

void main (){

    int n = 0;
    printf("Numero menu: ");
    scanf("%d", &n);
    switch (n){
        case 0 : printf("Non hai inserito nessun numero!");
        break;
        case 1 : //calcolo fattoriale ricorsivo
            printf("Inserisci il numero: ");
            int fattoriale = 0;
            scanf("%d", &fattoriale);
            printf("Il suo fattoriale e' %d", fattorialer(fattoriale));
        break;
        case 2 : //fibonacci
            printf("Inserisci il numero: ");
            int fibonacci = 0;
            scanf("%d", &fibonacci);
            printf("Il numero in posizione %d nella serie di Fibonacci e' %d", fibonacci, fibonaccir(fibonacci));
            break;
    }
}

int fattorialer(int n){
    //caso base
    if (n==1) return 1;
    //passo ricorsivo
    else return n*(fattorialer(n-1));
}

int fibonaccir(int n){
    //caso base
    if (n==0 || n==1) return 0;
    else if (n==2) return 1;
    //passo ricorsivo
    else return (fibonaccir(n-1))+(fibonaccir(n-2));
}