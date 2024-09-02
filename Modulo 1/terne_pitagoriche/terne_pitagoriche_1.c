/* lez19es2
Dato n intero dato in input, visualizzare le terne pitagoriche a,b,c,
ovvero tutte le triple a,b,c di interi minori di n tali che a^2+b^2=c^2. */

#include <stdio.h>
#include <math.h>
void main()
{
    int n, a, b, c;
    printf("Inserisci il valore: ");
    scanf("%d",&n);
    a=1, b=n;
    while (a!=n && b!=1){
        c=sqrt(a*a+b*b);
        if (a*a+b*b==c*c) printf("%d %d %d\n", a, b, c);
        a=a+1, b=b-1;
    }
}