/* Scrivete un programma che usi una pila per determinare se una stringa è un palindromo (cioè la stringa
si legge allo stesso modo in avanti e all’indietro). Il programma deve ignorare spazi e punteggiatura. */

#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node * next;
};

typedef struct node * NodePtr;

void main (){
    char parola[] = "radar";
    char lettera = parola[0];
    int count = 0;

    NodePtr pila = malloc(sizeof(NodePtr));
    NodePtr head = pila;
    while (lettera != '\0'){
        pila->data = lettera;
        lettera = parola[count+1];
        pila->next = malloc(sizeof(NodePtr));
        pila=pila->next;
        count++;
    }
    pila->next=NULL;
    NodePtr tail = pila;
    count = (int) count / 2;

    int i = 0;
    for (; i<count;){
        if (head->data == tail->data) i++;
        else break; 
    }
    if (i != 0) printf("La parola %s e' palindroma", parola);
    else printf("La parola %s non e' palindroma", parola);
}

//non va