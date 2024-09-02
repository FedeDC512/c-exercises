/* (Ricerca in un albero binario) Scrivete la funzione binaryTreeSearch che cerca di loca-
lizzare un valore specificato in un albero di ricerca binaria. La funzione deve ricevere come
argomenti un puntatore al nodo radice dell’albero binario e una chiave di ricerca. Se viene
trovato un nodo contenente la chiave di ricerca, la funzione deve restituire un puntatore a
quel nodo; altrimenti, la funzione deve restituire un puntatore NULL. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// struttura autoreferenziale
struct treeNode {
    struct treeNode *leftPtr; // puntatore al sottoalbero sinistro
    int data; // valore del nodo
    struct treeNode *rightPtr; // puntatore al sottoalbero destro
};

typedef struct treeNode TreeNode; // sinonimo per struct treeNode
typedef TreeNode *TreeNodePtr; // sinonimo per TreeNode*

// prototipi funzioni
void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
TreeNodePtr searchNode(TreeNodePtr treePtr, int num);

int main()
{
    int n;

    TreeNodePtr rootPtr = NULL; // albero inizialmente vuoto   
    srand(time(NULL));
    puts("\nI numeri casuali nell'albero sono:");
    // inserisci nell'albero valori a caso tra 0 e 14
    for (unsigned int i = 1; i <= 10; ++i) {
        int item = rand() % 15;
        printf("%3d", item);
        insertNode(&rootPtr, item);
    }

    printf("\n\nInserisci il numero di cui vuoi trovare l'indirizzo: ");
    scanf("%d", &n);

    // attraversa l'albero in ordine
    puts("\n\nThe inOrder traversal is:");
    inOrder(rootPtr);

    printf("\n\nL'indirizzo del numero %d e' %d", n, searchNode(rootPtr, n));

}

// inserisci un nodo nell'albero
void insertNode(TreeNodePtr *treePtr, int value)
{
    // se l'albero e' vuoto
    if (*treePtr == NULL) {
        *treePtr = malloc(sizeof(TreeNode));

        // se la memoria e' stata allocata, allora memorizza il valore
        if (*treePtr != NULL) {
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }
        else {
            printf("%d not inserted. No memory available.\n", value);
        }
    }
    else { // l'albero non e' vuoto
        // il valore da inserire e' minore del valore nel nodo corrente
        if (value < (*treePtr)->data) {
            insertNode(&((*treePtr)->leftPtr), value);
        }

        // il valore da inserire e' maggiore del valore nel nodo corrente
        else if (value > (*treePtr)->data) {
            insertNode(&((*treePtr)->rightPtr), value);
        }
        else { // i valori duplicati vengono ignorati
            printf("%s", "dup");
        }
    }
}

void inOrder(TreeNodePtr treePtr)
    {
    // se l'albero non e' vuoto, allora attraversalo
    if (treePtr != NULL) {
        inOrder(treePtr->leftPtr);
        printf("%3d", treePtr->data);
        inOrder(treePtr->rightPtr);
    }
    }

TreeNodePtr searchNode(TreeNodePtr treePtr, int num)
{   
    // se l'albero non e' vuoto, allora attraversalo
    if (treePtr != NULL) {
        searchNode(treePtr->leftPtr, num);
        if (treePtr->data == num) {
            return treePtr;
            };
        searchNode(treePtr->rightPtr, num);
    }
}