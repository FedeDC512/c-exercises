#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node Node;
typedef struct node *NodePtr;

void stampalistacontrario(NodePtr lista);
void crealista(NodePtr inizio, int n);
void stampalista(NodePtr lista);

void main(){
    NodePtr inizio = malloc(sizeof(Node));
    crealista(inizio, 9);
    printf("\n");
    stampalista(inizio);
    printf("\n");
    stampalistacontrario(inizio);

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

void stampalista(NodePtr lista){
    while(lista != NULL){
        printf("%d -> ", lista->data); //stampo il valore nel nodo
        lista = lista->next; //mi sposto sul nodo succssivo
    }
    printf("NULL");
}

void stampalistacontrario(NodePtr lista){
    //caso base
    if(lista->next==NULL) printf("NULL <- %d <- ", lista->data);
    //chiamata ricorsiva
    else {
        stampalistacontrario(lista->next);
        printf(" <- %d", lista->data);
    }
}