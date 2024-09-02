#include <stdio.h>
#include <stdlib.h>

 struct node{
    unsigned int j;
    float value;
    struct node *nextPtr;};

typedef struct node nodo;
typedef struct node *nodeptr;

void crealista (struct node *A[], float M[], int n){
    
    for (int i=0; i<4; i++){
        A[i]=malloc(sizeof(nodo));
        nodeptr scorrilista=A[i];
        nodeptr mettifine=A[i];
        for(int j=0; j<4; j++){
            scorrilista->j=j;
            scorrilista->value=*(M+i*n+j);
            scorrilista->nextPtr=malloc(sizeof(nodo));
            printf("Valore assegnato", scorrilista-> value, i,j);
    mettifine=scorrilista;
    scorrilista=scorrilista->nextPtr;
        }
            mettifine->nextPtr=NULL;
        
    }
    
}

float traccia(struct node *A[], float M[], int n){
    int sommadiagonale=0;
    for ( int i = 0; i<n; i++) {
        nodeptr scorrilista=A[i];
        for (int j = 0; j < n; j++) {
    
            if (i==j) {
                sommadiagonale+=scorrilista->value;
            
            }
        scorrilista =scorrilista->nextPtr;
        }
    
    }
 return sommadiagonale;
}

void simmetrizza (struct node *A[], int n){
    int simmetrizza;
    
    for (int i=0; i<4;i++){
        nodeptr scorrilista=A[i];
        for(int j=0; j<4; j++){
            simmetrizza=(A[i][j]+A[j][i])/2;
            simmetrizza=A[i];
            
        }
    }
    
}    

void main(){
    int n=4;
    float M[4][4];
    for(int i=0; i<4;i++){
        for(int j=0;j<4;j++){
        scanf("%f",&M[i][j]);
        printf("%f",M[i][j]);
        }
    }
    nodeptr A[n];
    crealista(&A,&M,n);



}