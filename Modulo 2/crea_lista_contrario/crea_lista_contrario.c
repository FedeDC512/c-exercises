#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node *NodePtr;

void insertnode (NodePtr lista, int n);

NodePtr creacontry(NodePtr lista);

void main (){
    NodePtr lista = malloc(sizeof(NodePtr));
    NodePtr stampa = lista;
    int numeronodi = 10;
    insertnode(lista, numeronodi);

    while(stampa != NULL){
        printf("%d ", stampa->data);
        stampa=stampa->next;
    }
    printf("\n");

    NodePtr new = creacontry(lista);

    while(new != NULL){
        printf("%d ", new->data);
        new=new->next;
    }

}

void insertnode (NodePtr lista, int n){
    NodePtr temp = lista;
    for(int i = 0; i<n; i++){
        lista->data = i+1;
        temp = lista;
        lista->next = malloc(sizeof(NodePtr));
        lista=lista->next;
    }
    temp->next = NULL;

}

NodePtr creacontry(NodePtr lista){
    //passo ricorsivo
    if (lista->next != NULL){
        NodePtr temp = creacontry(lista->next);
        (lista->next)->next = lista;
        return temp;
    }
    //caso base
    else return lista;
}
