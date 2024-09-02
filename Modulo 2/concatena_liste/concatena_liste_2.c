/* (Concatenamento di liste) Scrivete un programma che concateni due liste collegate di
caratteri. Il programma deve includere la funzione concatenate che riceve come argomen-
ti i puntatori a entrambe le liste e concatena la seconda lista alla prima. */

#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *next;
};

typedef struct node *snode;

void concatenate (snode *sPtr1, snode *sPtr2);

void main (){
    char ciao[4]= "ciao";

    snode s1 = malloc(sizeof(snode)), shead = s1;  
    for(int i=0; i<4 ; i++){
        s1->data = ciao[i];
        s1->next = malloc(sizeof(snode));
        if (i != 3) s1 = s1->next;
    }
    s1->next = NULL;

    char bello[5]= "bello";

    snode s2 = malloc(sizeof(snode)), shead2 = s2;  
    for(int i=0; i<5 ; i++){
        s2->data = bello[i];
        s2->next = malloc(sizeof(snode));
        if (i != 4) s2 = s2->next;
    }
    s2->next = NULL;

    s1->next = shead2;

    while (shead!=NULL){
        printf("%c", shead->data);
        shead=shead->next;
    }
}