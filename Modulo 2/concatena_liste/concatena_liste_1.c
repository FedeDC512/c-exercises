/* Scrivete un programma che concateni due liste collegate di caratteri. Il programma deve includere la funzione 
concatenate che riceve come argomenti i puntatori a entrambe le liste e concatena la seconda lista alla prima. */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node * NodePtr;

void concatenate ();

void main() {

    NodePtr ptr;
    NodePtr ptr2;
    ptr = malloc(sizeof(struct node));
    ptr2 = malloc(sizeof(struct node));

    NodePtr inizio;
    inizio = ptr;

    NodePtr fun1;
    fun1 = ptr;

    NodePtr inizio2;
    inizio2 = ptr2;

    NodePtr fun2;
    fun2 = ptr2;

    //crea e stampa lista 1
    ptr->next = ptr;
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

    //crea e stampa lista2
    ptr2->next = ptr2;
    ptr2-> data = 4;
    ptr2->next = malloc(sizeof(struct node));
    ptr2=ptr2->next;
    ptr2-> data = 5;
    ptr2->next = malloc(sizeof(struct node));
    ptr2=ptr2->next;
    ptr2-> data = 6;
    ptr2->next = NULL;

    for(int i=0; i<3; i++){
        printf("%d", inizio2->data);
        inizio2=inizio2->next;
    }
    printf("\n");

    concatenate (fun1, fun2);

}

void concatenate (NodePtr ptr1, NodePtr ptr2){
    NodePtr ptrdef;
    ptrdef = ptr1;
    while (ptr1->next != NULL){
        ptr1=ptr1->next;
    }

    ptr1->next=ptr2;

    for(int i=0; i<6; i++){
        printf("%d", ptrdef->data);
        ptrdef=ptrdef->next;
    }
    printf("\n");

    return;
}