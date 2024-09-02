// libro es228

#include <stdio.h>
void main()
{
    int codice;
    float paga;
    printf("Se vuoi calcolare la paga di un manager inserisci il codice paga 1,\nse di un lavoratore a ore inserisci il 2,\nse di un lavoratore a provvigione inserisci il 3\ne se di un lavoratore a cottimo inserisci il 4.\nInserisci il codice paga: ");
    scanf("%d", &codice);

    switch (codice){
	case 1 : 
        printf("Inserisci la paga settimanale del manager: ");
        scanf("%f", &paga);
        printf("Sto tizio guadagnera' %.2f dollari", paga);
		break;

	case 2 : 
        printf("Inserisci il numero di ore svolte dal lavoratore a ore: ");
        int ore;
        scanf("%d", &ore);
        printf("Inserisci la paga all'ora del lavoratore a ore: ");
        scanf("%f", &paga);

        if (ore>=40){
            ore = ore-40;
            printf("Sto tizio guadagnera' %.2f dollari piu' %.2f dollari di straordinari", 40*paga, (ore*paga)*1.5);
        }
        else {
            printf("Sto tizio guadagnera' %.2f dollari", ore*paga);
        }
		break;

	case 3 : 
        printf("Inserisci il quadagno lordo delle vendite del lavoratore a provvigione: ");
        scanf("%f", &paga);
        paga = (paga/100)*5.7;
        printf("Sto tizio guadagnera' 250.00 dollari piu' %.2f dollari", paga);
		break;

	case 4 : 
        printf("Inserisci il numero di articoli prodotti dal lavoratore a cottimo: ");
        int articoli;
        scanf("%d", &articoli);
        printf("Inserisci la quantita' fissa per ogni articolo prodotto dal lavoratore a cottimo: ");
        scanf("%f", &paga);
        printf("Sto tizio guadagnera' %.2f dollari", articoli*paga);
		break;

	default : printf("Inserisci un codice paga valido!");
		break;
    }
}