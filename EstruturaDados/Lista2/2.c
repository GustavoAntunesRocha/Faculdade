#include <stdio.h>

int fibonacci(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    } else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
    return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    int i;
    for(i = 0; i <= n; i++){
        printf("%d ",fibonacci(i));
    }
    return 0;
}