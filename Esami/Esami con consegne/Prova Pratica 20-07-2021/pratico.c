#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct arco{
    size_t nodo;
    struct arco *arcoPtr;
} Arco;
typedef struct arco * ArcoPtr;

void main (){

    FILE * fp = fopen("grafo.txt", "rw");
    char line[80];
    char * l;
    long node;

    ArcoPtr arraybello[4]; //= calloc(0, sizeof(ArcoPtr));
    int i = 0;


    while (fgets(l=line, sizeof(line), fp) != 0){
        arraybello[i] = malloc(sizeof(ArcoPtr));
        while (* l){
            if(isdigit(* l)){
                node = strtol (l, &l, 10);
                arraybello[i]->nodo = node;
                arraybello[i]->arcoPtr = malloc(sizeof(ArcoPtr));
                arraybello[i] = arraybello[i]->arcoPtr;
                printf("%d ", node);
            }
            else l++;
        }
        printf("\n");
        arraybello[i]->arcoPtr = NULL;
        i++;
    }
    arraybello[i] = NULL;

    for (int a =0; a<4 ; a++){
        for(int b =0; b<3; b++){
            printf("%d", arraybello[b]->nodo);
            arraybello[b] = arraybello[b]->arcoPtr;
        }
    }
}