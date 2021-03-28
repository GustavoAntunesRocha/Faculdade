#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <semaphore.h>

#define BUFFER_SIZE 100
#define READ_END 0
#define WRITE_END 1

sem_t S;

int main(void)
{
    sem_init(&S, 0, 0);
    int fd[2];
    char write_pid[BUFFER_SIZE];
    char read_pid[BUFFER_SIZE];
    pid_t pid;
    
    while (1)
    {
        /* create the pipe */
        if (pipe(fd) == -1)
        {
            fprintf(stderr, "Pipe failed");
            return 1;
        }
        char comando = getchar();
        if (comando == 'w')
        {
            pid = fork();
            if (pid < 0)
            {
                fprintf(stderr, "Fork Failed\n");
                return 1;
            }
            else if (pid > 0)
            {
                
                close(fd[WRITE_END]);
                read(fd[READ_END], read_pid, BUFFER_SIZE);
                
                printf("perseverance@MAIN$ MAIN PID %d - Criando SUBSYS1 PID %s\n",getpid(),read_pid);
                
                sem_post(&S); //Semáforo libera

                close(fd[READ_END]);
                wait(NULL);
                printf("perseverance@MAIN$ MAIN PID %d - SUBSYS1 PID %s terminou\n",getpid(),read_pid);
            }
            else 
            {
                
                close(fd[READ_END]);

                //Concatena pid do filho na string
                snprintf(write_pid, BUFFER_SIZE, "%s%d", write_pid, (int)getpid());

                write(fd[WRITE_END], write_pid, strlen(write_pid) + 1);
                
                //sleep(1);
                
                sem_wait(&S); //Semáforo espera

                printf("perseverance@SUBSYS1$ SUBSYS1 PID %d - MOTORES a frente\n", getpid());
                close(fd[WRITE_END]);
                execlp("pstree", "pstree", "-p", NULL);
                exit(1);
            }
        }
        else if (comando == 's'){
            pid = fork();
            if (pid < 0)
            {
                fprintf(stderr, "Fork Failed\n");
                return 1;
            }
            else if (pid > 0)
            {
                
                close(fd[WRITE_END]);
                read(fd[READ_END], read_pid, BUFFER_SIZE);
                
                printf("perseverance@MAIN$ MAIN PID %d - Criando SUBSYS2 PID %s\n",getpid(),read_pid);
                close(fd[READ_END]);
                wait(NULL);
                printf("perseverance@MAIN$ MAIN PID %d - SUBSYS2 PID %s terminou\n",getpid(),read_pid);
            }
            else 
            {
                close(fd[READ_END]);

                //Concatena pid do filho na string
                snprintf(write_pid, BUFFER_SIZE, "%s%d", write_pid, (int)getpid());

                write(fd[WRITE_END], write_pid, strlen(write_pid) + 1);
                close(fd[WRITE_END]);
                sleep(1);
                printf("perseverance@SUBSYS2$ SUBSYS2 PID %d - CAMERA iniciou\n", getpid());
                printf("perseverance@SUBSYS2$ SUBSYS2 PID %d - Enviando foto de Marte\n", getpid());
                FILE * imagemMarte;

                if(!(imagemMarte = fopen("mars-photo.bag", "r"))){
                    fprintf(stderr, "\nFalha ao abrir camera (arquivo)!");
                }
                char linhaImagem[200];

                while(fgets(linhaImagem, 200, imagemMarte) != NULL){
                    sleep(1);
                    printf("%s", linhaImagem);
                }
                fclose(imagemMarte);
                printf("perseverance@SUBSYS2$ SUBSYS2 PID %d - Foto enviada com sucesso\n", getpid());
                exit(1);
            }
        }
        else if (comando == 'a'){
            printf("perseverance@MAIN$ MAIN PID %d - Processos em execução\n",getpid());
            system("ps -ef");
        }
        else if(comando ==  'd'){
            printf("perseverance@MAIN$ MAIN PID %d - Abortando missão ...\n",getpid());
            return 0;
        }
        else{
            printf("perseverance@MAIN$ MAIN PID %d - Comando inválido ...\n",getpid());
        }
    }
    return 0;
}