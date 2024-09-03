#include <stdio.h>
#include <stdlib.h>

struct node{
    unsigned int j;
    float value;
    struct node *nextptr;
};

typedef struct node Node;
typedef struct node *NodePtr;
//dichiarazione delle strutture e delle nomenclature ad essa collegate

void crealista(struct node *A[], float M[], int n){
    for (int i = 0; i < n; i++){
        A[i] = malloc(sizeof(Node)); //Allocazione del primo nodo della lista in posizione A[i]
        NodePtr scorri = A[i]; //Allocazione del nodo che ci tornerà utile a scorrere la lista
        NodePtr fine = A[i]; //Allocazione del nodo finale della lista
        for (int j = 0; j < n; j++){
            scorri->j = j;
            scorri->value = *(M+i*n+j); // Assegniamo il valore all'interno del nodo con la formula di puntatori di puntatori dell'array di liste
            scorri->nextptr = malloc(sizeof(Node)); //Allochiamo quindi il nodo successivo
            printf("Assegno il valore %.2f in posizione [%d][%d] dell'array \n", scorri->value, i, j); //stampa di controllo per verificare l'effettivo scambio
            fine = scorri;
            scorri = scorri -> nextptr; //spostamento al successivo nodo
        }
        fine -> nextptr = NULL; //allocazione finale a NULL del successivo così da non avere valori vari di garbage
    }
}

void ordinaliste(NodePtr A[], int n){ //ordinamento di liste con il metodo bubblesort
    int tempval = 0; //inizializzazione di una variabile temporanea utile ad effettuare i confronti per ordinare all'interno del bubblesort
    int tempj = 0; //inizializzazione di una variabile temporanea contenente l'indice di colonna
    NodePtr scorri; //inizializzazione del nodo di scorrimento
    for (int i = 0; i<n ; i++){
        for (int controllo = 0; controllo < n ; controllo++){ //controlla se la lista è ordinata  (n volte)
            scorri = A[i]; //assegnazione della posizione al nodo "scorri"
            for(int avanza = 0; avanza < n ; avanza++){
                if (scorri -> nextptr != NULL && (scorri -> value) > ((scorri -> nextptr) -> value)){ //metodo di ordinamento SE( prossimo numero è diverso da null e num1 maggiore di num2)
                    tempval = scorri -> value; //Assegnazione del valore maggiore alla variabile temporanea
                    tempj = scorri -> j; //Assegnazione dell'indice alla variabile temporanea

                    scorri -> value = (scorri -> nextptr) -> value; //assegnazione del valore successivo al nodo precedente
                    scorri -> j = (scorri -> nextptr) -> j; //assegnazione dell'indice successivo

                    (scorri -> nextptr) -> value = tempval; //sovrascrittura del valore nel nodo successivo con il valore maggiore
                    (scorri -> nextptr) -> j = tempj; //sovrascrittura dell'indice 
                }
                scorri = scorri -> nextptr; // scorrimento al nodo successivo
            }
        }
    }
    printf("Ordinamento liste avvenuto con successo! \n");
}

float traccia(struct node *A[], int n){
    float diagsum = 0; //Inizializziamo una variabile a cui assegnare la somma
    for(int i = 0; i<n ; i++){ //for di scorrimento delle righe
        NodePtr scorri = A[i];
        for(int j = 0; j < n ; j++){ //for di scorrimento delle colonne
            if (i == j){ //condizione per cui prendiamo a somma solo i numeri in diagonale(quindi con indice di colonna e righe uguale)
                diagsum += scorri -> value; //aumentiamo la variabile diagsum del valore trovato sulla diagonale
                printf("Sommiamo %.2f \n", scorri -> value);
            }
            scorri = scorri -> nextptr; //passiamo al nodo successivo
        }
    }
    return diagsum;
}

void printstruct(NodePtr A[], int n){ //funzione secondaria utile a stampare la struttura
    for(int i = 0; i<n ; i++){
        NodePtr scorri = A[i];
        for(int j = 0; j<n ; j++){
            printf("%5.2f > ", scorri -> value); //stampa del valore
            scorri = scorri -> nextptr; //scorrimento al successivo
        }
        printf("next \n   \n");
    }
    printf("Fine stampa \n\n");
}

float valuefinder(NodePtr A[], int n, int I, int J){ //funzione utile a trovare il valore all'interno della matrice
    NodePtr finded = A[I];
    NodePtr scorri = A[I];
    for(int j = 0; j < J+1 ; j++){
        finded = scorri;
        scorri = scorri ->nextptr;
    }
    return finded -> value;
}

float valueassign(NodePtr A[], int n, int I, int J, float value){ //funzione secondaria utile ad assegnare il valore che si vuole sovrascrivere all'interno della matrice
    NodePtr finded = A[I];
    NodePtr scorri = A[I];
    for(int j = 0; j < J+1 ; j++){
        finded = scorri;
        scorri = scorri -> nextptr;
    }
    finded -> value = value;
}

void simmetrizza(struct node *A[], int n){
    for(int i = 0; i<n ; i++){
        NodePtr scorri = A[i];
        for (int j=0; j<n ; j++){
            float med = (valuefinder(A , n, i , j) + valuefinder(A,n,j,i)) /2; //trovo il valore medio per simmetrizzare la matrice
            printf(" Simmetrizzo la matrice sostituendo i valori nelle posizioni [%d][%d] e [%d] [%d] con la loro media \n", i,j,j,i);
            valueassign(A,n,i,j,med); //assegnazione del valore medio in posizione i,j
            valueassign(A,n,j,i,med); //assegnazione del valore medio in posizione j,i
            scorri = scorri -> nextptr; //spostamento
        }
    }
    printf("\n");
}

void main(){
    int n = 3; //variabile di indicazione della dimensione della matrice
    float M[3][3] = {{3,8,13},{6,9,12},{6,10,14}}; //creazione ed assegnazione dei valori nella matrice
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n ; j++){
            printf("%.2f ", M[i][j]);
        } //for di scorrimento e stampa della matrice iniziale
    printf("\n");
    }
    NodePtr A[n]; //creazione del nodo iniziale della lista contenente l'array
    crealista(&A, &M, n); //chiamata a funzione di crealista
    ordinaliste(&A, n); //chiamata a funzione di ordinaliste (Metodo Bubblesort (ordine di n2) che effettua n^2/2 scambi (Sia in media che nel worst))
    printf("la somma della diagonale e' %.2f \n", traccia(&A,n)); //chiamata a funzione di traccia, con stampa diretta in quanto la funzione ha un valore di ritorno
    simmetrizza(&A, n); // chiamata a funzione della funzione simmetrizza che scambia i valori in posizione i,j e j,i con la loro media
    printstruct(&A, n); //chiamata a funzione della funzione printstruct che serve a stampare la struttura (Già ordinata e simmetrizzata, in questo caso)
}