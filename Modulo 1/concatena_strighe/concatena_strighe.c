/* Scrivere un programma C che legge due
stringhe da tastiera, le concatena in un’unica
stringa e stampa la stringa così generata */

#include <stdio.h>
#include <stdlib.h>
void main (){

    int n=0;
    char frase1[100], frase2[100];
    printf("Inserisci la prima stringa: ");
    gets(frase1);
    printf("Inserisci la seconda stringa: ");
    gets(frase2);

    int i1=0;
    while (frase1[i1]!='\0') i1++;
    int i2=0;
    while (frase2[i2]!='\0') i2++;

    char *c=(char*)calloc(i1+i2,sizeof(char));

    for(int j=0 ; j<i1 ; j++) c[j]=frase1[j];
    for(int j=0 ; j<i2 ; j++) c[j+i1]=frase2[j];

    puts(c);

}