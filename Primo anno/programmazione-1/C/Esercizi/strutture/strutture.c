#include <stdio.h>
/*
    *Di seguito introduciamo le strutture che utilizzano la point notation come un qualsiasi linguaggio ad oggetti
    ? Abbiamo 2 modi per accedere ai dati dentro una struttura
        ? Usando l'operatore di membro di struttura (es: card.face)
        ? Usando l'operatore di puntatore a struttura (es: card -> face)
        ! La seconda notazione diventa obbligatoria nelle funzioni dove le strutture sono passate per riferimento
    ? Le strutture possono essere passate sia per valore che per riferimento
        * Chiaramente come tutte le cose passate per valore rallentano il programma

*/
struct card {
    char *face;
    char *suit;
};
void modifyStruct(struct card *singleCard);
int main(){

    struct card carta = { "Faccia","Seme" };

    printf("%s - %s", carta.face,carta.suit);

    modifyStruct(&carta);

    printf("\n%s - %s", carta.face,carta.suit);

    typedef struct {
        char *nome;
        char *cognome;
        int age;
    } person;

    person persona = { "Andrea" , "Girlando" ,20};

    printf("\n%s %s %d\n",persona.nome, persona.cognome, persona.age);

    persona.cognome = "Garufi";

    printf("\n%s %s %d\n",persona.nome, persona.cognome, persona.age);

    return 0;
}

void modifyStruct(struct card *singleCard){
    singleCard->face = "Face";
}