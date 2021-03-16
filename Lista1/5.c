#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    int n;
    int *numeros;
    char *base4;
    int aux = 10;
    scanf("%d",&n);
    numeros = malloc(n * sizeof(int));
    base4 = malloc(n * sizeof(char));
    int i;
    for(i = 0; i < n; i++){
        scanf("%d",&numeros[i]);
        if(numeros[i] < 4){
            base4[i] = numeros[i] % 4;
        }else{
            base4[i] = numeros[i] % 4;
        }
    }
    for(i = 0; i < n; i++){
        printf("\n%d",base4[i]);
    }
}