#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>

void main(int argc, char *argv[]){
    int n = 0;
    int a = 0;
    int b = 0;
    char entrada[5];
    scanf("%d",&n);
    __fpurge(stdin);
    gets(entrada);
    printf("%s\n",entrada);
    a = entrada[0];
    b = entrada[4];
    printf("%d, %d",a,b);
}