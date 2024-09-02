#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodeT{
    int item;
    struct nodeT *next;
    struct nodeT *previous;
};
typedef struct nodeT ListNode;
typedef ListNode *ListNodePtr;

// struttura autoreferenziale
struct treeNode {
    struct treeNode *leftPtr; // puntatore al sottoalbero sinistro
    int data; // valore del nodo
    struct treeNode *rightPtr; // puntatore al sottoalbero destro
};
typedef struct treeNode TreeNode; // sinonimo per struct treeNode
typedef TreeNode *TreeNodePtr; // sinonimo per TreeNode*

int menu();
ListNodePtr crealista(int* numeri, int n);
void stampalista(ListNodePtr lista);
//void insertNode(TreeNodePtr *treePtr, int value);
//void inOrder(TreeNodePtr treePtr);


int main()
{
    int m = menu();
    int a;
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &a);
    int numeri[a];
    if(m == 1){ //numeri manuali
        for(int i = 0; i<a; i++){
            printf("Inserisci il numero %d: ", i);
            scanf("%d", &numeri[i]);
        }
    }
    else if (m==2){//numeri casuali
        for(int i = 0; i<a; i++){
            numeri[i] = rand() % 100;
        }
    }
    else {
        printf("Valore non valido, i numeri saranno inseriti casualmente");
            for(int i = 0; i<a; i++){
                numeri[i] = rand() % 100;
            }
    }

    printf("I numeri inseriti sono: ");
    for(int i = 0; i<a; i++){
        printf("%d ", numeri[i]);
    }
    printf("\n");
    
    ListNodePtr lista = crealista(numeri, a);
    printf("\n");
    stampalista (lista);


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

int menu(){
    int n;
    printf("Se vuoi inserire i numeri manualmente inserisci 1, altrimenti inserisci 2 per generarli casualmente: ");
        scanf("%d", &n);
    return n;
}

ListNodePtr crealista(int* numeri, int n){
    ListNodePtr inizio = malloc(sizeof(ListNode));
    ListNodePtr temp = inizio; //mi creo un temp che scorre la lista
    ListNodePtr fine = temp; //mi creo la fine che assegnerà la fine della lista
    ListNodePtr prima = NULL;
    for(int i = 0 ; i<=n-1 ; i++){
        temp->item = *(numeri+i); //assegnazione
        printf("ho inserito il valore %d\n", *(numeri+i));
        temp->next = malloc(sizeof(ListNode)); //allocazione
        temp-> previous = prima;
        prima = temp;
        fine = temp; //mi segno la fine, che sta sempre un nodo indietro
        temp = temp->next; //spostamento
    }
    free(temp); //libero lo spazio a cui punta il temp
    fine->next = NULL; //finisco la lista

    return inizio;
}

void stampalista(ListNodePtr lista){
    while(lista != NULL){
        printf("%d -> ", lista->item); //stampo il valore nel nodo
        lista = lista->next; //mi sposto sul nodo succssivo
    }
    printf("NULL");
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