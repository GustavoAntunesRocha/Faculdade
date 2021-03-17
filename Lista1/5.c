#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int base4(int num);

int main(int argc, char *argv[]) {
    int n;
    int i;
    int *numeros;
    scanf("%d", &n);
    numeros = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
    }
    for (i = 0; i < n; i++) {
        base4(numeros[i]);
    }
    return 0;
}

int base4(int num) {
    if (num < 4) {
        switch (num) {
            case 1:
                printf("C");
                printf("\n");
                break;
            case 2:
                printf("G");
                printf("\n");
                break;
            case 3:
                printf("T");
                printf("\n");
                break;
            case 0:
                printf("A");
                printf("\n");
                break;
        }
        return 0;
    }
    int i, j;
    int quociente;

    i = 0;

    int resto[i];

    quociente = num / 4;
    resto[i] = num % 4;

    while (quociente >= 4) {
        i++;
        resto[i] = quociente % 4;
        quociente = quociente / 4;
    }
    i++;
    resto[i] = quociente;

    for (; i >= 0; i--)
        if (resto[i] < 4 && num >= 4) {
            switch (resto[i]) {
                case 1:
                    printf("C");
                    break;
                case 2:
                    printf("G");
                    break;
                case 3:
                    printf("T");
                    break;
                case 0:
                    printf("A");
                    break;
            }
        } else {
            printf("%d", resto[i]);
        }

    printf("\n");
    return 0;
}