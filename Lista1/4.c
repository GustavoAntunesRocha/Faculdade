#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    int n;
    int *numbers;
    scanf("%d",&n);
    numbers = malloc(n * sizeof(int));
    if (numbers == NULL) {
        printf("malloc failed\n");
        return -1;
    }
    int i;
    for(i = 0; i < n; i++){
        scanf("%d",&numbers[i]);
    }
    int *inverso = malloc(n * sizeof(int));
    int j = 10;
    for(i = 0; i < n; i++){
        while (numbers[i] / j != 0){
            numbers[i] 
        }
        
        printf("%d\n",numbers[i] / 100);
    }
    return 0;
}