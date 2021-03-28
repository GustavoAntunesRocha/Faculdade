#include <stdio.h>

long double fatorial(unsigned long long int n){
    if(n <= 1){
        return n;
    }
    else {
        if(n % 2 == 0){
            n -= 1;
        }
        return (n * fatorial(n - 2));
    }
}
int main(){
    int n;
    scanf("%d",&n);
    long double resultado;
    resultado = fatorial(n);
    printf("%.Lf",resultado);
    return 0;
}