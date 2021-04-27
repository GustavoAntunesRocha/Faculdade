/*
* Assincrona 7
*
* Compilacao:
*   gcc -o sync_error.out sync_error.c -lpthread
*
*/

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t arq1_lock, arq2_lock;

void *t1() {
    FILE *arq1, *arq2;
    
    pthread_mutex_lock(&arq2_lock);
    pthread_mutex_lock(&arq1_lock);
    
    arq1 = fopen("arq1.txt", "a");
    printf("Thread 1 escrevendo no arq1.txt\n");
    fputs("1 2 3 4 5\n", arq1);
    fclose(arq1);
    
    arq2 = fopen("arq2.txt", "a");
    printf("Thread 1 escrevendo no arq2.txt\n");
    fputs("A B C D E\n", arq2);
    fclose(arq2);
    
    pthread_mutex_unlock(&arq2_lock);
    pthread_mutex_unlock(&arq1_lock);
}

void *t2() {
    FILE *arq1, *arq2;
    
    pthread_mutex_lock(&arq1_lock);
    pthread_mutex_lock(&arq2_lock);
    
    arq1 = fopen("arq1.txt", "a");
    printf("Thread 2 escrevendo no arq1.txt\n");
    fputs("6 7 8 9 10\n", arq1);
    fclose(arq1);
    
	arq2 = fopen("arq2.txt", "a");
    printf("Thread 2 escrevendo no arq2.txt\n");
    fputs("F G H I J\n", arq2);
    fclose(arq2);
    
	pthread_mutex_unlock(&arq1_lock);
    pthread_mutex_unlock(&arq2_lock);
}

int main() { 
    pthread_t threads[2];
    
    pthread_mutex_init(&arq1_lock, NULL);
    pthread_mutex_init(&arq2_lock, NULL);
    
    pthread_create(&threads[0], NULL, t1, NULL);
    pthread_create(&threads[1], NULL, t2, NULL);
    
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    
    return 0;
}