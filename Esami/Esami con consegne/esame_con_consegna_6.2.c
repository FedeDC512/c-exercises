#include <stdio.h>
#include <stdlib.h>

//creo la struttura 'struct node' dove passo un intero senza segno, un valore float e un riferimento alla stessa struttura chiamato nextptr
struct node {
 unsigned int j;
 float value;
 struct node *nextptr;
};

typedef struct node Node; //ridefinisco 'struct node' come 'Node'
typedef Node *NodePtr; //ridefinisco Node come NodePtr che è un puntatore a Node

//prototipi di funzione
void crealista(NodePtr A[], float M[5][5], int n);
float traccia (NodePtr A[], float n);
float trovavalore(NodePtr A[], int n, int cercai, int cercaj);
void assegnavalore(NodePtr A[], int n, int cercai, int cercaj, float valore);
void simmetrizza(NodePtr A[], int n);

void main(){
    int n = 5;
    float b;
    float Matrice[5][5] = { {3,4,5,8,12},{9,10,13,15,17},{20,22,21,23,24},{30,32,33,34,35},{40,43,56,67,90}}; //creo la matrice 5x5, con dati inseriti manualmente
    for(int i = 0; i<5; i++){  //creo un for che scorre l'indice i che rappresenta le righe della matrice
        for (int j = 0; j<5; j++){  //creo un for più interno l'indice j che rappresenta le colonne della matrice
            printf("% .2f", Matrice[i][j]);  //stampo la matrice a ogni giro di i e j

                   }
            printf("\n");
    }
    NodePtr A[n]; //creo un nodo alla Matrice
    crealista(&A, &Matrice, n); //richiamo la funzione 'crealista'

    printf("La somma della diagonale è %.2f", traccia(&A, n));

    printf("\n");

    simmetrizza(&A, n);
}

void crealista(NodePtr A[], float M[5][5], int n){ //creo la funzione 'crealista' dove passo come argomenti il nodo alla lista, la matrice 5x5, e un intero n

for (int i = 0; i<n; i++){ //creo un for che incrementa l'indice i, in modo da creare un nodo per ogni elemento della Matrice
    A[i] = malloc(sizeof(Node)); //alloco memoria per la lista
    NodePtr Attraversa =A[i]; //creo una variabile di tipo NodePtr e copio il valore della lista in base a i
    NodePtr ListaFine =  A[i]; //creo una variabile di tipo NodePtr e copio il valore della lista in base a i
    for(int j = 0; j<n; j++){ //creo un for che incrementi l'indice j
        Attraversa->j = j; //copio il valore di j nel unsigned int j puntato dalla variabile attraversa
        Attraversa->value = *(*M+i*n+j); //inserisco in ogni nodo della lista i vari elementi della matrice
        Attraversa->nextptr = malloc(sizeof(Node)); //alloco memoria per il nodo successivo
        printf("Assegno il valore %.2f alla posizione [%d][%d]\n",Attraversa->value, i,j);
        ListaFine = Attraversa; //faccio si che la variabile di tipo NodePtr 'ListaFine' punti allo stesso elemento di 'Attraversa'
    }
        Attraversa = Attraversa->nextptr;     //Sposto 'Attraverssa al nodo successivo
    ListaFine->nextptr = NULL; //faccio si che 'listafine' punti all'ultimo elemento della lista, mettendo il suo successivo a NULL
}

}

float traccia(NodePtr A[], float n){ //creo la funzione traccia dova passo come argomenti il puntatore al primo elemento della lista, e un float n

float somma = 0; //creo una variabile somma che mi serve per poter sapere la somma totale degli elementi della diagonale principale della mia matrice
for(int i = 0; i<5; i++){ //creo un for che aumenta l'indice i
    NodePtr Attraversa = A[i]; //creo una variabile locale 'Attraversa' di tipo NodePtr, che mi serve da puntatore alla lista
    for(int j = 0; j<5; j++){ //creo un for che aumenta l'indice j
        if (i == j){ //faccio un controllo dove se i è uguale a j, quindi i due indici si trovano nella stessa posizione all'interno della matrice
            somma+= Attraversa->value; //faccio l'addizione tra la variavìbile 'Somma e il valore contenuto nel nodo puntato dal puntatore 'Attraversa'
            printf("Sommo %.2f\n", Attraversa->value);

        }
        Attraversa = Attraversa->nextptr; //sposto 'Attraversa' al nodo successivo
    }

}
 return somma;//ritorno la somma nel main

}

float trovavalore(NodePtr A[], int n, int ri, int rj){  //creo una funzione 'trovavalore' dove passo come argomenti il puntatore al primo nodo della lista, un interno n, un intero ri che servirà come ricerca dell'indice i, e un intero ri, che servirà come ricerca dell'elemento j
    NodePtr trova = A[ri]; // creo la variabile 'trova' di tipo NodePtr
    NodePtr Attraversa = A[rj]; // creo la variabile 'Attraversa' di tipo NodePtr
    for (int j = 0; j < rj+1; j++){ //creo un for che incrementa l'indice j quando questo è minore dell'intero rj + 1
        trova = Attraversa; // faccio si che 'trova' punti allo stesso nodo di 'Attraversa'
        Attraversa = Attraversa->nextptr; //sposto 'Attraversa' al nodo successivo
    }
        return trova->value; //ritorno il valore contenuto nel nodo puntato da 'T

}

void assegnavalore(NodePtr A[], int n, int ri, int rj, float valore){ // creo la funzione 'assegnavalore' dove passo come argomenti gli stessi della funzione precedente, più un float 'valore', in modo da poter asseganre un valore
       NodePtr trova = A[ri];// creo un variabile 'trova' di tipo NodePtr
       NodePtr Attraversa = A[rj];//creo una variabile 'Attraversa' di tipo NodePtr
        for (int j = 0; j < rj+1; j++){//creo un for che incrementa l'indice j quando questo è minore dall'intero j+1
            trova = Attraversa; //faccio si che 'trova' punti allo stesso nodo che punta il puntaotre 'Attraversa'
            Attraversa = Attraversa->nextptr;//sposto il puntatore 'Attraversa' al nodo successivo
}
            trova->value = valore;// copio il valore da me inserito come float nel valore contenuto nel nodo puntato dal puntatore 'trova'
}

void simmetrizza(NodePtr A[], int n){ //creo la funzione 'simmetrizza' dove passo come argomenti il puntatore al primo elemento della lista e un intero n

     for (int i=0; i<n; i++){ //creo un for che incrementa l'indice c fino a che non è maggiore o uguale a n
        NodePtr Attraversa = A[i]; //creo una variabile 'Attraversa' di tipo NodePtr, che puntera ai vari elementi della lista in base all'indice i
	    for (int j=0; j<n; j++){ // creo un for che incrementa l'indice j fino a che j non è maggiore o uguale a n
            float media = (trovavalore(A, n, i, j) + trovavalore(A, n, j, i))/2; // calcolo la media dei valori che si trovano alla posizione i,j - j,i con i e j uguali richiamndo la funzione trovavalore che appunto trova gli elementi che si trovano nelle posizioni che rispettano quella determinata condizione
            printf("Sostituisco i valori %5.2f [%d,%d] e %5.2f [%d,%d] con la loro media %5.2f\n",trovavalore(A, n, i, j), i, j, trovavalore(A, n, j, i), j, i, media);
            assegnavalore(A, n, i, j, media); //richiamo la funzione assegnavalore in modo da asseganare alle posizione che rispetta la stessa condizione che usavo per trovavalore, passando però anche la media, in modo da avere la media dei due elementi precedenti nelle poszioni che quegli elemnti occupavano in precedenza            assegnavalore(A, n, j, i, media);
            Attraversa = Attraversa->nextptr; //sposto 'Attraversa' al nodo successivo

}
     }

}


//fine
