#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    pid_t pid2;
    pid_t pid3;

    pid = fork();
    pid_t pids[4];
    if (pid < 0) {
        fprintf(stderr, "Fork Failed\n");
        return 1;
    } else if (pid == 0) {
        pids[0] = getpid();
        printf("Sou P_A com PID %d, filho de PID %d\n", pids[0], getppid());
        pid2 = fork();
        if (pid2 < 0) {
            fprintf(stderr, "Fork Failed\n");
            return 1;
        } else if(pid2 > 0){
            printf("Eu P_A criei P_B!\n");
            wait(NULL);
            printf("Eu P_A aguardei P_B terminar!\n");
            printf("Eu P_A executei: ps\n");
            execlp("ps","ps","T",NULL);
            exit(0);
        } else{
            pids[1] = getpid();
            printf("Sou P_B com PID %d, PID interno %d, filho do PID %d\n",pids[1],pid2,getppid());
        }
        pid3 = fork();
        if (pid3 < 0) {
            fprintf(stderr, "Fork Failed\n");
            return 1;
        } else if(pid3 > 0){
            printf("Eu P_B criei P_C!\n");
            wait(NULL);
            printf("Eu P_B aguardei P_C terminar!\n");
            printf("Eu P_B executei: ps\n");
            execlp("ps","ps","T",NULL);
            exit(0);
        } else{
            pids[2] = getpid();
            printf("Sou P_C com PID %d, PID interno %d, filho do PID %d\n",pids[2],pid3,getppid());
            printf("Eu P_C executei: ps\n");
            execlp("ps","ps","T",NULL);
            exit(0);
        }
    } 
    return 0;
}