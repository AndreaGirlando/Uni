#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Parameters {
    float n;
    char inputFileName[100];
};

struct Parameters decodeParameters(int argc, char *argv[]) {
    struct Parameters params;

    if (argc != 3) {
        fprintf(stderr, "Uso: %s n input.dat\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *endptr;
    params.n = strtol(argv[1], &endptr, 10);

    if (*endptr) {
        fprintf(stderr, "Errore: Il primo parametro deve essere un intero valido.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(params.inputFileName, argv[2]);

    if (params.n < 5 || params.n > 20) {
        fprintf(stderr, "Errore: n deve essere compreso tra 5 e 20.\n");
        exit(EXIT_FAILURE);
    }

    const char *extension = strrchr(params.inputFileName, '.');
    if (extension == NULL || strcmp(extension, ".dat") != 0) {
        fprintf(stderr, "Errore: il file deve avere estensione .dat.\n");
        exit(EXIT_FAILURE);
    }

    return params;
}

int *readInput(const char *fileName, int *size) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        fprintf(stderr, "Errore: Impossibile aprire il file %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    int capacity = 10;
    int *array = (int *)malloc(capacity * sizeof(int));
    if (array == NULL) {
        fclose(file);
        fprintf(stderr, "Errore di allocazione memoria.\n");
        exit(EXIT_FAILURE);
    }

    int num;
    *size = 0;
    while (fscanf(file, "%d", &num) == 1) {
        if (*size == capacity) {
            capacity *= 2;
            array = (int *)realloc(array, capacity * sizeof(int));
            if (array == NULL) {
                fclose(file);
                fprintf(stderr, "Errore di allocazione memoria.\n");
                exit(EXIT_FAILURE);
            }
        }
        array[(*size)++] = num;
    }

    fclose(file);
    return array;
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }
}

struct stackNode {
    float data;
    struct stackNode *next;
};

typedef struct stackNode StackNode;

bool push(StackNode **top, float data) {
    StackNode *newNode = malloc(sizeof(StackNode));

    if(newNode==NULL)
        return false;

    newNode->data = data;
    newNode->next = *top;

    *top = newNode;
    return true;
}

float pop(StackNode **top) {
    StackNode *tmp = *top;
    float data = tmp->data;
    *top = tmp->next;
    free(tmp); 
    return data;
}

bool isEmpty(StackNode *top) {
    return top==NULL;
}

StackNode* createStack(int *array, int size, int n) {
    StackNode *top = NULL;

    for (int i = 0; i < size; i++) {
        if (array[i] % n == 0) {
            push(&top, array[i]);
        } else {
            if (!isEmpty(top)) {
                float x = pop(&top);
                float avg = (x + array[i]) / 2;
                push(&top, avg);
            }
        }
    }

    return top;
}

void printStack(StackNode *top) {
    StackNode *aux = top;
    while (aux) {
        float data = aux->data;
        printf("%0.2f\n", data);
        aux = aux->next;
    }
}

void findMinMaxMean(struct stackNode *top, float *min, float *max, float *mean) {
    if (isEmpty(top)) {
        fprintf(stderr, "Error: Stack is empty.\n");
        return;
    }

    *min = top->data;
    *max = *min;
    float sum = *min;
    int count = 1;

    StackNode *aux = top;
    aux = aux->next;

    while (aux) {
        int value = aux->data;
        sum += value;
        count++;

        if (value < *min) {
            *min = value;
        } else if (value > *max) {
            *max = value;
        }
        aux = aux->next;
    }

    *mean = sum / count;
}



int main(int argc, char *argv[]) {
    struct Parameters params = decodeParameters(argc, argv);

    printf("Punto A - Parametri inseriti: n=%d, inputFileName=%s\n", params.n, params.inputFileName);

    int size;
    int *array = readInput(params.inputFileName, &size);

    printf("\nPunto B - Contenuto di A:\n");
    printArray(array, size);

    StackNode *S = createStack(array, size, params.n);

    printf("\nPunto C - Contenuto di S:\n");
    printStack(S);

    float min, max, mean;

    findMinMaxMean(S, &min, &max, &mean);

    printf("\nPunto D:\n");
    printf("Valore minimo: %.2f\n", min);
    printf("Valore massimo: %.2f\n", max);
    printf("Valore medio: %.2f\n", mean);

    free(array);

    return 0;
}
