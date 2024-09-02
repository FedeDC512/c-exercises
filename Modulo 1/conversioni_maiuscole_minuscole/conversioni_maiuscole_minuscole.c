/* lez16es12
Scrivere un programma che dato in input una lettera dell’alfabeto, 
trasforma tale lettera in maiuscolo se è minuscola, o in minuscolo se è maiuscola. */

#include <stdio.h>
void main() {
    char a;
    printf("Inserisci il carattere\n");
    scanf("%c", &a);
    if (a>=65 && a<=90) a=a+32;
    else if (a>=97 && a<=122) a=a-32;
    printf("La lettera e' %c", a);
}