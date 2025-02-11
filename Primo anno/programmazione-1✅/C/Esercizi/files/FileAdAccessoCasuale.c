#include <stdio.h>
#include <stdlib.h>

/*
    ?fwrite(size_t fwrite( const void* buffer, size_t size, size_t count,FILE* stream );)
        buffer 	- 	pointer to the first object in the array to be written
        size 	- 	size of each object
        count 	- 	the number of the objects to be written
        stream 	- 	pointer to the output stream
    ?fread size_t fread( void *buffer, size_t size, size_t count,FILE *stream );
        buffer 	- 	pointer to the array where the read objects are stored
        size 	- 	size of each object in bytes
        count 	- 	the number of the objects to be read
        stream 	- 	the stream to read
*/
// Definizione di una struttura semplice
typedef struct {
    int id;
    char nome[50];
    float salario;
} Dipendente;

int main() {
    // Nome del file
    const char *nomeFile = "dipendenti.dat";

    // Scrittura dei dati su file
    {
        FILE *file = fopen(nomeFile, "wb"); // Apertura in modalità scrittura binaria
        if (!file) {
            perror("Errore nell'apertura del file");
            return 1;
        }

        Dipendente dipendenti[2] = {
            {1, "Mario Rossi", 2500.50},
            {2, "Luigi Bianchi", 3000.75}
        };

        // Scrittura dell'array di strutture nel file
        size_t elementiScritti = fwrite(dipendenti, sizeof(Dipendente), 2, file);
        if (elementiScritti != 2) {
            perror("Errore nella scrittura dei dati");
            fclose(file);
            return 1;
        }

        fclose(file);
        printf("Dati scritti con successo su %s.\n", nomeFile);
    }

    // Lettura dei dati dal file
    {
        FILE *file = fopen(nomeFile, "rb"); // Apertura in modalità lettura binaria
        if (!file) {
            perror("Errore nell'apertura del file");
            return 1;
        }

        Dipendente dipendentiLetti[2];

        // Lettura dei dati dal file
        size_t elementiLetti = fread(dipendentiLetti, sizeof(Dipendente), 2, file);
        if (elementiLetti != 2) {
            perror("Errore nella lettura dei dati");
            fclose(file);
            return 1;
        }

        fclose(file);

        // Stampa dei dati letti
        printf("Dati letti dal file:\n");
        for (int i = 0; i < 2; i++) {
            printf("ID: %d, Nome: %s, Salario: %.2f\n",
                   dipendentiLetti[i].id,
                   dipendentiLetti[i].nome,
                   dipendentiLetti[i].salario);
        }
    }

    return 0;
}



