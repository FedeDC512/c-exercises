#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int data;
    struct node *right;
    struct node *left;
};

typedef struct node *NodePtr;

void insertnode (NodePtr *radice, int numero);
void inorder (NodePtr radice);

void main (){
    int numerelli[10];
    srand(time(NULL));
    for(int j = 0 ; j<10 ; j++){
        numerelli[j] = 1+rand()%100;
        printf("%d ", numerelli[j]);
    }
    printf("\n");
    NodePtr alberello = malloc(sizeof(NodePtr));
    alberello->data = 50;
    alberello->right = NULL;
    alberello->left = NULL;

    for( int i = 0 ; i<10 ; i++){
        insertnode (&alberello, numerelli[i]);
    }

    inorder (alberello);
}

void insertnode (NodePtr *radice, int numero){
    if(*radice==NULL){
        (*radice) = malloc(sizeof(NodePtr));
        (*radice)->data = numero;
        (*radice)->right = NULL;
        (*radice)->left = NULL;
    }
    else if(numero < (*radice)->data){
        insertnode (&((*radice)->left), numero);
    }
    else if(numero > (*radice)->data){
        insertnode (&((*radice)->right), numero);
    }
    else printf("Sono presenti due numeri uguali, il numero %d sara' inserito solo una volta\n", numero);
}

void inorder (NodePtr radice){
    if(radice != NULL){
        inorder(radice->left);
        printf("%d ", radice->data);
        inorder(radice->right);
    }
}