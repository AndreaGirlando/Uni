#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Per sleep()

int main() {
    // Dimensione totale in byte da allocare: 2 GB
    size_t size_in_gb = 1.5;
    size_t size_in_bytes = size_in_gb * 1024 * 1024 * 1024;

    // Alloca la memoria
    printf("Allocating %zu bytes (%.2f GB)...\n", size_in_bytes, size_in_gb * 1.0);
    char *large_array = (char *)malloc(size_in_bytes);

    // Controlla se malloc ha avuto successo
    if (large_array == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    // Scrivi in tutta la memoria allocata per garantire che il sistema operativo la assegni
    for (size_t i = 0; i < size_in_bytes; i += 4096) {
        large_array[i] = 0; // Scrive 1 byte per pagina (4 KB)
    }
    printf("Memory successfully allocated and initialized.\n");

    // Mantieni la memoria occupata per 10 secondi
    printf("Holding memory for 10 seconds. Check Task Manager now.\n");
    sleep(10);

    // Libera la memoria
    free(large_array);
    printf("Memory freed. Check Task Manager again.\n");

    // Mantieni il programma in esecuzione per osservare la riduzione della memoria
    sleep(10);

    return 0;
}
