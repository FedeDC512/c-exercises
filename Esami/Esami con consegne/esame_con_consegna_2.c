/* Una matrice quadrata A ∈ R(nxn)
n×n si pu`o rappresentare come array di liste concatenate, in cui la i-esima
lista contiene solo gli elementi non nulli della i-esima riga della matrice. Un nodo della lista i-esima
contiene l’indice di colonna j e l’elemento non nullo A(i, j). Definire la struttura dati atta a contenere
la matrice A e costruire una funzione
float traccia(... A ..., int n);
che, data come argomento una matrice rappresentata come array di liste, restituisca la somma degli
elementi della diagonale principale. Si usi il tipo float per gli elementi della matrice. */

#include <stdio.h>
#include <stdlib.h>

struct node{
    int colonna;
    int data;
    struct node *next;
};

typedef struct node Nodo;
typedef struct node *NodoPtr;

float traccia(... A ..., int n);

void main(){
    int n = 5; //lunghezzaarray
    int matrice[n][n];

    Nodo arraybello[n] = malloc(n*sizeof(struct node));
    NodoPtr scorroarray = *arraybello;
    NodoPtr scorrolista = NULL;

    for(int i = 0; i<n; i++){
        NodoPtr finelista = scorryarray[i];
        for(int j = 0; j<n; j++){
            if(matrice[i][j] != NULL){
                scorryarray[i]-> data = matrice[i][j];
                scorroarray[i]-> colonna = j;
                finelista = scorryarray[i];
                scorryarray[i] = scorryarray[i]->next;
            }
        }
        finelista-> next = NULL;
    }



}

float traccia(... A ..., int n);