#include <stdio.h>
#include <stdlib.h>

struct node{
    Item item;
    struct node *leftPtr;
    struct node *rightPtr;
};

typedef struct node TreeNode;
typedef struct node *TreeNodePtr;

static void insertNode(TreeNodePtr *treePtr, Item item);

// inserisci un nodo nell'albero
void insertNode(TreeNodePtr *treePtr, Item item)
{
    // se l'albero e' vuoto
    if (*treePtr == NULL) {
        *treePtr = malloc(sizeof(TreeNode));

    // se la memoria e' stata allocata, allora memorizza il valore
        if (*treePtr != NULL) {
            (*treePtr)->item = item;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
            }
        else {
            printf("Item non inserito, nessuna memoria disponibile\n", item);
        }
    }
    else { // l'albero non e' vuoto
        // il valore da inserire e' minore del valore nel nodo corrente
        if (item < (*treePtr)->item) {
            insertNode(&((*treePtr)->leftPtr), item);
        }

        // il valore da inserire e' maggiore del valore nel nodo corrente
        else if (item > (*treePtr)->item) {
            insertNode(&((*treePtr)->rightPtr), item);
        }
        else { // i valori duplicati vengono ignorati
            printf("Item duplicato\n");
        }
    }
}

/*
alloca lo spazio per una matrice bidimensionale A di nxm double,
in modo tale che gli elemnti della matrice siano nell'heap secondo
la rappresentazione per riga, ovvero deve
M[i][j]==M[0][i+n+j]
*/
double ** allocacontigua(unsigned int n, unsigned int m){
    double **M = (double**) malloc (m*sizeof(double*)); //colonne x sizeof puntatore a double
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            /*devi tipo assegnare i valori con M[i][j]=qualcosa, magari con un if,
            non lo so perchè dalla foto non si capisce nulla, scusa*/
        }
    }
    return M;
}

    static int dpt[200];
    unsigned long int f (unsigned int n) {
        printf("dentro ");
        if ( 0==n || 1==n ) return n;
        if (dpt[n] == 0) dpt[n] = f(n-2) + f(n-1);
        return dpt[n];
    }

void main(){
    printf("%d", f(5));
}

//1,1,2,3,5,8,13