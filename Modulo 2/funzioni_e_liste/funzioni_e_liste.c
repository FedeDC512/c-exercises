#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NodePtr;
void scrivinumeri(int numeri[]);
void scrivilista(NodePtr lista);

void main (){
    //mi passo a una funzione un array, lo modifico e vedo che succede
    int array[10] = {0};
    scrivinumeri(array);
    for(int i=0; i<10; i++) printf("%d ", array[i]);
    printf("\n");


    //mi passo a una funzione una lista
    NodePtr lista1 = malloc(sizeof(NodePtr));
    NodePtr inizio = lista1;
    int numeronodi = 10;

    scrivilista(lista1);

    NodePtr stampa = inizio;
    while (stampa!=NULL){
        printf("%d ", stampa->data);
        stampa=stampa->next;
    }

}

void scrivinumeri(int numeri[]){
    for(int i = 0; i<10; i++) numeri[i] = i+1;
}

void scrivilista (NodePtr lista){

    for(int i=0; i<10; i++){
        lista->data = i+1;
        lista->next = malloc(sizeof(NodePtr));
        if (i==9) lista->next=NULL;
        else lista = lista->next;
    }
}