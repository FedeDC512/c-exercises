#include <stdio.h>
#include <stdlib.h>

struct node{
    unsigned int j;
    float value;
    struct node *nextPtr;
};

typedef struct node Node;
typedef struct node *NodePtr;

void crealista(struct node *A[], float M[], int n);
void ordinaliste(NodePtr A[], int n);

float traccia(struct node *A[], int n);

void simmetrizza(struct node *A[], int n);
float trovavalore(NodePtr A[], int n, int cercai, int cercaj);
void assegnavalore(NodePtr A[], int n, int cercai, int cercaj, float valore);

void stampastruttura(NodePtr A[], int n);

void main (){
    //creo una matrice di prova e la stampo
    int n = 5; //lunghezza matrice
    float M[5][5] = {{36,1,2,3,4},{14,12,11,13,10},{23,21,24,20,22},{33,31,32,30,34},{40,41,42,44,43}};
    printf("La matrice iniziale e':\n");
    for (int i=0; i<5; i++){
	    for (int j=0; j<5; j++){
	        printf("%5.2f ", M[i][j]);
	    }
        printf("\n");
    }
    printf("\n");
    //creo array di nodi
    NodePtr A[n];
    printf("Ho creato la struttura array di liste\n");
    //chiamo crealista
    crealista(&A, &M, n);
    
    stampastruttura(&A, n);
    printf("Ordino individualmente le liste all'interno dell'array...\n");
    ordinaliste(&A, n);
    stampastruttura(&A, n);
    
    printf("La somma della diagonale e' %.2f\n\n", traccia(&A, n));

    simmetrizza(&A, n);
    stampastruttura(&A, n);
    printf("Codice by Fede :)");
}

void crealista(struct node *A[], float M[], int n){
    for (int i=0; i<n; i++){
        A[i] = malloc(sizeof(Node));
        NodePtr scorrilista = A[i];
        NodePtr mettifine = A[i];
	    for (int j=0; j<n; j++){
	        scorrilista->j=j;
            scorrilista->value = *(M+i*n+j);
            //printf("%f", *(M+i*n+j)); 
            scorrilista->nextPtr = malloc(sizeof(Node));
            printf("Ho correttamente assegnato il valore %5.2f in posizione [%d][%d] nell'array di liste\n", scorrilista->value, i, j);
            mettifine = scorrilista;
            scorrilista = scorrilista->nextPtr;
	    }
        mettifine->nextPtr = NULL;
        free(scorrilista);
    }
}

void ordinaliste(NodePtr A[], int n){
    int valoretemp = 0;
    int jtemp = 0;

    NodePtr scorrilista;

    for (int i = 0 ; i<n ; i++){
        for(int check = 0; check < n ; check++){
            scorrilista = A[i];
            for (int scorri = 0; scorri < n; scorri++){
                if (scorrilista->nextPtr != NULL && scorrilista->value > (scorrilista->nextPtr)->value){
                    valoretemp = scorrilista->value;
                    jtemp = scorrilista->j;

                    scorrilista->value = (scorrilista->nextPtr)->value;
                    scorrilista->j = (scorrilista->nextPtr)->j;

                    (scorrilista->nextPtr)->value = valoretemp;
                    (scorrilista->nextPtr)->j = jtemp;
                }
                scorrilista=scorrilista->nextPtr;
            }
        }
    }
    printf("Le liste sono state correttamente ordinate!\n");
}

float traccia(struct node *A[], int n){
    float sommadiagonale = 0;
    for (int i=0; i<n; i++){
        NodePtr scorrilista = A[i];
	    for (int j=0; j<n; j++){
            //printf("%.2f ", scorrilista->value);
            if(i == j){
                sommadiagonale += scorrilista->value;
                //printf("sommo %.2f ", scorrilista->value);
            }
            scorrilista = scorrilista->nextPtr;
	    }
    }
    return sommadiagonale;
}

void simmetrizza(struct node *A[], int n){
    for (int i=0; i<n; i++){
        NodePtr scorrilista = A[i];
	    for (int j=0; j<n; j++){
            float media = (trovavalore(A, n, i, j) + trovavalore(A, n, j, i))/2;
            printf("Sostituisco i valori %5.2f [%d,%d] e %5.2f [%d,%d] con la loro media %5.2f\n",trovavalore(A, n, i, j), i, j, trovavalore(A, n, j, i), j, i, media);
            assegnavalore(A, n, i, j, media);
            assegnavalore(A, n, j, i, media);
            scorrilista = scorrilista->nextPtr;
	    }
    }
}

float trovavalore(NodePtr A[], int n, int cercai, int cercaj){

    NodePtr nodotrovato = A[cercai];
    NodePtr scorrilista = A[cercai];
    for(int j = 0; j < cercaj+1; j++){
        //printf("%.2f",scorrilista->value);
        nodotrovato = scorrilista;
        scorrilista = scorrilista->nextPtr;
    }
    return nodotrovato->value;
    
}

void assegnavalore(NodePtr A[], int n, int cercai, int cercaj, float valore){
    
    NodePtr nodotrovato = A[cercai];
    NodePtr scorrilista = A[cercai];
	for (int j = 0; j < cercaj+1; j++){
        nodotrovato = scorrilista;
        scorrilista = scorrilista->nextPtr;
    }
    nodotrovato->value = valore;
}

void stampastruttura(NodePtr A[], int n){
    printf("\nStampo la struttura:\n");
    for (int i=0; i<n; i++){
        NodePtr scorrilista = A[i];
	    for (int j=0; j<n; j++){
            //printf("%.2f ", scorrilista->value);
            printf("%5.2f -> ",scorrilista->value);
            scorrilista = scorrilista->nextPtr;
	    }
        printf("NULL\n|\n");
    }
    printf("Fine\n\n");
}