/* Data una lista a, i cui nodi abbiano campo informativo di tipo double, realizzare
1. una funzione che restituisca il minimo m ed il massimo M dei valori contenuti in a;
2. una funzione che, data la lista a, restituisca una lista c ordinata, che contenga i valori di a normalizzati
nell’intervallo [0, 1] (dato il valore x nella lista, il suo valore normalizzato e` (x−m)/(M−m);
3. una funzione che, dati i due valori reali l e r, con l < r, e un’altra lista b, crei una terza lista c ordinata,
i cui valori siano contenuti in a o in b e appartengano all’intervallo [l, r] */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

struct node {
    float data;
    struct node *next;
};

typedef struct node *NodePtr;

void insertnode (NodePtr inizio, float numeri[]);
void minmax (NodePtr lista, float *minptr, float *maxptr);
void normalizza (NodePtr lista, NodePtr newlista, int min, int max, int n);

void main (){
    srand(time(NULL));

    //creo lista, numero di nodi, ed array in cui sono contenuti i nodi
    NodePtr lista1 = malloc(sizeof(NodePtr));
    int numeronodi = 1;
    float numeri[MAX] = {0};

    //chiedo all'utente di inserire il numero di nodi
    printf("Inserisci il numero di nodi (max 99): ");
    scanf("%d", &numeronodi);

    //assegno all'array il numero di nodi randomizzati scelti
    printf("I numeri randomizzati sono:\n");
    for(int i=0; i<numeronodi; i++){
        numeri[i]= 1 + (rand() % 99);
        printf("%.2f ", numeri[i]);
    }
    printf("\n");

    //creo una lista di nodi e assegno i valori
    insertnode(lista1, numeri);

    //verifico minimo e massimo e li assegno a min e max
    float min = 0, max = 0;
    minmax(lista1, &min, &max);
    printf("Il minimo e' %.2f, il massimo e' %.2f\n", min, max);

    //stampo la lista per verificare che siano stati assegnati i nodi
    printf("I numeri nella lista sono:\n");
    NodePtr stampa =lista1;
    while (stampa!=NULL){
        printf("%.2f ", stampa->data);
        stampa=stampa->next;
    }
    printf("\n");

    //creo la nuova lista e la normalizzo
    NodePtr lista2 = malloc(sizeof(NodePtr));
    normalizza(lista1, lista2, min, max, numeronodi);

    //stampo la lista normalizzata
    printf("I valori normalizzati nella nuova lista sono:\n");
    while (lista2!=NULL){
        printf("%.2f ", lista2->data);
        lista2=lista2->next;
    }
    printf("\n");
}

void insertnode (NodePtr inizio, float numeri[]){
    int i = 0;
    NodePtr temp;

    while(numeri[i] != 0){
        inizio->data = numeri[i];
        inizio->next = malloc(sizeof(NodePtr));
        temp = inizio;
        inizio = inizio->next;
        i++;
    }
    printf("Sono stati inseriti %d numeri\n", i);
    temp->next =NULL;

}

void minmax (NodePtr lista, float *minptr, float *maxptr){
    *minptr = lista->data;
    *maxptr = lista->data;
    
    for(int i=0; i<10; i++){
        if( *minptr > lista->data ) *minptr = lista->data;
        if( *maxptr < lista->data ) *maxptr = lista->data;
        lista = lista->next;
    }

}

void normalizza (NodePtr lista, NodePtr newlista, int min, int max, int n){
    //dalla lista1 creo un array con i valori normalizzati
    float normarray[MAX] = {0};

    printf("I valori normalizzati sono:\n");
    for(int i=0; lista!=NULL; i++, lista=lista->next){
        normarray[i] = ((lista->data)-(min))/((max)-(min));
        printf("%.2f ", normarray[i]);
    }
    printf("\n");

    float swap = 0;
    for (int c = 0 ; c < n - 1; c++){
        for (int d = 0 ; d < n - c - 1; d++){
            if (normarray[d] > normarray[d+1]){
                swap = normarray[d];
                normarray[d] = normarray[d+1];
                normarray[d+1] = swap;
            }
        }
    }

    insertnode(newlista, normarray);    
}

//non funziona porca la porca