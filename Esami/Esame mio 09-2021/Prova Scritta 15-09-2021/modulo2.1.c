#include <stdio.h>
#include <stdlib.h>

struct node
{
    int (*fun)(int a);
    int arg;
    struct node *nextPtr;
};
typedef struct node *NodePtr;

int add(int a) {
    return a+a;
}

int minus(int a) {
    return a-a;
}

int multiply(int a) {
    return a*a;
}

void valuta(struct node *l){
    while(l!=NULL){
        printf("%d ", l->fun(l->arg));
        l=l->nextPtr;
    }
}

void main(){
    int (*arrayfunzioni[])(int a)={add, minus, multiply};
    int numeronodi = 3;
    int elementi[3] = {3, 3, 3};
    NodePtr lista = malloc(sizeof(NodePtr));

    insertnode(lista, numeronodi, elementi, arrayfunzioni);
    valuta(lista);

}

void insertnode (NodePtr lista, int numeronodi, int elementi[], int (*arrayfunzioni[])(int a)){
    NodePtr temp = lista;
    for(int i=0; i<numeronodi; i++){
        lista->nextPtr = malloc(sizeof(NodePtr));
        lista->arg = elementi[i];
        lista->fun = arrayfunzioni[i];
        temp=lista;
        lista=lista->nextPtr;
    }
    temp->nextPtr=NULL;
}