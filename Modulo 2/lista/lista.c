#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node Node;
typedef struct node *NodePtr;

void stampalista(NodePtr lista);
void crealista(NodePtr inizio, int n);
void aggiunginodo(NodePtr inizio, int n);

void main(){

    NodePtr inizio = malloc(sizeof(Node)); //mi faccio sempre la prima allocazione

    crealista(inizio, 9); //creo la lista mettendo i numeri fino a n passato
    stampalista(inizio);

    aggiunginodo(inizio, 10); //aggiungo alla fine della lista il valore n passato

    printf("\n");
    stampalista(inizio);
}

void stampalista(NodePtr lista){
    while(lista != NULL){
        printf("%d -> ", lista->data); //stampo il valore nel nodo
        lista = lista->next; //mi sposto sul nodo succssivo
    }
    printf("NULL");
}

void crealista(NodePtr inizio, int n){
    NodePtr temp = inizio; //mi creo un temp che scorre la lista
    NodePtr fine = temp; //mi creo la fine che assegnerà la fine della lista
    for(int i = 1 ; i<=n ; i++){
        temp->data = i; //assegnazione
        temp->next = malloc(sizeof(Node)); //allocazione
        fine = temp; //mi segno la fine, che sta sempre un nodo indietro
        temp = temp->next; //spostamento
    }
    free(temp); //libero lo spazio a cui punta il temp
    fine->next = NULL; //finisco la lista
}

void aggiunginodo(NodePtr inizio, int n){
    NodePtr fine = inizio; //mi creo un nuovo puntatore per trovare la fine

    while(fine->next != NULL) fine = fine->next; //trovo la fine facendolo scorrere fino a che il next è nullo

    NodePtr aggiungi = fine; //creo nuovo puntatore aggiungi
    aggiungi->next = malloc(sizeof(Node)); //allocazione 
    aggiungi = aggiungi->next; //spostamento
    aggiungi->data = n; //assegnazione
    aggiungi->next = NULL;
}