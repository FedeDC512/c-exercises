#include <stdio.h>
#include <stdlib.h>

typedef struct arco{
    int nodo;
    struct arco *arcoPtr;
} Arco;
//arco singolo
typedef struct arco *ArcoPtr;

typedef struct nodo{
    int nodo;
    struct arco *arcoPtr;
    struct nodo *nodoptr;
} Nodo;
//nodo doppio
typedef struct nodo *NodoPtr;

void main (){

    NodoPtr esercizio = malloc(sizeof(NodoPtr));
    NodoPtr inizio = esercizio;

    for(int j=0; j<4; j++){
        printf("Inserisci il primo nodo: ");
        scanf("%d", esercizio->nodo);
        ArcoPtr braccio, temp;
        esercizio->arcoPtr = braccio;
        for(int i=0; i<2; i++){
            printf("Inserisci l'arco: ");
            scanf("%d", braccio->nodo);
            braccio->arcoPtr = malloc(sizeof(ArcoPtr));
            temp = braccio;
            braccio = braccio->arcoPtr;
        }
        temp->arcoPtr = NULL;
        esercizio->nodoptr = malloc(sizeof(NodoPtr));
        esercizio = esercizio->nodoptr;

    }

    //while(inizio!=NULL){
    //    printf("%d", inizio->nodo);
    //    inizio=inizio->arcoPtr;
    //}

}

//non finito