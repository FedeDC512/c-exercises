/* Scrivere un programma che acquisisce una sequenza di caratteri terminata
dal carattere 'invio' e stabilisce se la sequenza è palindroma oppure no
(per esempio, "ada" è palindroma perché si legge allo stesso modo sia da
destra sia da sinistra) */

#include <stdio.h>
int main()
{
    int n=5, b=0;
    char a[5]={"eevee"};
    for(int i=0,j=n-1;i<(n/2)+1 && j>(n/2)-1;i++,j--){

        if (a[i]==a[j]){
            b=b+1;

        }
    }
    if(n%2==0 && b==n/2)printf("la parola è palindroma");
    else if(n%2==1 && b==(n/2)+1)printf("la parola è palindroma");
    else   printf("la parola non è palindroma");

    return 0;
}