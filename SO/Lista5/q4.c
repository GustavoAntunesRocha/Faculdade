#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NTHREADS 50
pthread_t threads[NTHREADS];

void *imprimeTID(void *threadid) {
    int i;
    void *status;
    if((long)threadid < NTHREADS){
        pthread_create(&threads[(long)threadid], NULL, imprimeTID, (void *)threadid + 1);
    }
    pthread_join(threads[(long)threadid], &status);
    if((long)threadid != 0){
        printf("Sou a thread com ID %ld criada pela thread com TID %ld\n",(long)pthread_self(), (long)threadid);
    }
    else{
        printf("Sou a thread com ID %ld criado pelo processo pai com PID %d\n",(long)pthread_self(), getppid());
        
    }
    pthread_exit(NULL);
}

int main() {
    int rc;
    long thId = 0;
    void *status;
    rc = pthread_create(&threads[0], NULL, imprimeTID, (void *)thId);
    if (rc) {
        printf("ERRO: código de retorno de pthread_create() é %d\n", rc);
        exit(-1);
    }    
    pthread_exit(NULL);
}