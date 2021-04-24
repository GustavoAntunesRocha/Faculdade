#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

const char *semaphore_name = "q2";
sem_t *S;

void gravaNumeros()
{
    int i;
    FILE *fp;
    for (i = 1; i <= 26; i++)
    {
        sem_wait(S);
        if ((fp = fopen("abc123.x", "a")) != NULL)
        {
            fprintf(fp, "%d", i);
        }
        else
            printf("Erro na abertura do arquivo.");
        fclose(fp);
        sem_post(S);
    }
}

void gravaLetras()
{
    int i;
    char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    FILE *f;

    for (i = 0; i < strlen(alfabeto); i++)
    {
        sem_wait(S);
        if ((f = fopen("abc123.x", "a")) != NULL)
        {
            fprintf(f, " %c\n", alfabeto[i]);
        }
        else
            printf("Erro na abertura do arquivo.");
        fclose(f);
        sem_post(S);
    }
}

int main()
{

    pid_t pid, pid2;
    //sem_init(&S, 1, 100);
    S  = sem_open("semaforo", O_CREAT, 0644, 1);
    pid = fork();
    sem_post(S);
    if (pid < 0)
    {
        fprintf(stderr, "Fork Failed\n");
        return 1;
    }
    else if (pid > 0)
    {
        
        pid2 = fork();
        if (pid2 < 0)
        {
            fprintf(stderr, "Fork Failed\n");
            return 1;
        }
        else if (pid2 > 0){
            wait(NULL);
        }
        else
        {
            gravaLetras();
            exit(1);
        }
        wait(NULL);
        FILE *fp;
        char c;
        if ((fp = fopen("abc123.x", "r")) != NULL)
        {
            while ((c = fgetc(fp)) != EOF)
            {
                printf("%c", c);
            }
            fclose(fp);
        }
        //sem_destroy(&S);
    }
    else
    {
        gravaNumeros();
        exit(1);
    }
}