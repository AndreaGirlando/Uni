#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include <errno.h>
#include <sched.h>
#include <limits.h> 
#include <unistd.h>
typedef struct {
    sem_t sem_ready; 
    sem_t sem_release;  

    long long op1;
    long long op2;
    char      op;        
    long long result;     

    int done_op1, done_op2, done_ops;
    bool op1_ready, op2_ready, ops_ready;
} Shared;

typedef struct {
    Shared *S;
    const char *path;
} Args;

static void die(const char *m){ perror(m); exit(EXIT_FAILURE); }

static void* th_op1(void *arg){
    Args *A=(Args*)arg; Shared *S=A->S;
    FILE *fp=fopen(A->path,"r"); if(!fp) die("open OP1");
    setvbuf(stdout,NULL,_IONBF,0);
    printf("[OP1] leggo gli operandi dal file '%s'\n", A->path);

    long long v; int idx=1; bool ended=false;
    S->op1_ready = false;
    for(;;){
        // produttore OP1 legge il primo file e mette il valore letto in S->op1
        //leggi l'operando e mettilo in S->op1
        //se arrivi a fine file, imposta S->done_op1=1
        if(!S->op1_ready)
            {
                if(fscanf(fp, "%lld", &v) == 1){
                S->op1 = v;  // scrivo direttamente nella memoria condivisa
                S->op1_ready = true;
                printf("[OP1] primo operando n.%d: %lld\n", idx++, v);
                sem_post(&S->sem_ready);
            } else {
                S->done_op1 = 1;  // fine file
                printf("[OP1] termino\n");
                sem_post(&S->sem_ready);
                break;
            }
        }
        else{
            continue;
        }
    }
    fclose(fp);
    return NULL;
}

static void* th_op2(void *arg){
    Args *A=(Args*)arg; Shared *S=A->S;
    FILE *fp=fopen(A->path,"r"); if(!fp) die("open OP2");
    setvbuf(stdout,NULL,_IONBF,0);
    printf("[OP2] leggo gli operandi dal file '%s'\n", A->path);

    long long v; int idx=1; bool ended=false;
    S->op2_ready = false; 
    for(;;){
        if(!S->op2_ready)
        {
        // produttore OP2 legge il secondo file e mette il valore letto in S->op2
        if (fscanf(fp, "%lld", &v) == 1){
            S->op2 = v;   // scrivo nella memoria condivisa
            S->op2_ready = true;
            printf("[OP2] secondo operando n.%d: %lld\n", idx++, v);
            // TODO: più avanti -> sem_post per svegliare CALC
            sem_post(&S->sem_ready);
        } else {
            S->done_op2 = 1;
            printf("[OP2] termino\n");
            sem_post(&S->sem_ready);
            break;
        }
    } else{
        continue;
    }
    }
    fclose(fp);
    return NULL;
}

static void* th_ops(void *arg){
    Args *A=(Args*)arg; Shared *S=A->S;
    FILE *fp=fopen(A->path,"r"); if(!fp) die("open OPS");
    setvbuf(stdout,NULL,_IONBF,0);
    printf("[OPS] leggo le operazioni e il risultato atteso dal file '%s'\n", A->path);

    long long somma=0;
    char tok[256];
    int n_ops=0;
    long long atteso=0;
    S->ops_ready = false;
    for(;;){
        if (!S->ops_ready)
        {    
        // un thread OPS che si occuperà di leggere il tipo di operazione da applicazione nelle varie operazioni minori dal terzo file fornito e il risultato finale atteso;
        if (fscanf(fp, "%63s", tok) != 1){
            // EOF inatteso: chiudo comunque
            S->done_ops = 1;
            printf("[OPS] termino\n");
            sem_post(&S->sem_ready);
            break;
        }

        // Se è un'operazione (+, -, x/X) la pubblico su S->op
        if (tok[1] == '\0' && (tok[0] == '+' || tok[0] == '-' || tok[0] == 'x' || tok[0] == 'X')){
            S->op = (tok[0] == 'X') ? 'x' : tok[0];
            printf("[OPS] operazione n.%d: %c\n", ++n_ops, S->op);
            S->ops_ready = true;
            sem_post(&S->sem_ready);      // segnala a CALC
            while (S->ops_ready == true) { continue; }
            somma += S->result;
            printf("[OPS] sommatoria dei risultati parziali dopo %d operazione/i: %lld\n",
                   n_ops, somma);
        } else {
            // Altrimenti interpreto il token come risultato finale atteso e termino
            errno = 0; 
            char *endp = NULL;
            long long atteso = strtoll(tok, &endp, 10);
            if (errno == 0 && endp && *endp == '\0'){
                printf("[OPS] risultato finale atteso: %lld\n", atteso);
            } else {
                fprintf(stderr, "[OPS] token non valido: '%s'\n", tok);
            }
            S->done_ops = 1;
            printf("[OPS] termino\n");
            sem_post(&S->sem_ready);
            break;
        }
        } else{
            continue;
        }
    }

    fclose(fp);
    return NULL;
}

static void* th_calc(void *arg){
    Shared *S=(Shared*)arg;
    setvbuf(stdout,NULL,_IONBF,0);
    int idx=1;
    bool ended=false;
    for(;;){
        // Attendo i 3 eventi (OP1, OP2, OPS)
        sem_wait(&S->sem_ready);
        sem_wait(&S->sem_ready);
        sem_wait(&S->sem_ready);

        // Potrebbe essere la terna di CHIUSURA: in tal caso termina
        if (S->done_op1 && S->done_op2 && S->done_ops) {
            printf("[CALC] termino\n");
            break;
        }

        // Eseguo il calcolo
        long long a = S->op1, b = S->op2, r = 0;
        char op = (S->op == 'X') ? 'x' : S->op;
        switch(op){
            case '+': r = a + b; break;
            case '-': r = a - b; break;
            case 'x': r = a * b; break;
            default : printf("[CALC] Errore ops non mi ha fornito un'operazione, controlla la sincronizzazione"); break;
        }
        S->result = r;
        static int idx = 1;
        printf("[CALC] operazione minore n.%d: %lld %c %lld = %lld\n", idx++, a, op, b, r);
        S->op1_ready = false;
        S->op2_ready = false;
        S->ops_ready = false;
        // Sveglio i 3 produttori
        //sem_post(&S->sem_release);
        //sem_post(&S->sem_release);
        //sem_post(&S->sem_release);
    }
    return NULL;
}

/* ------------------- MAIN ------------------- */
int main(int argc, char **argv){
    if(argc!=4){
        fprintf(stderr,"Uso: %s <first-operands> <second-operands> <operations>\n", argv[0]);
        return EXIT_FAILURE;
    }
    setvbuf(stdout,NULL,_IONBF,0);
    printf("[MAIN] creo i thread ausiliari\n");

    Shared S;
    memset(&S, 0, sizeof S);
    if(sem_init(&S.sem_ready,0,0)) die("sem_init gate");
    if(sem_init(&S.sem_release,0,0)) die("sem_init calc");

    pthread_t t1,t2,t3,tc;
    Args a1={.S=&S,.path=argv[1]};
    Args a2={.S=&S,.path=argv[2]};
    Args ao={.S=&S,.path=argv[3]};

    if(pthread_create(&t1,NULL,th_op1,&a1)) die("pthread_create OP1");
    if(pthread_create(&t2,NULL,th_op2,&a2)) die("pthread_create OP2");
    if(pthread_create(&t3,NULL,th_ops,&ao)) die("pthread_create OPS");
    if(pthread_create(&tc,NULL,th_calc,&S )) die("pthread_create CALC");

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(tc,NULL);

    sem_destroy(&S.sem_ready);
    sem_destroy(&S.sem_release);

    printf("[MAIN] termino il processo\n");
    return EXIT_SUCCESS;
}