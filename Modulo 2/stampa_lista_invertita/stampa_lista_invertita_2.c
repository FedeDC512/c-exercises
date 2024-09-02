#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node *NodePtr;

void insertnode (NodePtr lista);

void stampacontry(NodePtr lista);

void main (){
    NodePtr lista = malloc(sizeof(NodePtr));
    NodePtr stampa = lista;
    insertnode(lista);

    for(int i =0; i<5; i++){
        printf("%d", stampa->data);
        stampa=stampa->next;
    }
    printf("\n");

    stampacontry(lista);

}

void insertnode (NodePtr lista){
    NodePtr temp = lista;
    for(int i = 0; i<5; i++){
        lista->data = i+1;
        temp = lista;
        lista->next = malloc(sizeof(NodePtr));
        lista=lista->next;
    }
    temp->next = NULL;

}

void stampacontry(NodePtr lista){
    //caso base
    if(lista->next == NULL) printf("%d", lista->data);
    //passo ricorsivo
    else {
        stampacontry(lista->next);
        printf("%d", lista->data);
    }
}

// Finito e funziona!