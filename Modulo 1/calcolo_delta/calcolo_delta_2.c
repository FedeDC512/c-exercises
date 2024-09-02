/* Scrivere un programma che, dati in input tre numeri interi a,b,c,
risolva l’equazione di secondo grado ax2+bx+c=0, ovvero ne calcoli e
visualizzi le soluzioni (se esistono). La radice quadrata in C si calcola
tramite la funzione sqrt della libreria <math.h> */

#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c, delta;
    float sol1, sol2;

    printf("Inerisci i tre numeri dell'equazione: ");
    scanf("%d %d %d", &a, &b, &c);

    delta=(b*b)-(4*a*c);
    printf("Il delta e' %d\n", delta);

    if (delta==0){
        printf("L'equazione ha una soluzione ed e' ");
        sol1=(-b)/(2*a);
        printf("%f", sol1);
    }
    else if (delta>0){
        printf("L'equazione ha due soluzioni che sono ");
        sol1=(-b+sqrt(delta))/(2*a);
        sol2=(-b-sqrt(delta))/(2*a);
        printf("%f e %f", sol1, sol2);
    }
    else 
        printf("L'equazione non ha soluzioni reali");

}