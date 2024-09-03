/* Scrivere una funzione ricorsiva void simmetrizza (struct node ** a) che,
ricevuta come argomento una lista concatenata di N valori a virgola mobile,
restituisca nello stesso argomento una lista in cui l'elemento i-esimo e
quello (N-i)-esimo hanno valori uguali e pari alla media dei valori di
posizione i e (N-i) nella lista originale. Ad esempio, data la lista
3.0->5.0->-2.0->2.0->-3.0
sarà trasformata in
0.0->>3.5->-2.0->3.5->0.0 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
    float data;
    struct node *next;
};

typedef struct node *NodePtr;

void insertnode (NodePtr inizio, int numeri[]);
NodePtr simmetrizza (struct node ** a);

void main (){
    srand(time(NULL));
    NodePtr lista = malloc(sizeof(NodePtr));
    float numeri[10] = {0};
    printf("I numeri randomizzati sono:\n");
    for(int i=0; i<10; i++){
        numeri[i]= 1 + (rand() % 99);
        printf("%.2f ", numeri[i]);
    }
    printf("\n");

    insertnode(lista, numeri);
    NodePtr listanormalizzata = simmetrizza (lista);



}

void insertnode (NodePtr inizio, int numeri[]){
    NodePtr temp;

    for(int i=0; i<10; i++){
        inizio->data = numeri[i];
        inizio->next = malloc(sizeof(NodePtr));
        temp = inizio;
        inizio = inizio->next;
    }
    temp->next =NULL;

}

NodePtr simmetrizza (struct node ** a){
    NodePtr listadef = malloc(sizeof(NULL));

    /*NodePtr temp = *a;
    float inizio = (*a)->data;
    while((*a)->next != NULL){
        *a = (*a)->next;
    }
    float fine = (*a)->data;

    listadef->data = (inizio + fine)/2;*/

    if((*a)->next != NULL){
        simmetrizza(a->next);
    }


}

//non finito