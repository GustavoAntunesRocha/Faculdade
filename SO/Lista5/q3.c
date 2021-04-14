#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void *gravaNumeros(void *threadid)
{
    int i;
    FILE *fp;
    if ((fp = fopen("numeros.txt", "w")) != NULL)
    {
        for (i = 1; i <= 10; i++)
        {
            fprintf(fp, "%d\n", i);
        }
    }
    else
        printf("Erro na abertura do arquivo.");
    fclose(fp);
    pthread_exit(NULL);
}

void *gravaLetras(void *threadid)
{
    int i;
    char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    FILE *f;
    if ((f = fopen("letras.txt", "w")) != NULL)
    {
        for (i = 0; i < strlen(alfabeto); i++)
        {
            fprintf(f, "%c\n", alfabeto[i]);
        }
    }
    else
        printf("Erro na abertura do arquivo.");
    fclose(f);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[2];
    int rc;
    long thId;
    void *status;
    rc = pthread_create(&threads[0], NULL, gravaNumeros, (void *)0);
    rc = pthread_create(&threads[1], NULL, gravaLetras, (void *)1);
    if (rc)
    {
        printf("ERRO: código de retorno de pthread_create() é %d\n", rc);
        exit(-1);
    }
    FILE *fp, *fp2;
    char c, c2;
    for (thId = 0; thId < 2; thId++)
    {
        rc = pthread_join(threads[thId], &status);
        if (rc)
        {
            printf("ERRO: código de retorno de pthread_join() é %d\n", rc);
            exit(-1);
        }
    }
    if ((fp = fopen("numeros.txt", "r")) != NULL)
    {
        while ((c = fgetc(fp)) != EOF)
        {
            printf("%c", c);
        }
        fclose(fp);
    }
    if ((fp2 = fopen("letras.txt", "r")) != NULL)
    {
        while ((c2 = fgetc(fp2)) != EOF)
        {
            printf("%c", c2);
        }
        fclose(fp2);
    }
    pthread_exit(NULL);
}