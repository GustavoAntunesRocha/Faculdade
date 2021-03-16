#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
void splitEspaces(char string[]);
char  numeros[5];
void main(int argc, char *argv[]){
    int n;
    char entrada[10];
    scanf("%d",&n);
    __fpurge(stdin);
    gets(entrada);
    int i= 0;
    int op1;
    int op2;
    char op;
    /*
    printf("entrada: %s\n",entrada[i]);
    while(strcmp(entrada[i], "\n") != 0){
       op1 += (int)entrada[i];
       printf("Estágio 1: %d",op1);
       if(entrada[i] == " "){
          i++;
          op = entrada[i];
          printf("Estágio 2: %d",op);
       }
       i += 2;
       while(strcmp(entrada[i], "\n") != 0)
       {
          op2 += (int)entrada[i];
          printf("Estágio 3: %d",op2);
          i++;
       }
       
    }
    */
    //printf("%d, %c, %d",op1,op,op2);
    splitEspaces(entrada);
    if(strcmp(entrada[i], "+") != 0){
       if((int)numeros[0] + (int)numeros[2] > n){
          printf("overflow + \n");
       } else{
          printf("no overflow + \n");
       }
    }
    if(strcmp(entrada[i], "x") != 0){
       if((int)numeros[0] * (int)numeros[2] > n){
          printf("overflow x \n");
       } else{
          printf("no overflow x \n");
       }
    }
}
void splitEspaces(char string[]){
   // Extract the first token
   char * token = strtok(string, " ");
   // loop through the string to extract all other tokens
   int i = 0;
   while( token != NULL ) {
      numeros[i] = &token;
      token = strtok(NULL, " ");
      i++;
   }
}