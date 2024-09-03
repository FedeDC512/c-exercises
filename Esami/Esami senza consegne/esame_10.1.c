#include <stdio.h>
#include <stdlib.h>

typedef struct cammino
{
    size_t nodo;
    struct cammino *next;
} Cammino;

typedef struct arco
{
    size_t nodo;
    struct arco *arcoPtr;
} Arco;

typedef struct nodo
{
    size_t nodo;
    struct arco *arcoPtr;
    struct nodo *nodoPtr;
} Nodo;

void acquisisciArchi(Nodo *);
Nodo *inserisciNodo(Nodo *, Nodo *);
Arco *inserisciArco(Arco *, Arco *);
void stampaAdiacenze(Nodo *);
Cammino *inserisciCammino(Cammino *, int);
void stampaCammino(Cammino *);

int main()
{

    Arco *p = NULL;
    Nodo *inizio = NULL;
    Nodo *nodoTemp;
    Cammino *testa;
    size_t temp;
    int tempCamm;
    char scelta;

    do
    {
        printf("Inserisci il nodo di partenza: ");
        scanf("%lu", &temp);
        nodoTemp = (Nodo *)malloc(sizeof(Nodo));
        nodoTemp->nodo = temp;
        nodoTemp->nodoPtr = NULL;
        nodoTemp->arcoPtr = NULL;
        acquisisciArchi(nodoTemp);
        inizio = inserisciNodo(inizio, nodoTemp);

        do
        {
            getchar();
            printf("Vuoi inserire un nuovo nodo?(s/n)");
            scelta = getchar();

        } while (scelta != 'n' && scelta != 's');
    } while (scelta == 's');

    stampaAdiacenze(inizio);

    printf("Inserisci il cammino da verificare (-1 per terminare): ");
    tempCamm = 0;
    while (tempCamm >= 0)
    {
        scanf("%d", &tempCamm);
        printf("%d\n", tempCamm);
        if (tempCamm >= 0)
            testa = inserisciCammino(testa, tempCamm);
    }
    stampaCammino(testa);

    return 0;
}

void acquisisciArchi(Nodo *nodo)
{
    char scelta;
    size_t temp;
    Arco *arcoTemp = NULL;
    do
    {
        printf("Inserisci un arco: ");
        scanf("%lu", &temp);
        arcoTemp = (Arco *)malloc(sizeof(Arco));
        arcoTemp->nodo = temp;
        arcoTemp->arcoPtr = NULL;
        nodo->arcoPtr = inserisciArco(nodo->arcoPtr, arcoTemp);

        do
        {
            getchar();
            printf("Vuoi inserire un nuovo arco?(s/n)");
            scelta = getchar();
        } while (scelta != 'n' && scelta != 's');
    } while (scelta == 's');
}

Arco *inserisciArco(Arco *inizio, Arco *nuovo)
{
    Arco *tmp = inizio;
    Arco *tmp2;
    if (tmp == NULL)
    {
        return nuovo;
    }
    if (tmp->nodo > nuovo->nodo)
    {
        printf("IF\n");
        nuovo->arcoPtr = inizio;
        inizio = nuovo;
    }
    else
    {
        printf("ELSE\n");
        while (tmp->arcoPtr != NULL && tmp->arcoPtr->nodo < nuovo->nodo)
            tmp = tmp->arcoPtr;

        tmp2 = tmp->arcoPtr;
        tmp->arcoPtr = nuovo;
        nuovo->arcoPtr = tmp2;
    }
    printf("INSERITO\n");
    return inizio;
}

Nodo *inserisciNodo(Nodo *inizio, Nodo *nuovo)
{
    Nodo *tmp = inizio;
    Nodo *tmp2;
    if (tmp == NULL)
    {
        return nuovo;
    }
    if (tmp->nodo > nuovo->nodo)
    {
        printf("IF\n");
        nuovo->nodoPtr = inizio;
        inizio = nuovo;
    }
    else
    {
        printf("ELSE\n");
        while (tmp->nodoPtr != NULL && tmp->nodoPtr->nodo < nuovo->nodo)
            tmp = tmp->nodoPtr;

        tmp2 = tmp->nodoPtr;
        tmp->nodoPtr = nuovo;
        nuovo->nodoPtr = tmp2;
    }
    printf("INSERITO\n");
    return inizio;
}

void stampaAdiacenze(Nodo *start)
{
    printf("Stampo\n");
    while (start != NULL)
    {
        printf("%lu -> ", start->nodo);
        Arco *tmp = start->arcoPtr;
        while (tmp != NULL)
        {
            printf("%lu -> ", tmp->nodo);
            tmp = tmp->arcoPtr;
        }
        printf("\n");
        start = start->nodoPtr;
    }
}

Cammino *inserisciCammino(Cammino *testa, int x)
{

    Cammino *tmp = testa;

    if (tmp == NULL)
    {
        testa = (Cammino *)malloc(sizeof(Cammino));
        testa->nodo = x;
        testa->next = NULL;
    }
    else
    {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = (Cammino *)malloc(sizeof(Cammino));
        tmp->next->nodo = x;
        tmp->next->next = NULL;
    }
    return testa;
}

void stampaCammino(Cammino *testa)
{
    while (testa != NULL)
    {
        printf("%lu->", testa->nodo);
        testa = testa->next;
    }
    printf("NULL\n");
}