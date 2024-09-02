#include <stdio.h>

void main()
{
    int S[9]={1,2,3,4,5,6,7,8,9};
    int i;
    int **N= (int **) malloc (3*sizeof(int*));
    for (i=0;i<3;i++) {
        N[i]=S+i*3;
    }
    //for (i=0;i<3;i++) printf("%d \n",N[i][1]);

    for (int a=0; a<3; a++) {
        for (int b=0; b<3; b++){
            printf("%d ", N[a][b]);
        }
        printf("\n");
    }
}