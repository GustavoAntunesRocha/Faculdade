#include <stdio.h>
#include <stdlib.h>
int binario(int n){
    int i;
    if(n / 2 != 0){
        i = n / 2;
        binario(i);
        printf("%d",n % 2);
    }
    else{
        printf("%d",n % 2);
    }
}
int main(){
    int *n, i, j;
    scanf("%d",&i);
    n = malloc(i * sizeof(int));
    for(j = 0; j < i; j++){
        scanf("%d",&n[j]);
    }
    for(j = 0; j < i; j++){
        binario(n[j]);
        printf("\n");
    }
    return 0;
}