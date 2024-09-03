#include <stdio.h>
#include <stdlib.h>

typedef struct arco{
    int data;
    struct arco *next;
} Arco;
typedef struct arco *ArcoPtr;

typedef struct nodo{
    int data;
    struct arco *right;
    struct nodo *down;
} Nodo;
typedef struct nodo *NodoPtr;

void main(){
    NodoPtr a = malloc(sizeof(NodoPtr));
    NodoPtr temp2;
    ArcoPtr b1 = malloc(sizeof(ArcoPtr));
    ArcoPtr b2 = malloc(sizeof(ArcoPtr));
    ArcoPtr b3 = malloc(sizeof(ArcoPtr));
    ArcoPtr temp;
    ArcoPtr b[3] ={b1, b2, b3};    
    int g = 0;
    int i = 1;
    int j = 1;
    for(i; i!=0; ){
        printf("Inserisci nodo? 1/0: ");
        scanf("%d", &i);
        if(i==0) break;
        printf("Metti il numero nel nodo: ");
        scanf("%d", &(a->data));
        for(j; j!=0; ){
            printf("Inserisci arco? 1/0: ");
            scanf("%d", &j);
            if(j==0) break;
            a->right=b[i];
            printf("Metti il numero nell'arco: ");
            scanf("%d", &(b[i]->data));
            temp=b[i];
            b[i]=b[i]->next;
        }
        b[i]->next=NULL;
        temp2=a;
        a->down=malloc(sizeof(NodoPtr));
        a=a->down;
    }
    temp2->down = NULL;
}