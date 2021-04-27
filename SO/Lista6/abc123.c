#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

const char *semaphore_name = "semaforo";
sem_t mutex;
int turn;

void gravaNumeros(FILE *fp) {
    int i;    
    for (i = 1; i <= 26; i++) {
        sem_wait(&mutex);
        if (fp != NULL) {
            fprintf(fp, "%d", i);
        } else
            printf("Erro na abertura do arquivo.");
        //fclose(fp);
        //i++;
        sem_post(&mutex);
    }
}

void gravaLetras(FILE *fp) {
    int i;
    char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (i = 0; i < strlen(alfabeto); i++) {
        sem_wait(&mutex);
        if (fp != NULL) {
            fprintf(fp, " %c\n", alfabeto[i]);
        } else
            printf("Erro na abertura do arquivo.");
        
        sem_post(&mutex);
    }
}

int main() {
    FILE *fp;
    pid_t pid, pid2;
    sem_init(&mutex, 1, 1);
    //mutex = sem_open(semaphore_name, O_CREAT, 0644, 1);
    fp = fopen("abc123.x", "a");
    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork Failed\n");
        return 1;
    } else if (pid > 0) {
        pid2 = fork();
        if (pid2 < 0) {
            fprintf(stderr, "Fork Failed\n");
            return 1;
        } else if (pid2 > 0) {
            wait(NULL);
        } else if (pid2 == 0) {
            gravaLetras(fp);
            exit(1);
        }
        wait(NULL);
        //FILE *fp;
        char c;
        if ((fp = fopen("abc123.x", "r")) != NULL) {
            while ((c = fgetc(fp)) != EOF) {
                printf("%c", c);
            }
            fclose(fp);
        }
        sem_destroy(&mutex);
    } else {
        gravaNumeros(fp);
        exit(1);
    }
}