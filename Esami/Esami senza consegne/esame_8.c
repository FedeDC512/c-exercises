#include <stdio.h>
#include <stdlib.h>

typedef struct arco {
    size_t nodo;
    struct arco *arcoPtr;
} Arco;

typedef struct arco * ArcoPtr;

typedef struct nodo {
    size_t nodo;
    struct arco *arcoPtr;
    struct nodo *nodoPtr;
} Nodo;

typedef struct nodo * NodoPtr;

void main (){

    int valore;
    int numeri[] = malloc(sizeof(int));
    int contanumeri = 0;
    ArcoPtr listabella = malloc(sizeof(ArcoPtr));
    ArcoPtr iniziolista = listabella;

    NodoPtr dito1 = malloc(sizeof(NodoPtr));
    NodoPtr dito2 = malloc(sizeof(NodoPtr));
    NodoPtr dito3 = malloc(sizeof(NodoPtr));
    NodoPtr dito4 = malloc(sizeof(NodoPtr));

    for (int i = 1; i<5; i++){
        printf("Inserisci la sequenza %d:\nInserisci -1 per terminare la riga", i);

        scanf("%d", &valore);
        numeri[contanumeri] = valore;
        dito1->nodo = valore;
        dito1->arcoPtr = malloc(sizeof(Arco));
        dito1->nodoPtr = malloc(sizeof(Nodo));
        dito1 = dito1->nodo;
        contanumeri++;

        while (valore >= 0){
            numeri[contanumeri] = valore;
            dito1->nodo = valore;
            dito1->nodoPtr = malloc(sizeof(Nodo));
            dito1 = dito1->nodoPtr;
            contanumeri++;
        }
        dito1->nodoPtr = NULL;
    }
}