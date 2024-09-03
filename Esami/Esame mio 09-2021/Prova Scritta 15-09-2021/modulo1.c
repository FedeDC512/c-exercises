#include <stdio.h>
#include <stdlib.h>

void simmetriche (double ***Z, int n, int m, int *ns);
int simmsing (double matrice, int lunghezza);

void main(){

}

void simmetriche (double ***Z, int n, int m, int *ns){
    (*ns)=0;
    for(int i=0; i<n; i++){
        (*ns)=simmsing((*Z)[n], m) ? (*ns) : (*ns)++ ;
    }
}

int simmsing (double matrice, int lunghezza){
    int simm = 0;
    for(int i=0; i<lunghezza; i++){
        for (int j=0; j<lunghezza; j++){
            if (matrice[i][j] != matrice[j][i]){
                simm++;
            }
        }
    }
}