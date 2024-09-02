/* In questo esercizio progetterete una struttura “iniziale” HealthProfile per
una persona. I membri della struttura devono comprendere il nome, il cognome, il sesso,
la data di nascita (consistente in attributi separati per il giorno, il mese e l’anno di nascita),
l’altezza e il peso della persona. Il vostro programma deve avere una funzione che riceve
questi dati e li utilizza per impostare i membri di una variabile di tipo HealthProfile. Il
programma deve includere anche le funzioni che calcolano e restituiscono l’età del pazien-
te in anni, la massima frequenza cardiaca (220 meno la vostra età), l’intervallo della 
frequenza cardiaca normale (intervallo del 50–80 % della vostra massima frequenza cardiaca) 
e l’indice di massa corporea (vedi tabella). Il programma deve richiedere le informazioni di 
una persona, creare una variabile di tipo HealthProfile per essa e stampare le informazioni 
contenute in quella variabile (compreso il nome della persona, il cognome, il sesso, la data 
di nascita, l’altezza e il peso), quindi calcolare e stampare l’età della persona in anni, 
il BMI, la massima frequenza cardiaca e l’intervallo della frequenza cardiaca normale. 

              peso (Kg)
BMI =             /
      altezza (m) * altezza (m)

VALORI del BMI :
Sottopeso: meno di 18.5
Normale: tra 18.5 e 24.9
Sovrappeso: tra 25 e 29.9
Obeso: 30 o oltre */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int eta (int giorno, int mese, int anno);
int maxcard (int eta);
double normcardmin (int maxcard);
double normcardmax (int maxcard);
double bmi (double peso, double altezza);

struct HealthProfile {
    char nome[20];
    char cognome[20];
    char sesso;
    int giorno;
    int mese;
    int anno;
    float altezza;
    float peso;
};

void main()
{

    int etap;
    int maxcardp;
    double normcardminp;
    double normcardmaxp;
    double bmip;

    struct HealthProfile Persona;

    printf("Inserisci il tuo nome: ");
    gets(Persona.nome);

    printf("Inserisci il tuo cognome: ");
    gets(Persona.cognome);

    printf("Inserisci il tuo sesso con m/f: ");
    scanf("%c", &Persona.sesso);

    printf("Inserisci il tuo giorno di nascita: ");
    scanf("%d", &Persona.giorno);

    printf("Inserisci il tuo mese di nascita: ");
    scanf("%d", &Persona.mese);

    printf("Inserisci il tuo anno di nascita: ");
    scanf("%d", &Persona.anno);

    printf("Inserisci la tua altezza in m: ");
    scanf("%f", &Persona.altezza);

    printf("Inserisci il tuo peso in kg: ");
    scanf("%f", &Persona.peso);

    etap = eta(Persona.giorno, Persona.mese, Persona.anno);
    maxcardp = maxcard(etap);
    normcardminp = normcardmin(maxcardp);
    normcardmaxp = normcardmax(maxcardp);
    bmip = bmi(Persona.peso, Persona.altezza);

    printf("\nCartella clinica di %s %s\n", Persona.cognome, Persona.nome);

    switch (Persona.sesso){
        case 'm':printf("Sesso: maschio\n"); break;
        case 'f':printf("Sesso: femmina\n"); break;
        default:printf("Sesso: %c\n", Persona.sesso); break;
    }
    printf("Eta': %d anni\n", etap);
    printf("Nato il %d/%d/%d\n", Persona.giorno, Persona.mese, Persona.anno);

    printf("Peso: %.2f kg\n", Persona.peso);
    printf("Altezza: %.2f m\n", Persona.altezza);

    printf("Massima frequenza cardiaca: %d bpm\n", maxcardp);
    printf("Intervallo della frequenza cardiaca normale: %.2f-%.2f bpm\n", normcardminp, normcardmaxp);

    printf("Indice di massa corporea: %.2f\n", bmip);

    if (bmip<18.5) printf("In base al BMI, il paziente e' sottopeso");
        else if (bmip>=18.5 && bmip<=24.9) printf("In base al BMI, il paziente e' normopeso");
        else if (bmip>=25 && bmip<=29.9) printf("In base al BMI, il paziente e' sovrappeso");
        else printf("In base al BMI, il paziente e' obeso");

    printf("\n");
    system("pause");
}

int eta(int giorno, int mese, int anno)
{
time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    int cd = local->tm_mday;
    int cm = local->tm_mon + 1;
    int cy = local->tm_year + 1900;

    printf("\nData odierna: %d/%d/%d", cd, cm, cy);

    int eta;
    if (mese>cm) eta = cy - anno - 1;
    else if (mese==cm)
    {
        if (giorno>cd) eta = cy - anno - 1;
        else eta = cy - anno;
    }
    else eta = cy - anno;

    return eta;
}

int maxcard (int eta)
{
    return 220-eta;
}

double normcardmin (int maxcard)
{
    return (50 * maxcard)/100;
}

double normcardmax (int maxcard)
{
    return (80 * maxcard)/100;
}

double bmi (double peso, double altezza)
{
    return peso / (altezza*altezza);
}