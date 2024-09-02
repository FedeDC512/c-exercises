#include <stdio.h>
#include <stdlib.h>

char **pciclestring(char *S);

void main (){
    char S[6]="Casale";
    printf("%u\n", S);
    //char **B = pciclestring(S);
    pciclestring(S);

}

char **pciclestring(char *S){

    char *trueS;
    trueS = S;
    char parola[6];

    for(int i=0; i<6; i++){
        if (i != 0) parola[i] = *S;
        else parola[5] = *S;
        *S++; 
        /*S = *(S+1);
        S+=1;
        if (i == 5) *S = parola[1];*/
    }
    
    for (int i=0; i<6; i++){
        printf("%c", *trueS);
        trueS+=1;
    }

}