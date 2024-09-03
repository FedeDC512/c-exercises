/* Prova 200716
Data una lista a, i cui nodi abbiano campo informativo di tipo double, realizzare
1. una funzione che restituisca il minimo m ed il massimo M dei valori contenuti in a;
2. una funzione che, data la lista a, restituisca una lista c ordinata, che contenga i valori di a normalizzati
nell'intervallo [0, 1] (dato il valore x nella lista, il suo valore normalizzato è (x-m)/(M-m));
3. una funzione che, dati i due valori reali l e r, con l < r, e un'altra lista b, crei una terza lista c ordinata,
i cui valori siano contenuti in a o in b e appartengano all'intervallo [l, r].
*/

#include <stdio.h>

struct List {
    double num;
    struct List *np;
};

typedef struct List* list;

double listMin(list l);
double listMax(list l);
list normalizeList(list l, double min, double max);
list intervalElements(list a, list b, unsigned l, unsigned r);

list array2list(double array[], int size) {
    list temp = malloc(sizeof(list));
    temp->num = array[0];
    temp->np = NULL;
    list result = temp;
    int i = 0;
    while (++i < size) {
        temp->np = malloc(sizeof(list));
        temp = temp->np;
        temp->num = array[i];
	}
	return result;
}

void main() {
    double arr1[5] = {1.21, 4.67, 10.42, 43.2, 24.12}, arr2[5] = {1.21, 4.67, 10.42, 43.2, 24.12};
    list als = array2list(arr1, 5), bls = array2list(arr2, 5);
    printf("Valore piu' piccolo presente nella lista : %.2f\n", listMin(als));
    printf("Valore piu' grande presente nella lista : %.2f\n", listMax(als));
    list c = normalizeList(als, listMin(als), listMax(als));
    printf("Valori normalizzati : ", c->num);
    while (c != NULL) {
        printf("%.2f, ", c->num);
        c = c->np;
    }
    int l, r;
    printf("\nInserisci un valore che indichi l'inizio dell'intervallo : ");
    scanf("%d", &l);
    printf("Inserisci un valore che indichi la fine dell'intervallo : ");
    scanf("%d", &r);
    if (r < l) return printf("Il valore che indica la fine non puo' essere minore di quello che indica l'inizio !");
    printf("Valori che appartengono all'intervallo [%d, %d] : ", l, r);
    list d = intervalElements(als, bls, l, r);
    while (d->np != NULL) {
        printf("%.2f, ", d->num);
        d = d->np;
    }
}

double listMin(list l) {
    list cursor = l;
    double min = cursor->num;
    while (cursor != NULL) {
        if (cursor->num < min) min = cursor->num;
        cursor = cursor->np;
    }
    return min;
}

double listMax(list l) {
    list cursor = l;
    double max = cursor->num;
    while (cursor != NULL) {
        if (cursor->num > max) max = cursor->num;
        cursor = cursor->np;
    }
    return max;
}

list normalizeList(list l, double min, double max) {
    list c = malloc(sizeof(list));
    list cursor = l, backup = c;
    c->num = (l->num - min) / (max - min);
    c->np = NULL;
    while ((cursor = cursor->np) != NULL) {
        c->np = malloc(sizeof(list));
		c = c->np;
		c->num = (cursor->num - min) / (max - min);
    }
    return backup;
}

list intervalElements(list a, list b, unsigned l, unsigned r) {
    list c = malloc(sizeof(list));
    list backup = c;
    while (a != NULL || b != NULL) {
        if (a->num >= l && a->num <= r) {
            c->num = a->num;
            c->np = malloc(sizeof(list));
            c = c->np;
        } else if (b->num >= l && b->num <= r) {
            c->num = b->num;
            c->np = malloc(sizeof(list));
            c = c->np;
        }
        a = a->np;
        b = b->np;
    }
    return backup;
}