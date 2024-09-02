#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *next;
};

typedef struct node Node;
typedef struct node * NodePtr;

NodePtr mettiparola (char parola[]);
NodePtr nodoppie (NodePtr lista);

void main(){

    char parola[] = {'c', 'i', 'a', 'i', '\0'};

    NodePtr lista = mettiparola(parola);

    NodePtr lista2 = nodoppie(lista);

    for(int i=0; i<4; i++){
        printf("%c", lista2->data);
        lista2=lista2->next;
    }
    printf("\n");

}

NodePtr mettiparola (char parola[]){

    int i = 0;
    NodePtr lp = malloc(sizeof(NodePtr));
    NodePtr out = lp;
    while (parola[i] != '\0'){
        lp->data = parola[i];
        lp->next = malloc(sizeof(NodePtr));
        lp = lp->next;
        i++;
    }
    lp->next=NULL;

    return out;
}

NodePtr nodoppie (NodePtr lista){
    NodePtr listadef = malloc(sizeof(NodePtr));
    NodePtr out = listadef;

    NodePtr pointer1 = lista;
    NodePtr pointer2 = listadef;

    pointer2->data = pointer1->data;
    pointer2->next = NULL;
    pointer1 = pointer1->next;

    for ( ; pointer1->next != NULL ; ){
        for ( ; pointer1->next != NULL ; ){
            if (pointer1->data != pointer2->data){
                pointer2->next = malloc(sizeof(NodePtr));
                pointer2 = pointer2->next;
                pointer2->data = pointer1->data;

                pointer1 = pointer1->next;
            }
            else pointer1 = pointer1->next;
        
        }
        pointer2 = lista;
    }
    pointer2->next = NULL;

    return out;
}



//non va