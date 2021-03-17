#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    int n;
    int *numeros;
    char **base4;
    int aux = 10;
    scanf("%d",&n);
    numeros = malloc(n * sizeof(int));
    base4 = malloc(n * sizeof(char *));
    int i;
    //char *temp;
    int count;
    for(i = 0; i < n; i++){
        scanf("%d",&numeros[i]);
        count = 0;
        aux = numeros[i];
        while(aux != 0){
            count++;
            aux /= 10;
        }
        base4[i] = malloc((count = 1) * sizeof(char));
        if(numeros[i] < 4){
            if(numeros[i] % 4 == 0){
                base4[i]  = "A";
            }
            if(numeros[i] % 4 == 1){
                base4[i] = "C";
            }if(numeros[i] % 4 == 2){
                base4[i] = "G";
            }if(numeros[i] % 4 == 3){
                base4[i] = "T";
            }
        }
        else{
            char temp[count+1];
            //temp = malloc((count + 1) * sizeof(char));
            for(aux = count -1; aux > 0; aux--){
                printf("Etapa 1\n");
                if(numeros[i] % 4 == 0){
                    temp[aux] += 'A';
                    numeros[i] /= 4;
                }
                if(numeros[i] % 4 == 1){
                    temp[aux] += 'C';
                    numeros[i] /= 4;
                }
                if(numeros[i] % 4 == 2){
                    temp[aux] = 'G';
                    numeros[i] /= 4;
                }
                if(numeros[i] % 4 == 3){
                    temp[aux] = 'T';
                    numeros[i] /= 4;
                }
                if(numeros[i] / 4 == 1){
                    temp[aux] == 'C';
                }
                if(numeros[i] / 4 == 2){
                    temp[aux] == 'G';
                }
                if(numeros[i] / 4 == 3){
                    temp[aux] == 'T';
                }
            }
            for(aux = 1; aux < count; aux++){
                //printf("%s", &temp[aux]);
                strcat(temp[aux], base4[i]);
                //base4[i] += temp[aux];
            }
        }
    }
    for(i = 0; i < n; i++){
        printf("\n%s",base4[i]);
    }
}