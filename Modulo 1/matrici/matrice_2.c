// Verificare se una matrice 8×8 di interi è una “scacchiera” ovvero se vi sono presenti solo 0 e 1 alternati tra loro.

#include <stdio.h>

int main()
{
    int a[8][8];
    int i, j, b=0;
    
    printf("Inserisci la matrice: ");
    for(i=0; i<8;i++){
        for (j=0; j<8; j++){
            scanf("%d ", &a[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<8;i++){
        for (j=0; j<8; j++){
            if(a[i][j]!=(i+j)%2){
                b=1;
            }
        }
    }
    
    if(b==1){
        printf("La matrice e' a scacchiera\n");
    }
    else printf("La matrice non e' a scacchiera\n");

    printf("La matrice completa e':\n");
    for(i=0; i<8;i++){
        for (j=0; j<8; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}


