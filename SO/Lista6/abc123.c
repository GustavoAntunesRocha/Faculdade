#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

const char *semaphore_name = "q2";
sem_t *sem_id;
//sem_t S;

void gravaNumeros() {
    sem_id = sem_open(semaphore_name, 0);
    int i;
    FILE *fp;
    for (i = 1; i <= 26; i++) {
        sem_wait(sem_id);
        if ((fp = fopen("abc123.x", "a")) != NULL) {
            fprintf(fp, "%d", i);
        } else
            printf("Erro na abertura do arquivo.");
        fclose(fp);
        sem_post(sem_id);
    }
}

void gravaLetras() {
    sem_id = sem_open(semaphore_name, 0);
    int i;
    char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    FILE *f;
    for (i = 0; i < strlen(alfabeto); i++) {
        sem_wait(sem_id);
        if ((f = fopen("abc123.x", "a")) != NULL) {
            fprintf(f, " %c\n", alfabeto[i]);
        } else
            printf("Erro na abertura do arquivo.");
        fclose(f);
        sem_post(sem_id);
    }
}

int main() {
    pid_t pid, pid2;
    sem_id = sem_open(semaphore_name, O_CREAT, 0644, 3);
    //sem_init(&S, 1, 1);
    //S = sem_open("semaforo", O_CREAT, 0644, 1);
    pid = fork();
    sem_post(sem_id);
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
            gravaLetras();
            exit(1);
        }
        wait(NULL);
        FILE *fp;
        char c;
        if ((fp = fopen("abc123.x", "r")) != NULL) {
            while ((c = fgetc(fp)) != EOF) {
                printf("%c", c);
            }
            fclose(fp);
        }
        //sem_destroy(&S);
        sem_unlink(semaphore_name);
    } else {
        gravaNumeros();
        exit(1);
    }

}