/* (Calcolatore che usa puntatori a funzioni) Usando le tecniche che avete imparato nella
Figura 7.28, realizzate un programma guidato da menu testuale che permetta all'utente di
scegliere se sommare, sottrarre, moltiplicare o dividere due numeri. Il programma deve quin-
di leggere due valori double forniti dall'utente, effettuare il calcolo appropriato e stampare
il risultato. Usate un array di puntatori a funzioni in cui ogni puntatore rappresenta una
funzione che restituisce void e riceve due parametri double. Le funzioni corrispondenti
devono ognuna stampare un messaggio che indica quale calcolo è stato eseguito, i valori dei
parametri e il risultato del calcolo. */

#include <stdio.h>

void somma();
void sottrazione();
void moltiplicazione();
void divisione();

void main()
{
    void (*f[4])(int, int, int)={somma, sottrazione, moltiplicazione, divisione};

    int a,b;

    printf("1 Somma\n2 Sottrazione\n3 Moltiplicazione\n4 Divisione\nQuale operazione vuoi eseguire? ");
    int choice;
    scanf("%d", &choice);
    choice-=1;

    printf("Inserisci il primo numero: ");
    scanf("%d", &a);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &b);

    while (choice >=0 && choice <=3){
        (*f[choice])(choice, a, b);

        printf("1 Somma\n2 Sottrazione\n3 Moltiplicazione\n4 Divisione\nQuale operazione vuoi eseguire? ");
        scanf("%d", &choice);
        choice-=1;

        printf("Inserisci il primo numero: ");
        scanf("%d", &a);
        printf("Inserisci il secondo numero: ");
        scanf("%d", &b);
    }

}

void somma (int f, int a, int b){
    printf("La somma di %d e %d e' %d\n\n", a, b, a+b);
}

void sottrazione (int f, int a, int b){
    printf("La sottrazione di %d e %d e' %d\n\n", a, b, a-b);
}

void moltiplicazione (int f, int a, int b){
    printf("La moltiplicazione di %d e %d e' %d\n\n", a, b, a*b);
}

void divisione (int f, int a, int b){
    printf("La divisione di %d e %d e' %.2f\n\n", a, b, (float)a/b);
}