#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
	int(*fun)(int a);
	int arg;
	struct node *next;
};
typedef struct node *NodePtr;

int verificaprimo(int n);
void insertnode(NodePtr lista, int numeronodi, int numeri[], int(*myfun[])(int a));
void splitprimes(struct node *l, struct node **l1, struct node **l2);
//void splitprimes(NodePtr l,NodePtr *l1, NodePtr *l2);

void main(){
	srand(time(NULL));
	int numeronodi = 0;
	printf("Inserisci il numero di nodi nella lista: ");
	scanf("%d", &numeronodi);
	char numerirandom;
	printf("Vuoi inserire %d numeri casualmente da 1 a 100 (s/n)? ", numeronodi);
	numerirandom = 's'; //non funziona getchar() :(
	printf("\n");
	int arraynumeri[99]={0}; //non funziona arraynumeri[numeronodi]
	if(numerirandom =='s'){
		printf("I numeri randomizzati sono: ");
		for (int i=0; i<numeronodi; i++){
			arraynumeri[i]= 1 +(rand() % 99);
			printf("%d ", arraynumeri[i]);
		}
		printf("\n");
	}
	else if (numerirandom == 'n'){
		for (int i=0; i<numeronodi; i++){
			printf("Inserisci il nodo numero %d: ", i);
			scanf("%d", arraynumeri[i]);
		}
	}
	else printf("Inserisci una lettera valida!");
	
	NodePtr lista = malloc(sizeof(NodePtr));
	NodePtr verificaptr = lista;
	int (*myfun[1]) = {verificaprimo};
	insertnode (lista, numeronodi, arraynumeri, myfun);
	
	for(int j=0; j<numeronodi; j++){
		if (verificaptr->fun(verificaptr->arg) == 1) printf("Il numero %d e' primo\n", verificaptr->arg);
		else if (verificaptr->fun(verificaptr->arg) == 0) printf("Il numero %d non e' primo\n", verificaptr->arg);
		else printf("Stampa di prova del numero %d il cui output della funzione verificaprimo e' %d\n", verificaptr->arg, verificaptr->fun(verificaptr->arg));
		verificaptr = verificaptr->next;
	}
	
	NodePtr listaprimi = malloc(sizeof(NodePtr));
	NodePtr listanoprimi = malloc(sizeof(NodePtr));
	splitprimes(lista, &listaprimi, &listanoprimi);
	
	printf("Stampo la lista completa: ");
	while(lista != NULL){
		printf("%d ", lista->arg);
		lista=lista->next;
	}
	printf("\n");
	
	printf("Stampo la lista di primi: ");
	while(listaprimi != NULL){
		printf("%d ", listaprimi->arg);
		listaprimi=listaprimi->next;
	}
	printf("\n");
	
	printf("Stampo la lista di non primi: ");
	while(listanoprimi != NULL){
		printf("%d ", listanoprimi->arg);
		listanoprimi=listanoprimi->next;
	}
	printf("\n");
	printf("Agnello Federico");
	
}

void insertnode(NodePtr lista, int numeronodi, int numeri[], int(*myfun[])(int a)){
	NodePtr temp = lista;
	for(int i=0; i<numeronodi;i++){
		lista->next = malloc(sizeof(NodePtr));
		lista->arg = numeri[i];
		lista->fun = myfun[0];
		temp=lista;
		lista=lista->next;
	}
	temp->next=NULL;
}

int verificaprimo(int n){
	int out, verifica=0; //se out=1 primo, se out=0 non primo
	for(int i=2; i<=n/2; i++){
		//verifica negativo
		if (n%1 == 0){
			verifica=1;
			break;
		}
	}
	if (n==1){
		out = 1;
	}
	else {
		if (verifica ==0){
		out = 1;
		}
		else out = 0;
	}	
	return out;
}

void splitprimes(struct node *l, struct node **l1, struct node **l2){
	NodePtr temp1 = malloc(sizeof(NodePtr));
	NodePtr temp2 = malloc(sizeof(NodePtr));
	while(l!=NULL){
		if (l->fun(l->arg) == 1){
			(*l1)->next = malloc(sizeof(NodePtr));
			(*l1)->arg = l->arg;
			temp1=(*l1);
			(*l1)=(*l1)->next;
			l=l->next;
		}
		else if (l->fun(l->arg) == 0){
			(*l2)->next = malloc(sizeof(NodePtr));
			(*l2)->arg = l->arg;
			temp2=(*l2);
			(*l2)=(*l2)->next;
			l=l->next;
		}
		else {
			printf("Qualcosa e' andato storto nell'inserimento di %d nelle liste, il suo output della funzione e' %d", l->arg, (l->fun(l->arg)));
			l=l->next;
		}
	}
	temp1=NULL;
	temp2=NULL;
}	