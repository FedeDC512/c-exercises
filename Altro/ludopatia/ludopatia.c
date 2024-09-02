#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
    int numero = 0;

    int contaritardoneri = 0;
    int contaritardorossi = 0;          
    int contaritardopari = 0;
    int contaritardodispari = 0;
    int contaritardodozzina1 = 0;
    int contaritardodozzina2 = 0;
    int contaritardodozzina3 = 0;
    int contaritardoriga1 = 0;
    int contaritardoriga2 = 0;
    int contaritardoriga3 = 0;
    int contaritardopm = 0;
    int contaritardosm = 0;
    int rossi[18] = {1,3,5,9,7,12,14,16,18,19,21,23,25,27,30,32,34,36};
    int neri[18] = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};
    printf("Inserire il numero uscito: ");
    scanf("%d", &numero);
    while(numero >= -1){
        if(numero <= 36 && numero > 0) {
            if(numero%2 == 0){
                contaritardodispari++;
                contaritardopari = 0;
            } else{
                contaritardopari++;
                contaritardodispari = 0;
            }
            for(int i=0 ; i < 19 ; i++){
                if(numero == rossi[i]){
                    contaritardoneri++;
                    contaritardorossi = 0;
                    break;
                } else if(numero == neri[i]){
                    contaritardorossi++;
                    contaritardoneri = 0;
                    break;               
                }
            }
           /* if(numero == 1,3,5,9,7,12,14,16,18,19,21,23,25,27,30,32,34,36){
                contaritardoneri++;
                contaritardorossi = 0;
            } else{
                contaritardorossi++;
                contaritardoneri = 0;
            }
            */
            if(numero <= 19){
                contaritardosm++;
                contaritardopm = 0;
            } else{
                contaritardopm++;
                contaritardosm = 0;
            }
            
            if(numero <= 12){
                contaritardodozzina2++;
                contaritardodozzina3++;
                contaritardodozzina1 = 0;
            } else if(numero <= 24){
                contaritardodozzina1++;
                contaritardodozzina3++;
                contaritardodozzina2 = 0;
            } else{
                contaritardodozzina2++;
                contaritardodozzina1++;
                contaritardodozzina3 = 0;
            }
            
            if(numero%3 == 0){
                contaritardoriga2++;
                contaritardoriga3++;
                contaritardoriga1 = 0;
            } else if(numero%3 == 2){
                contaritardoriga1++;
                contaritardoriga3++;
                contaritardoriga2 = 0;
            } else if(numero%3 == 1){
                contaritardoriga1++;
                contaritardoriga2++;
                contaritardoriga3 = 0;
            }
            
            printf("\n%d e' il ritardo sui pari\n", contaritardopari);
            printf("%d e' il ritardo sui dispari\n", contaritardodispari);
            printf("%d e' il ritardo sui neri\n", contaritardoneri);
            printf("%d e' il ritardo sui rossi\n", contaritardorossi);
            printf("%d e' il ritardo sulla prima dozzina\n", contaritardodozzina1);
            printf("%d e' il ritardo sulla seconda dozzina\n", contaritardodozzina2);
            printf("%d e' il ritardo sulla terza dozzina\n", contaritardodozzina3);
            printf("%d e' il ritardo sulla prima meta'\n", contaritardopm);
            printf("%d e' il ritardo sulla seconda meta'\n", contaritardosm);
            printf("%d e' il ritardo sulla prima riga '3,6,9...',\n", contaritardoriga1);
            printf("%d e' il ritardo sulla seconda riga '2,5,8...'\n", contaritardoriga2);
            printf("%d e' il ritardo sulla terza riga '1,4,7...'\n\n", contaritardoriga3);
            printf("Inserire il numero uscito: ");
        } else if(numero == 0){
            contaritardoneri++;
            contaritardorossi++;
            contaritardopari++;
            contaritardodispari++;
            contaritardodozzina1++;
            contaritardodozzina2++;
            contaritardodozzina3++;
            contaritardoriga1++;
            contaritardoriga2++;
            contaritardoriga3++;
            contaritardopm++;
            contaritardosm++;
            printf("\n%d e' il ritardo sui pari\n", contaritardopari);
            printf("%d e' il ritardo sui dispari\n", contaritardodispari);
            printf("%d e' il ritardo sui neri\n", contaritardoneri);
            printf("%d e' il ritardo sui rossi\n", contaritardorossi);
            printf("%d e' il ritardo sulla prima dozzina\n", contaritardodozzina1);
            printf("%d e' il ritardo sulla seconda dozzina\n", contaritardodozzina2);
            printf("%d e' il ritardo sulla terza dozzina\n", contaritardodozzina3);
            printf("%d e' il ritardo sulla prima meta'\n", contaritardopm);
            printf("%d e' il ritardo sulla seconda meta'\n", contaritardosm);
            printf("%d e' il ritardo sulla prima riga '3,6,9...',\n", contaritardoriga1);
            printf("%d e' il ritardo sulla seconda riga '2,5,8...'\n", contaritardoriga2);
            printf("%d e' il ritardo sulla terza riga '1,4,7...'\n\n", contaritardoriga3);
            printf("Inserire il numero uscito: ");
        }
        else if (numero == -1){
            contaritardoneri = 0;
            contaritardorossi = 0;          
            contaritardopari = 0;
            contaritardodispari = 0;
            contaritardodozzina1 = 0;
            contaritardodozzina2 = 0;
            contaritardodozzina3 = 0;
            contaritardoriga1 = 0;
            contaritardoriga2 = 0;
            contaritardoriga3 = 0;
            contaritardopm = 0;
            contaritardosm = 0;
            printf("Hai correttamente resettato il programma");
            printf("\n%d e' il ritardo sui pari\n", contaritardopari);
            printf("%d e' il ritardo sui dispari\n", contaritardodispari);
            printf("%d e' il ritardo sui neri\n", contaritardoneri);
            printf("%d e' il ritardo sui rossi\n", contaritardorossi);
            printf("%d e' il ritardo sulla prima dozzina\n", contaritardodozzina1);
            printf("%d e' il ritardo sulla seconda dozzina\n", contaritardodozzina2);
            printf("%d e' il ritardo sulla terza dozzina\n", contaritardodozzina3);
            printf("%d e' il ritardo sulla prima meta'\n", contaritardopm);
            printf("%d e' il ritardo sulla seconda meta'\n", contaritardosm);
            printf("%d e' il ritardo sulla prima riga '3,6,9...'\n", contaritardoriga1);
            printf("%d e' il ritardo sulla seconda riga '2,5,8...'\n", contaritardoriga2);
            printf("%d e' il ritardo sulla terza riga '1,4,7...'\n\n", contaritardoriga3);
            printf("Inserire il numero uscito: ");
        }
        else printf("Ri-inserisci un numero minore di 36: ");
        scanf("%d", &numero);
    }
}