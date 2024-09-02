/* lez15es5
Scrivete un programma che, dai due interi a e b in input, 
verifica se il più grande è quadrato o cubo del più piccolo. */

#include <stdio.h>
void main()
{
    int a, b;
    printf("Inserisci i due numeri A e B\n");
    scanf("%d %d",&a, &b);

    if (a>b){
        if (a==b*b*b) printf("%d e' il cubo di %d", a, b);
        else if (a==b*b) printf("%d e' il quadrato di %d", a, b);
        else printf("%d non e' il quadrato o il cubo di %d", a, b);
    }
    else {
        if (b==a*a*a) printf("%d e' il cubo di %d", b, a);
        else if (b==a*a) printf("%d e' il quadrato di %d", b, a);
        else printf("%d non e' il quadrato o il cubo di %d", b, a);
    }
}