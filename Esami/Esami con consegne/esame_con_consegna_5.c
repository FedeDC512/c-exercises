/* Scrivere la funzione int * TrovaMaxParziale(int * a,int N); che ricevuto in ingresso un vettore di
N interi, restituisca un vettore di interi con i massimi relativi del vettore. I massimi relativi hanno la
caratteristica di avere l'elemento precedente e successivo minori di esso. Per il primo elemento vericare
che il successivo sia minore, mentre per l'ultimo elemento vericare solo che il precedente sia minore.
Es.:
input: [11,22,33,44,5,66,7,88,99,10,202]
output: [44,66,99,202] */

#include <stdio.h>
#include <stdlib.h>

int * TrovaMaxParziale(int *a, int N);

void main()
{

    int N;

    printf("Inserisci il numero di valori che vuoi inserire: ");
    scanf("%d", &N);

    int a[N];
    int *c;

    printf("Inserisci %d valori:\n", N);

    
    for(int i=0; i<N-1; i++){
        scanf("%d\n", &a[i]);
    }


    c = TrovaMaxParziale(a, N);

    for(int i=0; i<N; i++){
        printf("%d ", *(c+i));
    } 

}

int * TrovaMaxParziale(int *a, int N)
{
    int *b=(int *) calloc(N, sizeof(int));
    int cb=0;

    for(int i=0; i<N; i++){
	    if (i == 0)
        {
            if (*a >= *(a+1)){
                b[cb] = *a;
                cb += 1;
            };
        }
        else if (i == N-1)
        {
            if (*a >= *(a-1)){
                b[cb] = *a;
                cb += 1;
            };
        }
        else if (*a >= *(a+1) && *a >= *(a-1))
        {
	        b[cb] = *a;
            cb += 1;
        };
        *a ++;
    }
    return b;
}