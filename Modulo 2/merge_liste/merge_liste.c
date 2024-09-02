/* Scrivete un programma in grado di fondere due liste ordinate di interi in una singola lista
ordinata di interi. La funzione merge deve ricevere i puntatori al primo nodo di ognuna
delle liste da fondere e restituire un puntatore al primo nodo della lista fusa. */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};

typedef struct node * NodePtr;

NodePtr merge ();

void main() {

    NodePtr lista1;
    lista1 = malloc(sizeof(NodePtr));
    NodePtr lista2;
    lista2 = malloc(sizeof(NodePtr));

    NodePtr start1 = lista1;
    NodePtr start2 = lista2;

    lista1->data = 11;
    lista1->next = malloc(sizeof(NodePtr));
    lista1 = lista1->next;
    lista1->data = 12;
    lista1->next = malloc(sizeof(NodePtr));
    lista1 = lista1->next;
    lista1->data = 13;
    lista1->next = NULL;

    lista2->data = 8;
    lista2->next = malloc(sizeof(NodePtr));
    lista2 = lista2->next;
    lista2->data = 9;
    lista2->next = malloc(sizeof(NodePtr));
    lista2 = lista2->next;
    lista2->data = 10;
    lista2->next = NULL;

    NodePtr listadef = merge (start1, start2);

    while (listadef != NULL){
        printf("%d ", listadef->data);
        listadef=listadef->next;
    }

}

NodePtr merge (NodePtr lista1, NodePtr lista2){

    NodePtr start1 = lista1;
    NodePtr start2 = lista2;
    if (lista1->data < lista2->data){
        while (lista1->next != NULL){
            lista1=lista1->next;
        }
        lista1->next=lista2;
        return start1;
    }
    else if (lista1->data > lista2->data){
        while (lista2->next != NULL){
            lista2=lista2->next;
        }
        lista2->next=lista1;
        return start2;
    }
    else printf("Le due liste hanno lo stesso numero iniziale");
    return NULL;
}