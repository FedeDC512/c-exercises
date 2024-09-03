#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int (*fun)(int a);
	int arg;
	struct node *nextPtr;
};
typedef struct node *nodeptr;

//numeroprimo
int fun(int num)
{
	int divisore;
	int trovato = 0;
	divisore = 2;
	while ((divisore < num) && !trovato)
	{
		if ((num % divisore) == 0)
			trovato = 1;
		else
			divisore++;
	}

	return !trovato;
}

void insert(nodeptr *inizio, int valore)
{
	nodeptr newptr;
	nodeptr prev;
	nodeptr cur;
	newptr = malloc(sizeof(struct node));
	if (newptr != NULL)
	{
		newptr->fun = fun;
		newptr->arg = valore;
		newptr->nextPtr = NULL;
		prev = NULL;
		cur = *inizio;
		while (cur != NULL && valore > cur->arg)
		{
			prev = cur;
			cur = cur->nextPtr;
		}
		if (prev == NULL)
		{
			newptr->nextPtr = *inizio;
			*inizio = newptr;
		}
		else
		{
			;
			prev->nextPtr = newptr;
			newptr->nextPtr = cur;
		}
	}
	else
	{
		printf("memoria non allocata");
	}
}
//int isempty(nodeptr prptr){

//return prptr== NULL;

//}

void printlist(nodeptr prptr)
{
	if (prptr == NULL)
	{
		printf("la lista e'vuota\n ");
	}
	else
	{
		while (prptr != NULL)
		{
			printf("%d->", prptr->arg);
			prptr = prptr->nextPtr;
		}
		puts("NULL");
	}
}

void splitprimes(struct node *l, struct node **l1, struct node **l2)
{

	while (l != NULL)
	{
		if (l->fun(l->arg))
		{
			insert(l1, l->arg);
		}
		else
		{
			insert(l2, l->arg);
		}
		l = l->nextPtr;
	}
}

int main()
{
	nodeptr l = NULL;
	nodeptr l1 = NULL;
	nodeptr l2 = NULL;
	int numero;
	printf("\ninserisci -1 per terminare:");
	printf("\ninserisci una lista di numeri:");
	do
	{

		scanf("%d", &numero);
		if (numero >= 0)
		{
			insert(&l, numero);
		}
		else
		{
			printf("\nsequenza terminata");
		}
	} while (numero >= 0);

	printf("\nlista completa:\n ");
	printlist(l);
	splitprimes(l, &l1, &l2);
	printf("lista primi:\n");
	printlist(l1);
	printf("\nlista NON primi:\n");
	printlist(l2);
}