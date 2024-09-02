// Scrivere una procedura che, data una lista, restituisca la stessa lista invertita.

#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int valore;
    struct Nodo *next;
};

typedef struct Nodo nodo;
typedef nodo *NodoPtr;

void stampa(NodoPtr lista){

    while (lista != NULL){
        printf("%d ", lista->valore);
        lista = lista->next;
    }
}

void inverter(NodoPtr inizio){
    
    NodoPtr temp = inizio;
    NodoPtr count = inizio;
    NodoPtr listadef = malloc(sizeof(nodo));
    int conta = 0;
    while (count != NULL){
        count = count->next;
        conta++;
    }

    for (int i = conta; i >= 0; i--){
        
    }

}

int main(){

    NodoPtr lista = malloc(sizeof(nodo));
    NodoPtr head = lista;
    if(lista == NULL)
        return -1;

    lista->valore = 1;
    lista->next = malloc(sizeof(nodo));
    lista = lista->next;

    lista->valore = 2;
    lista->next = malloc(sizeof(nodo));
    lista = lista->next;

    lista->valore = 3;
    lista->next = malloc(sizeof(nodo));
    lista = lista->next;

    lista->valore = 4;
    lista->next = NULL;

    inverter(head);
    stampa(head);
}