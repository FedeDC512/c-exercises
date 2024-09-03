#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int info;
    struct nodo *next;
} Nodo;

typedef struct nodoS{
    struct nodoS *next;
    Nodo *list;
} NodoS;

NodoS *soli12(Nodo * l){
    NodoS * risultato = malloc(sizeof(NodoS *));
    //Nodo * tmpptr = malloc(sizeof(NodoS *));
    risultato->list = malloc(sizeof(Nodo *));
    risultato->list = l;
    //tmpptr = risultato->list;
    if(risultato->list->next!=NULL){
        risultato->list->next->next=NULL;
    }
    risultato->next = soli12(l->next);
    return risultato;
}

void main(){
    Nodo * nodo1 = malloc(sizeof(Nodo));
    nodo1->info = 1;
    Nodo * nodo2 = malloc(sizeof(Nodo));
    nodo2->info = 2;
    Nodo * nodo3 = malloc(sizeof(Nodo));
    nodo3->info = 3;
    nodo1->next = nodo2;
    nodo2->next = nodo3;
    nodo3->next = NULL;
    NodoS * lista = soli12(nodo1);
    /*
    NodoS * lista = malloc(sizeof(NodoS));
    lista->list = nodo1;
    lista->next = nodo2;
    lista->next->next = NULL;
    */   
    while(lista->list != NULL){
        while(lista->list->info != NULL){
            printf("%d", lista->list->info);
            lista->list = lista->list->next;
        }
        lista = lista->next;
    }
    
}