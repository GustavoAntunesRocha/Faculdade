#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int base4(int num);
char aux[200];
int main(int argc, char *argv[]) {
    int n;
    int i;
    int *numeros;
    scanf("%d", &n);
    numeros = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
    }
    for(i = 0; i < 200; i++){
        aux[i] = NULL;
    }
    for (i = 0; i < n; i++) {
        base4(numeros[i]);
    }
    printf("%s",aux);
    return 0;
}

int base4(int num) {
    if (num < 4) {
        switch (num) {
            case 1:
                strcat(aux,"C\n");
                break;
            case 2:
                strcat(aux,"G\n");
                break;
            case 3:
                strcat(aux,"T\n");
                break;
            case 0:
                strcat(aux,"A\n");
                break;
        }
        return 0;
    }
    int i;
    int quociente;

    i = 0;

    int resto[i];

    quociente = num / 4;
    resto[i] = num % 4;

    while (quociente >= 4) {
        i++;
        resto[i] = quociente % 4;
        quociente = quociente / 4;
    }
    i++;
    resto[i] = quociente;
    
    
    for (; i >= 0; i--){
        if (resto[i] < 4 && num >= 4) {
            switch (resto[i]) {
                case 1:
                    strcat(aux,"C");
                    break;
                case 2:
                    strcat(aux,"G");
                    break;
                case 3:
                    strcat(aux,"T");
                    break;
                case 0:
                    strcat(aux,"A");
                    break;
            }
        }
    }
    strcat(aux,"\n");
    return 0;
}