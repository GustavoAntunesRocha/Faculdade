#include <stdio.h>

int main() {
    int t, i, aux;
    scanf("%d", &t);
    int countM[t], countN[t];
    unsigned long long int m[t], n[t];
    for (i = 0; i < t; i++) {
        scanf("%lld", &m[i]);
        scanf("%lld", &n[i]);
        countM[i] = 0;
        countN[i] = 0;
    }
    //Contando quantos algarismos tem os vetores m
    for (i = 0; i < t; i++) {
        aux = m[i];
        while (aux != 0) {
            countM[i]++;
            aux /= 10;
        }
    }
    //Contando quantos algarismos tem os vetores n
    for (i = 0; i < t; i++) {
        aux = n[i];
        while (aux != 0) {
            countN[i]++;
            aux /= 10;
        }
    }
    for (i = 0; i < t; i++) {
        printf("%lld", m[i] * n[i]);
    }
    unsigned long long int c return 0;
}