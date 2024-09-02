#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void turnoplayer(int *mat[3][3]);
void turnocpu(int *mat[3][3]);

void main(){

srand(time(NULL));
int *mat [3][3] = {0};
printf ("Il giocatore avrà come simbolo 1, la cpu avra' come simbolo 2");
//void (*scelte[2])(int [3][3]) = {turnoplayer,turnocpu};

for(int i = 0 ; i<2 ; ++i){
    for (int i = 0; i<3 ; i++){
        printf("\n");
        for(int j = 0; j<3 ; j++){
        printf("%d", mat[i][j]);
        }
    }
turnoplayer(mat);
turnocpu(mat);
printf("\n");
}
}

void turnoplayer(int *mat[3][3]){
    printf("\nIn che riga vuoi mettere il tuo segno?");
    int a = 0;
    scanf("%d", &a);
    a -= 1;
    printf("In che colonna vuoi mettere il tuo segno?");
    int b = 0;
    scanf("%d", &b);
    b -= 1;
    mat[a][b] = 1;
}
void turnocpu(int *mat[3][3]){
    int a = 0;
    int b = 0;
    a = (rand() %2);
    b = (rand() %2);
    //printf("%d", mat[a][b]);
    while (mat[a][b] == 1||2){
        a = (rand() %2);
        b = (rand() %2);
        printf("%d %d", a, b);
    }
    mat[a][b] = 2;
    printf("%d", mat[a][b]);
}