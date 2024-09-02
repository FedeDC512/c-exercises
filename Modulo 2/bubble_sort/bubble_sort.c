/* Scrivere un programma c che prende in ingresso da tastiera una serie di 20 
numeri interi. I numeri immessi devono essere salvati all’interno di un array.
Una volta terminata l’immissione. Stampare a video l’array e successivamente 
ordinare l’array in ordine crescente. Scrivere delle funzioni c che permettano di
effettuare l’ordinamento secondo gli algoritmi selection sort e bubble sort. Infine 
stampare a video l’array ordinato su una sola riga e i passi necessari per 
effettuare l’ordinamento con i due differenti algoritmi */

#include <stdio.h>
#include <time.h>

void bubbleSort (int *sPtr);

void main (){
    srand(time(NULL));

    int numeri[20];

    printf("Inserisci 20 numeri:\n");
    for (int i=0 ; i<20 ; i++){
        //scanf("%d", numeri[i]);
        numeri[i]= 1 + (rand() % 100);
        printf("%d ", numeri[i]);
    }
    printf("\n");
    
    bubbleSort(numeri);

    printf("\n");

    for (int i=0 ; i<20 ; i++){
        printf("%d ", numeri[i]);
    }
}

void bubbleSort (int *sPtr){
    int temp;
    int *truePtr;
    truePtr=sPtr;

    for (int pass = 0; pass < 20; ++pass){

        for (int i = 0; i < 20; ++i){

            if (*sPtr>*(sPtr+1)){
                temp=*sPtr;
                *sPtr=*(sPtr+1);
                *(sPtr+1)=temp;
            }
            sPtr+=1;
        }
        sPtr=truePtr;
    }

    for (int i = 0; i < 20 ; ++i){
        printf("%d ", *truePtr);
        truePtr+=1;
    }

}
