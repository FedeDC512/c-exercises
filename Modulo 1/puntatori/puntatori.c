// Dichiara due variabili intere e punta alle variabili con due puntatori

#include <stdio.h>

int main()
{
    int a=0, b=0;
    int *ap, *bp;
    ap=&a;
    bp=&b;
    printf("Insrisci il primo numero: ");
    scanf("%d", &a);
    printf("Insrisci il secondo numero: ");
    scanf("%d", &b);
    printf("%d\n",ap);
    printf("%d",bp);
    
    return 0;
}