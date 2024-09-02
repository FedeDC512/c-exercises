#include <stdio.h>
#include <stdlib.h>

struct persona{
    struct ingrediente *likes;
    struct ingrediente *dislikes;
    struct persona *next; //nextpersona
};

struct ingrediente{
    char ing[15];
    struct ingrediente *next;
};

typedef struct persona Persona;
typedef struct persona *PersonaPtr;
typedef struct ingrediente Ingrediente;
typedef struct ingrediente *IngredientePtr;

void main (){
    PersonaPtr inizio = malloc(sizeof(Persona));
    PersonaPtr scorripersone = inizio;
    int n = 3; //prendo in inpunt il primo numero e lo salvo in n
    for(int i = 0 ; i < n ; i++){

        int numinglike = 2;// prendo primo elemento di nextline del file
        scorripersone->likes = malloc(sizeof(Ingrediente));
        IngredientePtr scorriing = scorripersone->likes;
        IngredientePtr mettifineing = scorriing;

        for(int j = 0 ; j < numinglike ; j++){
            scorriing->ing[15] = "parola";//prendi parola nella stessa riga
            mettifineing = scorriing;
            scorriing = scorriing->next;
        }
    }
}
