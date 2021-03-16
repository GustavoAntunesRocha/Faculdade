#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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
    int *temp;
    int aux;
    double j;
    int count;
    int k;
    for(i = 0; i < n; i++){
        count = 0;
        aux = numbers[i];
        while(aux != 0){
            count++;
            aux /= 10;
        }
        temp = malloc(count * sizeof(int));
        k = 0;
        aux = numbers[i];
        inverso[i] = 0;
        while (aux != 0){
            temp[k] = aux % 10;
            aux /= 10;
            k++;
        }
        j = count -1;
        for(k = 0; k < count; k++){
            inverso[i] += temp[k] * pow(10,j);
            j--;
        }
        if(inverso[i] == numbers[i]){
            printf("yes ");
        } else{
            printf("no ");
        }
        free(temp);
    }
    free(numbers);
    free(inverso);
    return 0;
}