#include <stdio.h>
int reverso(int n){
    if(n == 0){
        return n;
    }
    else{
        if(n % 10 != 0){
            printf("%d",n % 10);
        }
        return reverso(n / 10);
    }
}

int main(){
    int n, i;
    scanf("%d",&n);
    reverso(n);
    return 0;
}