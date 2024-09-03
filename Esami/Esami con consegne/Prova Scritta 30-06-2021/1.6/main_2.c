#include <stdio.h>
#include <stdlib.h> 

int **proximity(char ** S, int n){
    size_t i,j,k,l;
    int **caratteri = calloc(n, sizeof(char *));
    for(i = 0; i < n; i++){
        caratteri[i] = calloc(n, sizeof(char *));
        for(j=0; j < n; j++){
            if(S[i]!=NULL){
                for(k=0; S[i][k]!=NULL; k++){
                    for(l=0; S[j][l]!=NULL; l++){
                        if(S[i][k]==S[j][l]){
                            caratteri[i][j]++;
                        }
                    }
                }
            }
        }
    }
    return caratteri;
}

void main(){
    char * lista [2];
    char casta [6] ="casta";
    lista[0] = &casta;
    char cartello [9] ="cartello";
    lista[1] = &cartello;
    int ** i = proximity(lista, 2);
    printf("%d %d %d %d", i[0][0], i[0][1], i[1][0], i[1][1]);
}
