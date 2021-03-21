#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    int n;
    scanf("%d",&n);
    fflush(stdin);
    char dimensoes[n][20];
    int i, j;
    char aux[8];
    for(i = 0; i < n; i++){
        getline(aux, sizeof(aux),NULL);
        for(j = 0; j < strlen(aux); j++){
            dimensoes[i][j] = (char*) aux;
        }
    }
    for(i = 0; i < n; i++){
        printf("%s\n",dimensoes[i]);
    }
    return 0;
}