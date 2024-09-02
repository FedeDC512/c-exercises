/* Realizzate un programma guidato da menu testuale che permetta all’utente di scegliere se
calcolare la circonferenza di un cerchio, l’area di un cerchio o il volume di una sfera. Il
programma deve poi leggere il valore del raggio fornito dall’utente, eseguire il calcolo
appropriato e stampare il risultato. Usate un array di puntatori a funzioni in cui ogni
puntatore rappresenta una funzione che restituisce void e riceve un parametro double. Le
funzioni corrispondenti devono stampare ognuna un messaggio che indica quale calcolo è
stato eseguito, il valore del raggio e il risultato del calcolo. */

#include <stdio.h>

void funz1(int a);
void funz2(int b);
void funz3(int c);

void main()
{
    void (*f[3])(int)={funz1, funz2, funz3};

    printf("Inserisci 1 per calcolare la circonferenza di un cerchio,\n2 per l'area di un cerchio\no 3 il volume di una sfera\n");
    int choice;
    scanf("%d", &choice);
    choice -= 1;

    while (choice >= 0 && choice <= 2) {
        (*f[choice])(choice);

        printf("Inserisci 1 per calcolare la circonferenza di un cerchio,\n2 per l'area di un cerchio\no 3 il volume di una sfera\n");
        scanf("%d", &choice);
        choice -= 1;
    }
    printf("Fine");

}

void funz1(int a){
    printf("Inserisci il raggio del cerchio: ");
    float r;
    scanf("%f", &r);
    printf("La circonferenza del cerchio di raggio %.2f e' %.2f\n", r, 2*3.14*r);

    printf("Funzione conclusa\n");
}

void funz2(int b){
    printf("Inserisci il raggio del cerchio: ");
    float r;
    scanf("%f", &r);
    printf("L'area del cerchio di raggio %.2f e' %.2f\n", r, 3.14*r*r);

    printf("Funzione conclusa\n");
}

void funz3(int c){
    printf("Inserisci il raggio della sfera: ");
    float r;
    scanf("%f", &r);
    printf("Il volume della sfera di raggio %.2f e' %.2f\n", r, 4/3*3.14*r*r*r);

    printf("Funzione conclusa\n");
}