/* Create una lista di 30 parole, frasi e nomi di aziende che si trovano comunemente nei mes-
saggi di phishing. Assegnate un punteggio a ognuno di essi valutando voi stessi il livello di
probabilità che facciano parte di un messaggio di phishing (ad esempio: un punto se è
leggermente probabile, due punti se è moderatamente probabile o tre punti se è altamente
probabile). Scrivete un programma che esegua la scansione di un file di testo per questi
termini e frasi. Ogni volta che una parola chiave o una frase ricorre nel file di testo, aggiun-
gete il punteggio assegnato ai punti totali per quella parola o frase. Per ogni parola chiave
o frase trovata, stampate una riga con la parola o la frase, il numero delle volte che ricorre
e il punteggio totale. Poi mostrate il punteggio totale per l’intero messaggio. Il vostro pro-
gramma assegna un punteggio totale alto ad alcune vere e-mail di phishing che avete rice-
vuto? Assegna un punteggio totale alto ad alcune e-mail legittime che avete ricevuto? */

#include <stdio.h>

int main()
{
    FILE *punta_alice;
    FILE *punta_nuovo;

    char nome[50];
    char parola[50];

    printf("Inserisci il nome da sostituire: ");
    gets(nome);

    if ((punta_alice = fopen("alice.txt", "r")) == NULL) {
        puts("Il file non puo' essere aperto, scemo");
    }
    else {
        if ((punta_nuovo = fopen("nuovo.txt", "w")) == NULL) {
            puts("Il file non puo' essere aperto, scemo");
        }
        else {

            fscanf(punta_alice, "%s", parola);
            while (!feof(punta_alice) ) {
                
                if(parola[0]=="A"){
                    if(parola[1]=="l"){
                        if(parola[2]=="i"){
                            if(parola[3]=="c"){
                                if(parola[4]=="e"){
                                    fprintf("%s ", nome);
                                }
                            }
                        }
                    }
                }
                
                else{
                    fprintf(punta_nuovo, "%s ", parola);
                    fscanf(punta_alice, "%s", parola); 
                }
            }

        
        }

    fclose(punta_alice);
    fclose(punta_nuovo);
    }
}
