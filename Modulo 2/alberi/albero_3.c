#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int data;
    struct node* right;
    struct node* left;
};

typedef struct node *NodePtr; //NodePtr

void insertNode(NodePtr *treePtr, int value);
void inOrder(NodePtr treePtr);


void main (){

    srand(time(NULL));

    NodePtr albero = malloc(sizeof(struct node));
    NodePtr start = albero;

    int numeri[10];
    for(int i=0; i<10; i++){
        numeri[i]= 1 + (rand() % 99);
        printf("%d ", numeri[i]);
    }
    printf("\n");

    for(int i=0; i<10; i++){
        insertNode(&albero, numeri[i]);
    }

    inOrder(start);
   

    };

    void insertNode(NodePtr *treePtr, int value){
    
        if (*treePtr == NULL){
            *treePtr = malloc(sizeof(struct node));

            if (*treePtr != NULL) {
                (*treePtr)->data = value;
                (*treePtr)->left = NULL;
                (*treePtr)->right = NULL;
            }
            else {
                printf("%d not inserted. No memory available.\n", value);
            }
	    }

        else{
            if (value < (*treePtr)->data) {
                insertNode(&((*treePtr)->left), value);
            }
            else if (value > (*treePtr)->data) {
                insertNode(&((*treePtr)->right), value);
            }
            else {
                printf("%s", "dup");
            }
        }
    }

    void inOrder(NodePtr treePtr)
{
	if (treePtr != NULL) {
		inOrder(treePtr->left);
		printf("%3d", treePtr->data);
		inOrder(treePtr->right);
	}
}