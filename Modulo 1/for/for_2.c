#include <stdio.h>

int main()
{
    int i, a[5];
    printf("Inserisci i 5 numeri:\n");
    for(i=0; i<5; i++){
        scanf("%d", &a[i]);
    }
    for(i=0; i<5; i++){
    printf("Il numero in posizione %d e' %d\n", i, a[i]);
    }
    
    return 0;
}