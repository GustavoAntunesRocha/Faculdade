#include <stdio.h>

int numerosNaturais(int n, int i){
    if(i <= n){
        printf("%d ",i);
        i++;
        numerosNaturais(n, i);
    }
    return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    numerosNaturais(n, 1);
    return 0;
}