#include <stdio.h>
#include <stdlib.h> 

// Federico
int **proximity(char ** S, int n){
    int m[n][n];
    int i,j;
    for(j=0; j<n; j++){
        for(i=0; i<n; i++){
            int count = 0;
            int *ind1;
            int *ind2;
            int ind1 = *S[i];
            int ind2 = *S[j];
            for(ind1,ind2; *ind1!='\0' || *ind2!='\0'; ind1++, ind2++){
                if(*ind1==*ind2){
                    count++;
                }
            }
            m[i][j]=count;
        }
    }
    return m; 
}

void main(){
    char * lista [2];
    char casta [6] ="casta";
    lista[0] = &casta;
    char cartello [9] ="cartello";
    lista[1] = &cartello;
    int ** i = proximity(lista, 2);
   
   char S[5][10] = {
        "ciao",
        "prova",
        "casta",
        "lol",
        "cartello"
    };
    int **D;
    D = proximity(S, 5);
    printf("%d %d %d %d", D[0][0], D[0][1], D[1][0], D[1][1]);

}
