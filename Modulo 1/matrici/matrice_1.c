/* Memorizzare in un array bidimensionale 5 per 5 tutti zeri tranne nelle celle della diagonale
principale dove memorizzare uno (non usare l’inizializzazione con parentesi grafe nemmeno per gli zeri) */

#include <stdio.h>

int main()
{
    int a[5][5];
    int i, j;
    for(i=0; i<5;i++){
        for (j=0; j<5; j++){
            if (i==j) {
                a[i][j]=1;
            }
            else a[i][j]=0;
        }
    }
    
    for(i=0; i<5;i++){
        for (j=0; j<5; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
