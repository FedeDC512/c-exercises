/* lez16es11
Scrivere un programma che prende in input un carattere e verifica se 
si tratta di un carattere numerico (cifra da zero a 9), di una 
consonante o di una vocale come lettere minuscole. */

#include <stdio.h>
void main() {
    char a;
    printf("Inserisci il carattere\n");
    scanf("%c", &a);
    if (a>=65 && a<=90) a=a+32;
    if (a>=48 && a<=57) printf("Il valore inserito e' un carattere numerico");
    else if (a==97 || a==101 || a==105 || a==111 || a==117) printf("Il valore inserito e' una vocale");
    else if (a>=97 && a<=122) printf("Il valore inserito e' una consonante");
}