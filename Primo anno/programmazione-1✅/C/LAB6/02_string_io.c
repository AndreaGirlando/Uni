#include<stdio.h>
#define MAXLEN 255

int main() {
    // Vediamo diversi modi per leggere una stringa da standard input

    // allochiamo automaticamente una stringa di lunghezza (massima) MAXLEN=255
    char string[MAXLEN];

    // METODO 1: scanf
    printf("Inserisci la prima riga di testo: ");
    scanf("%s", string);

    printf("La stringa letta con scanf è: %s\n", string);
    // notiamo che il metodo sopra si "fermerà" quando incontra lo spazio
    // i caratteri non inseriti in string sono "in attesa" sullo standard input

    printf("Inserisci la seconda riga di testo: ");
    scanf("%s", string);
    printf("La seconda stringa letta con scanf è: %s\n", string);

    // rimuoviamoli iterando su getchar, che legge un carattere alla volta
    while(getchar()!='\n');

    printf("Inserisci la terza riga di testo: ");
    scanf("%s", string);
    printf("La terza stringa letta con scanf è: %s\n", string);

    while(getchar()!='\n'); //Serve per evitare che fgets prenda in input l'ultimo "a capo"

    // METODO 2: fgets
    printf("Inserisci una riga di testo con fgets: ");
    // Con fgets possiamo specificare quanti caratteri leggere
    // e da dove leggerli (stdin indica lo standard input - la tastiera)
    // leggiamo 9 caratteri dalla standard input stdin (la decima posizione è usata per il carattere di terminazione) e li mettiamo in string
    fgets(string, 10, stdin);

    printf("La stringa letta con fgets è: %s\n", string);
    // notiamo che questo metodo legge esattamente n-1 caratteri (n secondo parametro di fgets)

    while(getchar()!='\n'); // rimuoviamo i caratteri in eccesso da stdin

    // METODO 3: getchar
    // Possiamo leggere i caratteri "manualmente" fino al massimo di caratteri che possiamo inserire nella stringa
    printf("Inserisci una riga di testo: ");
    int i = 0;
    char c;
    while((c = getchar()) != '\n' && i < MAXLEN-1)
        string[i++] = c;

    string[i] = 0; // '\0'

    printf("La stringa letta con getchar è: %s\n", string);

    while(getchar()!='\n'); // rimuoviamo i caratteri in eccesso da stdin

    // Le funzioni sprintf e sscanf funzionano come printf e scanf
    // ma invece di leggere e scrivere da standard input e output
    // leggono e scrivono da e su stringa

    // sprintf è utile per ottenere una stringa formattata a partire dai valori di altre variabili
    int x = 2;
    float y = 3.5;
    sprintf(string, "x=%d - - y=%f", x, y); // il primo parametro è la string in output
    printf("Stringa formattata: %s\n", string);

    char str[] = "i risultati sono 1 e 5.2";

    // Analogamente sscanf permette di prelevare valori da una stringa formattata
    sscanf(str, "i risultati sono %d e %f", &x, &y);
    printf("Il valore di x è %d\nIl valore di y è %f\n", x, y);
}