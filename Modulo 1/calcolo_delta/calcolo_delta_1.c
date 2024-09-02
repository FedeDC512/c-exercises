/* lez15es3
Scrivere un programma che, dati in input tre numeri interi a,b,c, 
risolva l’equazione di secondo grado ax2+bx+c=0, ovvero ne calcoli e visualizzi le soluzioni (se esistono). 
La radice quadrata in C si calcola tramite la funzione sqrt della libreria <math.h>. */

#include <stdio.h>
#include <math.h>

void main()
{
    int a, b, c, delta;
    float sol1, sol2;
    printf("Inserisci i tre numeri\n");
    scanf("%d %d %d",&a, &b, &c);
    delta = (b*b)-(4*a*c);
    if(delta>0){
    printf("La prima soluzione e' %f\n", (-b + sqrt(delta))/(2*a));
    printf("La seconda soluzione e' %f", (-b - sqrt(delta))/(2*a));
    }
    else if(delta==0){
    printf("La soluzione e' %d", -b/(2*a));
    }
    else printf("Non ci sono soluzioni");
}
