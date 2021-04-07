#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define TAM 1000000000

typedef int elem;
typedef struct {
    elem* v;
    elem proximo;
} Conjunto;

int criaConjunto(Conjunto *C);
int conjuntoVazio(Conjunto *C);
int insereElementoConjunto(elem x, Conjunto *C);
int excluirElementoConjunto(elem x, Conjunto *C);
int tamanhoConjunto(Conjunto *C);
int maior(elem x, Conjunto *C);
int menor(elem x, Conjunto *C);
int pertenceConjunto(elem x, Conjunto *C);
int conjuntosIdenticos(Conjunto *C1, Conjunto *C2);
int subconjunto(Conjunto *C1, Conjunto *C2);
Conjunto* complemento(Conjunto *C1, Conjunto *C2);
Conjunto* uniao(Conjunto *C1, Conjunto *C2);
Conjunto* interseccao(Conjunto *C1, Conjunto *C2);
Conjunto* diferenca(Conjunto *C1, Conjunto *C2);
Conjunto* conjuntoPartes(Conjunto *C);
void mostraConjunto(Conjunto *C, char *ordem);
int copiarConjunto(Conjunto *C1, Conjunto *C2);
int destroiConjunto(Conjunto *C);

void quick_sort_crescente(Conjunto *C, int left, int right);
void quick_sort_decrescente(Conjunto *C, int left, int right);

void main(){
    int escolha;
    printf("Escolha uma opção:\n");
}

int criaConjunto(Conjunto *C){
    C = malloc(sizeof(Conjunto));
    if(C == NULL){
        return 0;
    }
    C->v = (int*)malloc( TAM * sizeof(int));
    if(C->v == NULL){
        return 0;
    }
    C->proximo = 0;
    return 1;
}

int conjuntoVazio(Conjunto *C){
    int i;
    for(i = 0; i < TAM; i++){
        if(C->v != NULL){
            return 0;
        }
    }
    return 1;
}

int insereElementoConjunto(elem x, Conjunto *C){
    if(x >= LONG_MAX || x < 0){
        return 0;
    }
    C->v [C->proximo] = x;
    C->proximo += 1;
    return 1;
}

int excluirElementoConjunto(elem x, Conjunto *C){
    if(x >= LONG_MAX || x < 0){
        return 0;
    }
    int i;
    int j;
    for(i = 0; i < C->proximo; i++){
        if(C->v[i] == x){
            for(j = i; j < C->proximo; j++){
                C->v[j] = C->v[j+1];
            }
        }
    }
    C->proximo -= 1;
    return 1;
}

int tamanhoConjunto(Conjunto *C){
    return C->proximo;
}

int maior(elem x,Conjunto *C){
    int i, aux = 0;
    for(i = 0; i < C->proximo; i++){
        if(C->v > x){
            aux ++;
        }
    }
    if(tamanhoConjunto(C) == aux){
        return 0;
    }
    return aux;
}

int menor(elem x,Conjunto *C){
    int i, aux = 0;
    for(i = 0; i < C->proximo; i++){
        if(C->v < x){
            aux ++;
        }
    }
    if(tamanhoConjunto(C) == aux){
        return 0;
    }
    return aux;
}

int pertenceConjunto(elem x, Conjunto *C){
    if(x >= LONG_MAX || x < 0){
        return 0;
    }
    int i;
    for(i = 0; i < C->proximo; i++){
        if(C->v[i] == x){
            return 1;
        }
    }
    return 0;
}

int conjuntosIdenticos(Conjunto *C1,Conjunto *C2){
    int i;
    for(i = 0; i < C1->proximo; i++){
        if(C1->v[i] != C2->v[i]){
            return 0;
        }
    }
    return 1;
}

int subconjunto(Conjunto *C1, Conjunto* C2){
    int i;
    for(i = 0; i < C1->proximo; i++){
        if(!pertenceConjunto(C1->v[i], C2) ){
            return 0;
        }
    }
    return 1;
}

Conjunto* complemento(Conjunto *C1, Conjunto *C2){
    Conjunto *C3;
    criaConjunto(C3);
    if(subconjunto(C2, C1) == 0){
        C3 = NULL;
        return C3;
    }
    int i;
    for(i = 0; i < C2->proximo; i++){
        if(!pertenceConjunto(C2->v[i], C1)){
            C3->v[C3->proximo] = C2->v[i];
            C3->proximo ++;
        }
    }
    return C3;
}

Conjunto* uniao(Conjunto *C1, Conjunto *C2){
    Conjunto *C3;
    criaConjunto(C3);
    int i;
    for(i = 0; i < C1->proximo; i++){
        C3->v[C3->proximo] = C1->v[i];
        C3->proximo ++;
    }
    for(i = 0; i < C2->proximo; i++){
        C3->v[C3->proximo] = C2->v[i];
        C3->proximo ++;
    }
    return C3;
}

Conjunto* interseccao(Conjunto *C1, Conjunto *C2){
    Conjunto *C3;
    criaConjunto(C3);
    if(subconjunto(C2, C1) == 0){
        C3 = NULL;
        return C3;
    }
    int i;
    for(i = 0; i < C1->proximo; i++){
        if(pertenceConjunto(C1->v[i], C2)){
            C3->v[C3->proximo] = C1->v[i];
            C3->proximo ++;
        }
    }
    return C3;
}

Conjunto* diferenca(Conjunto *C1, Conjunto *C2){
    Conjunto *C3;
    criaConjunto(C3);
    if(subconjunto(C1, C1) == 0){
        C3 = NULL;
        return C3;
    }
    int i;
    for(i = 0; i < C1->proximo; i++){
        if(!pertenceConjunto(C1->v[i], C2)){
            C3->v[C3->proximo] = C1->v[i];
            C3->proximo ++;
        }
    }
    return C3;
}

Conjunto* conjuntoPartes(Conjunto *C){

}

void quick_sort_crescente(Conjunto *C, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = C->v[(left + right) / 2];
     
    while(i <= j) {
        while(C->v[i] < x && i < right) {
            i++;
        }
        while(C->v[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = C->v[i];
            C->v[i] = C->v[j];
            C->v[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort_crescente(C, left, j);
    }
    if(i < right) {
        quick_sort_crescente(C, i, right);
    }
}

void quick_sort_decrescente(Conjunto *C, int left, int right){
    int i, j, x, y;
     
    i = left;
    j = right;
    x = C->v[(left + right) / 2];
     
    while(i <= j) {
        while(C->v[i] > x && i < right) {
            i++;
        }
        while(C->v[j] < x && j > left) {
            j--;
        }
        if(i <= j) {
            y = C->v[i];
            C->v[i] = C->v[j];
            C->v[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort_decrescente(C, left, j);
    }
    if(i < right) {
        quick_sort_decrescente(C, i, right);
    }
}

void mostraConjunto(Conjunto *C, char *ordem){
    Conjunto *A;
    criaConjunto(A);
    A = C;
    if(strcmp("CRESCENTE", ordem) == 0){
        quick_sort_crescente(A, 0, A->proximo -1);
    }
    else{
        quick_sort_decrescente(A, 0, A->proximo -1);
    }
    int i;
    for(i = 0; i < A->proximo; i++){
        printf("%d\n", A->v[i]);
    }
}

int copiarConjunto(Conjunto *C1, Conjunto *C2){
    int i;
    if(conjuntoVazio(C1)){
        return 0;
    }
    for(i = 0; i < C1->proximo; i++){
        if(C2->proximo == TAM){
            return 0;
        }
        C2->v[C2->proximo] = C1->v[i];
        C2->proximo ++;
    }
    return 1;
}

int destroiConjunto(Conjunto *C){
    if(C == NULL){
        return 0;
    }
    free(C);
    return 1;
}