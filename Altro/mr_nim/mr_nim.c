/* Il gioco inizia con 10 biglie in gioco
L'obbiettivo consiste nel togliere l'ultima biglia, chi lascia l'ultima vinca il gioco.
Ad ogni turno puoi scegliere se togliere una, due o tre biglie
La sfida è contro il computer, come umano puoi iniziare per primo */

#include <stdio.h>

void main()
{

int tot=13;
int player;
char tutorial;

printf("Il professor Nim ti da' il bevenuto, preparati a giocare!\n");

printf("Conosci gia' le regole del gioco? Rispondi con s/n\n");
scanf("%c", &tutorial);

    switch (tutorial){
        case 's' : 
        printf("Bene iniziamo, il prof Nim non vede l'ora di sfidarti!\n");
        break;

        case 'n' : 
        printf("Il \"NIM\" nasce come un gioco matematico per due giocatori.\n");
        printf("Il gioco inizia con 13 biglie in serie.\n");
        printf("Ad ogni turno ogni giocatore sceglie se togliere una, due o tre biglie.\n");
        printf("L'obbiettivo consiste nel lasciare l'ultima biglia, vince chi lascia una biglia come ultima mossa all'altro giocatore.\n");
        printf("In questa versione giocherai contro il pc, rappresentato dal prof Nim.\n");
        printf("Fai tu la prima mossa!\n");
        break;

        default : printf("Il prof Nim e' intelligente, ma non crede di aver capito cosa intendi.\nDara' per scontato che tu sia pronto a sfidarlo!\n");
        break;
    }
    
printf("Il gioco inizia con 13 biglie in gioco\n");
for(int i=0; i<tot; i++){
	printf("* ");
}

while(tot>1){
    printf("\nQuante biglie vuoi togliere? ");

    scanf("%d", &player);

        switch (player){
        case 1 : 
            tot=tot-1;
            printf("\nHai scelto di togliere una biglia, allora il prof Nim ne toglie tre.\n");
            tot=tot-3;
            printf("Sono rimaste %d biglie\n", tot);
            for(int i=0; i<tot; i++){
            printf("* ");
            }
            break;

        case 2 : 
            tot=tot-2;
            printf("\nHai scelto di togliere due biglie, anche il prof Nim ne toglie due.\n");
            tot=tot-2;
            printf("Sono rimaste %d biglie\n", tot);
            for(int i=0; i<tot; i++){
            printf("* ");
            }
            break;

        case 3 : 
            tot=tot-3;
            printf("\nHai scelto di togliere tre biglie, bene, il prof Nim ne toglie una.\n");
            tot=tot-1;
            printf("Sono rimaste %d biglie\n", tot);
            for(int i=0; i<tot; i++){
            printf("* ");
            }
            break;

        default : 
            printf("\nPuoi scegliere di togliere solo una, due o tre biglie!\n");
            break;

        }
    }
    printf("\nOh no, il prof Nim ti ha lasciato solo una biglia da prendere.\nHai perso!\n");
    printf("Inserisci una lettera per uscire dal gioco (metto sta cosa per comodita'): ");
    scanf("%d", &tutorial);
}