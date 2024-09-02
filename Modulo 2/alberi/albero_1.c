#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
    int numero;
    struct node *destra;
    struct node *sinistra;
};

typedef struct node *NodePtr;
void insertnode (NodePtr radice, int n);
void inorder (NodePtr radice);

void main(){

    srand(time(NULL));

    NodePtr alberello = malloc(sizeof(NodePtr));

    NodePtr inizio = alberello;
    int numeronodi = 10;
    int numerelli[numeronodi];

    for(int i = 0; i<numeronodi; i++){
        numerelli[i] = 1 + (rand() % 99);
        printf("%d ", numerelli[i]);
    }
    printf("\n");

    for( int i = 0 ; i<numeronodi ; i++){
        if(i==0){
            alberello->numero = numerelli[i];
            alberello->destra = NULL;
            alberello->sinistra = NULL;
        }
        else insertnode(alberello, numerelli[i]);
    }
    inorder(alberello);
}

void insertnode (NodePtr radice, int n){
    if(radice->numero==0){
        radice->numero = n;
        radice->destra = NULL;
        radice->sinistra = NULL;
    }
    else if(n < radice->numero){
        radice->sinistra = malloc(sizeof(NodePtr));
        radice=radice->sinistra;
        radice->numero=0;
        insertnode (radice, n);
    }
    else if(n > radice->numero){
        radice->destra = malloc(sizeof(NodePtr));
        radice=radice->destra;
        radice->numero=0;
        insertnode (radice, n);
    }
    else printf("Sono presenti due numeri uguali, il numero %d sara' inserito solo una volta\n", n);
}

void inorder (NodePtr radice){
    if(radice != NULL){
        inorder(radice->sinistra);
        printf("%d ", radice->numero);
        inorder(radice->destra);
    }
}