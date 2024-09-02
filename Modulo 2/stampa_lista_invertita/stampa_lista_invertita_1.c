/* Scrivete una funzione printListBackward che stampi in maniera ricorsiva gli elementi in una lista in ordine inverso. Usate
la vostra funzione in un programma di test che crea una lista ordinata di interi e stampa la lista in ordine inverso. */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void printListBackward ();

void main() {

    struct node numeri;
    struct node * ptr;
    ptr = &numeri;

    struct node* inizio;
    inizio = &numeri;

    struct node* bw;
    bw = &numeri;

    ptr->next = &numeri;
    ptr-> data = 1;
    ptr->next = malloc(sizeof(struct node));
    ptr=ptr->next;
    ptr-> data = 2;
    ptr->next = malloc(sizeof(struct node));
    ptr=ptr->next;
    ptr-> data = 3;
    ptr->next = NULL;

    for(int i=0; i<3; i++){
        printf("%d", inizio->data);
        inizio=inizio->next;
    }
    printf("\n");

    printListBackward (bw);

}

void printListBackward (struct node * ptr){

    if(ptr->next == NULL) {
        printf("%d", ptr->data);
        return;
    }
    printListBackward (ptr->next);
    printf("%d", ptr->data);
}