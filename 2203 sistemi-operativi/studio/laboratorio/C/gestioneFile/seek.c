/**
 * tenta di effetture un seek sullo standard input: il risultato atteso dipende
 * dalla natura associato a tale canale:
 *  - in una invocazione ordinaria, il canale è associato al terminale e
 *    pertanto l'esecuzione di `lseek` è destinata a fallire
 *  - in una invocazione in cui lo standard input è associato ad un file (ad
 *    esempio `./a.out < meme.txt`) il seek diventa possibile e non
 *    genera errori
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// STDIN_FILENO costante che definisce il file "STDIN"
int main(int argc, char *argv[]) {
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
        printf("impossibile fare seek sullo standard input\n");
    else
        printf("seek correttamente applicato allo standard input\n");

    exit(EXIT_SUCCESS);
}