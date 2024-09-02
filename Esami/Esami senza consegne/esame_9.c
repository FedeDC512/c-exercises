#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo * next;
} Nodo;
typedef struct nodo * NodoPtr;

typedef struct nodoS{
    struct nodoS * next;
    Nodo * list;
} NodoS;
typedef struct nodoS * NodoSPtr;

NodoS *soli12(Nodo * l);

void main (){

    NodoPtr lista1;
    lista1 = malloc(sizeof(NodoPtr));

    NodoPtr start1 = lista1;

    lista1->info = 1;
    lista1->next = malloc(sizeof(NodoPtr));
    lista1 = lista1->next;
    lista1->info = 2;
    lista1->next = malloc(sizeof(NodoPtr));
    lista1 = lista1->next;
    lista1->info = 3;
    lista1->next = NULL;

    NodoS * battista = soli12(start1);

    while(battista->next != NULL){
        while(battista->list->next != NULL){
            printf("%d->", battista->list->info);
            battista->list = battista->list->next;
        }
        printf("\n");
        battista = battista->next;
    }

}

NodoS *soli12(Nodo * l){
    NodoSPtr listadef = malloc(sizeof(NodoSPtr));
    NodoSPtr start = listadef;
    while(l != NULL){
        listadef->list = l;
        listadef->list->next = NULL;
        if (l->next != NULL){
            listadef->next = malloc(sizeof(NodoSPtr));
            listadef = listadef->next;
            listadef->list = l;
            listadef->list = listadef->list->next;
            listadef->list->next = NULL;
            listadef->next = malloc(sizeof(NodoSPtr));
            listadef = listadef->next;
        }
        l = l->next;
    }
    listadef->next = NULL;
    return start;
}