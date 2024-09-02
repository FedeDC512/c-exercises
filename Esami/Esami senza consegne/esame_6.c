#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *nextPtr;
};

typedef struct node ListNode;
typedef struct node *ListNodePtr;

ListNodePtr v(ListNodePtr l1, ListNodePtr l2) {
    ListNode result;
    ListNodePtr c = &result;
    while((l1!=NULL)&&(l2!=NULL)){
        if((l1->data)<=(l2->data)){
            c-> nextPtr = l1;
            c = l1;
            l1 = l1->nextPtr;
        } else {
            c-> nextPtr = l2;
            c = l2;
            l2 = l2->nextPtr;
        }
    }
    c->nextPtr = (l1 == NULL) ? l2 : l1;
    return result.nextPtr;
}

void stampalista(ListNodePtr lista){
    while(lista != NULL){
        printf("%d -> ", lista->data); //stampo il valore nel nodo
        lista = lista->nextPtr; //mi sposto sul nodo succssivo
    }
    printf("NULL");
}

void main (){

    ListNodePtr s1 = malloc(sizeof(ListNode));
    ListNodePtr inizio = s1;
    for(int i=0; i<4 ; i++){
        s1->data = i;
        s1->nextPtr = malloc(sizeof(ListNode));
        if (i != 3) s1 = s1->nextPtr;
    }
    s1->nextPtr = NULL;
    s1 = inizio;
    printf("/n");

    ListNodePtr s2 = malloc(sizeof(ListNode));
    inizio = s2;  
    for(int i=0; i<5 ; i++){
        s2->data = i;
        s2->nextPtr = malloc(sizeof(ListNode));
        if (i != 4) s2 = s2->nextPtr;
    }
    s2->nextPtr = NULL;
    s2 = inizio;

    stampalista(s1);
    stampalista(s2);
}