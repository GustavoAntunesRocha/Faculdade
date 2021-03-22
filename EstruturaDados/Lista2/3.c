#include <stdio.h>

int fack(int m, int n) {
    if (m == 0) {
        return n + 1;
    }
    else if (n == 0) {
        return fack(m - 1, 1);
    }
    else {
        int aux = fack(m, n - 1);
        return fack(m - 1, aux);
    }
}
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    printf("%d", fack(m, n));
    return 0;
}