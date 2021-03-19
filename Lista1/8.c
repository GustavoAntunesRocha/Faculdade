#include <stdio.h>

int main() {
    int i, j, n, resultado;

    scanf("%d", &n);
    unsigned long long int num[n];
    for (i = 0; i < n; i++) {
        scanf("%lld", &num[i]);
    }
    for (i = 0; i < n; i++) {
        resultado = 0;
        for (j = 2; j <= num[i] / 2; j++) {
            if (num[i] % j == 0) {
                resultado++;
                break;
            }
        }
        if (resultado == 0)
            printf("primo\n");
        else
            printf("composto\n");
    }

    return 0;
}