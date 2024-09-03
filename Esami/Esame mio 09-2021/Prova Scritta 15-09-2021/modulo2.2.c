#include <stdio.h>
#include <stdlib.h>
struct node
{
    int (*fun)(int a);
    int arg;
    struct node *nextPtr;
};

int fun(int a)
{
    return a;
}

void valuta(struct node *l)
{
    while (l != NULL)
    {
        int a = l->fun(l->arg);
        l = l->nextPtr;
        printf("%d \n", a);
    }
}

int main()
{
    struct node *list = NULL;

    struct node *n1 = malloc(sizeof(struct node));
    n1->fun = fun;
    n1->arg = 10;
    n1->nextPtr = NULL;

    struct node *n = malloc(sizeof(struct node));
    n->fun = fun;
    n->arg = 5;
    n->nextPtr = n1;

    list = n;

    valuta(list);

    return 0;
}