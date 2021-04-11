#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define TAM 1000000

typedef int elem;
typedef struct {
    elem *v;
    elem chave;
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
void mostraConjunto(Conjunto *C, int ordem);
int copiarConjunto(Conjunto *C1, Conjunto *C2);
int destroiConjunto(Conjunto *C);

void quick_sort_crescente(Conjunto *C, int left, int right);
void quick_sort_decrescente(Conjunto *C, int left, int right);

int conjuntoExiste(Conjunto *C , int j);

int i = 0;

int main(){
    int escolha = 1;
    Conjunto *C;
    C = malloc(sizeof(Conjunto));
    if(C == NULL){
        printf("Nao foi possivel alocar memoria para o vetor de conjuntos");
        return 0;
    }
    
    while(escolha != 0){
    printf("Digite o numero correspondente a opção desejada:\n");
    printf("0 - Sair do programa:\n");
    printf("1 - Criar um conjunto:\n");
    printf("2 - Verificar se um conjunto e vazio:\n");
    printf("3 - Inserir um elemento em um conjunto:\n");
    printf("4 - Excluir um elemento em um conjunto:\n");
    printf("5 - Calcular a cardinalidade de um conjunto:\n");
    printf("6 - Determinar a quantidade de elementos de um conjunto maiores que um numero X:\n");
    printf("7 - Determinar a quantidade de elementos de um conjunto menores que um numero X:\n");
    printf("8 - Verificar se um elemento pertence a um conjunto:\n");
    printf("9 - Comparar se dois conjuntos sao identicos:\n");
    printf("10 - Identificar se um conjunto e subconjunto de outro:\n");
    printf("11 - Gerar o complemento de um conjunto em relacao a outro:\n");
    printf("12 - Gerar a uniao de um conjunto com outro:\n");
    printf("13 - Gerar a interceccao de um conjunto com outro:\n");
    printf("14 - Gerar a diferenca entre um conjunto e outro:\n");
    printf("15 - Gerar o conjunto das partes de um conjunto:\n");
    printf("16 - Mostrar os elementos presentes em um conjunto:\n");
    printf("17 - Copiar um conjunto para outro:\n");
    printf("18 - Excluir um conjunto:\n");
    scanf("%d",&escolha);
    int retorno;
    int j;
    int k;
    switch (escolha)
    {
    case 0:
        printf("Programa encerrando\n");
        free(C);
        return 1;
        break;
    case 1:
        C = realloc(C, (i + 1) * sizeof(Conjunto));
        if(C == NULL){
            printf("Nao foi possivel alocar\n");
            printf("___________________________________________________\n");
            printf("Pressione qualquer tecla para continuar...");
            getchar();
            getchar();
            printf("\n\n\n\n");
            break;
        }
        retorno = criaConjunto(&C[i]);
        if(retorno){
            printf("___________________________________________________\n");
            printf("Conjunto criado com sucesso!\nID do conjunto: %d\n",i);
            printf("Pressione qualquer tecla para continuar...");
            getchar();
            getchar();
            i++;
            printf("\n\n\n\n");
        }
        else{
            printf("Nao foi possivel criar o conjunto\n");
            printf("Pressione qualquer tecla para continuar...");
            getchar();
            getchar();
            printf("\n\n\n\n");
        }
        break;
    case 2:
        printf("___________________________________________________\n");
        printf("Digite o ID do conjunto: ");
        scanf("%d",&j);
        if(conjuntoExiste(&C[j], j) == 0){
            break;
        }
        if(conjuntoVazio(&C[j]) == 0){
            printf("O conjunto nao esta vazio\n");
        }
        else{
            printf("O conjunto esta vazio\n");
        }
        printf("Pressione qualquer tecla para continuar...");
        getchar();
        getchar();
        printf("\n\n\n\n");
        break;
    case 3:
        printf("___________________________________________________\n");
        printf("Digite o ID do conjunto: ");
        scanf("%d",&j);
        if(conjuntoExiste(&C[j], j) == 0){
            break;
        }
        printf("Digite o numero a ser adicionado no conjunto %d: ",j);
        scanf("%d",&k);
        retorno = insereElementoConjunto(k,&C[j]);   
        if(retorno == 1){
            printf("Elemento inserido com sucesso!\nPressione qualquer tecla para continuar...");
            getchar();
            getchar();
            printf("\n\n\n\n");
        }
        else{
            printf("Nao foi possivel inserir no conjunto\n");
            printf("Pressione qualquer tecla para continuar...");
            getchar();
            getchar();
            printf("\n\n\n\n");
        }
        break;
    case 4:
        printf("___________________________________________________\n");
        printf("Digite o ID do conjunto: ");
        scanf("%d",&j);
        if(conjuntoExiste(&C[j], j) == 0){
            break;
        }
        printf("Digite o numero a ser excluido do conjunto %d: ",j);
        scanf("%d",&k);
        retorno = excluirElementoConjunto(k,&C[j]);   
        if(retorno == 1){
            printf("Elemento excluído com sucesso!\nPressione qualquer tecla para continuar...");
            getchar();
            getchar();
            printf("\n\n\n\n");
        }
        else{
            printf("Não foi possivel excluir o elemento do conjunto\n");
            printf("Pressione qualquer tecla para continuar...");
            getchar();
            getchar();
            printf("\n\n\n\n");
        }
        break;
    case 5:
        printf("___________________________________________________\n");
        printf("Digite o ID do conjunto: ");
        scanf("%d",&j);
        if(conjuntoExiste(&C[j], j) == 0){
            break;
        }
        printf("A cardinalidade do conjunto é: %d\n",tamanhoConjunto(&C[j]));
        printf("___________________________________________________\n");
        printf("Pressione qualquer tecla para continuar...");
        getchar();
        getchar();
        printf("\n\n\n\n");
        break;
    case 6:
        printf("___________________________________________________\n");
        printf("Digite o ID do conjunto: ");
        scanf("%d",&j);
        if(conjuntoExiste(&C[j], j) == 0){
            break;
        }
        printf("Digite o numero para comparação: ");
        scanf("%d",&k);
        printf("Numero de elementos que são maiores que %d: %d\n",k,maior(k, &C[j]));
        printf("___________________________________________________\n");
        printf("Pressione qualquer tecla para continuar...");
        getchar();
        getchar();
        printf("\n\n\n\n");
        break;
    case 7:
        printf("___________________________________________________\n");
        printf("Digite o ID do conjunto: ");
        scanf("%d",&j);
        if(conjuntoExiste(&C[j], j) == 0){
            break;
        }
        printf("Digite o numero para comparacao: ");
        scanf("%d",&k);
        printf("Numero de elementos que são menores que %d: %d\n",k,menor(k, &C[j]));
        printf("___________________________________________________\n");
        printf("Pressione qualquer tecla para continuar...");
        getchar();
        getchar();
        printf("\n\n\n\n");
        break;
    case 8:
        printf("___________________________________________________\n");
        printf("Digite o ID do conjunto: ");
        scanf("%d",&j);
        if(conjuntoExiste(&C[j], j) == 0){
            break;
        }
        printf("Digite o numero para comparacao: ");
        scanf("%d",&k);
        if(pertenceConjunto(k, &C[j]) == 0){
            printf("O numero %d não pertence ao conjunto %d\n",k,j);
        }
        else{
            printf("O numero %d pertence ao conjunto %d\n",k,j);
        }
        printf("___________________________________________________\n");
        printf("Pressione qualquer tecla para continuar...");
        getchar();
        getchar();
        printf("\n\n\n\n");
        break;
    case 9:
        printf("___________________________________________________\n");
        printf("Digite o ID do primeiro conjunto: ");
        scanf("%d",&j);
        if(conjuntoExiste(&C[j], j) == 0){
            break;
        }
        printf("Digite o ID do segundo conjunto: ");
        scanf("%d",&k);
        if(conjuntoExiste(&C[k], k) == 0){
            break;
        }
        if(conjuntosIdenticos(&C[k], &C[j]) == 0){
            printf("Os conjuntos não são identicos\n");
        }
        else{
            printf("Os conjuntos são identicos\n");
        }
        printf("___________________________________________________\n");
        printf("Pressione qualquer tecla para continuar...");
        getchar();
        getchar();
        printf("\n\n\n\n");
        break;
    case 10:
        printf("___________________________________________________\n");
        printf("Digite o ID do primeiro conjunto: ");
        scanf("%d",&j);
        if(conjuntoExiste(&C[j], j) == 0){
            break;
        }
        printf("Digite o ID do segundo conjunto: ");
        scanf("%d",&k);
        if(conjuntoExiste(&C[k], k) == 0){
            break;
        }
        if(subconjunto(&C[j], &C[k]) == 0){
            printf("O conjunto %d não e subconjunto do conjunto %d\n",j,k);
        }
        else{
            printf("O conjunto %d é subconjunto do conjunto %d\n",j,k);
        }
        printf("___________________________________________________\n");
        printf("Pressione qualquer tecla para continuar...");
        getchar();
        getchar();
        printf("\n\n\n\n");
        break;
    case 11:
        
        break;
    case 12:
        
        break;
    case 13:
        
        break;
    case 14:
        
        break;
    case 15:
        
        break;
    case 16:
        printf("___________________________________________________\n");
        printf("Digite o ID do conjunto: ");
        scanf("%d",&j);
        if(conjuntoExiste(&C[j], j) == 0){
            break;
        }
        int ordenacao;
        printf("Digite a ordem de ordenacao \n1 - CRESCENTE ou  2 - DECRESCENTE: ");
        scanf("%d",&ordenacao);
        printf("\nConjunto ordenado:\n");
        mostraConjunto(&C[j],ordenacao);
        printf("___________________________________________________\n");
        printf("Pressione qualquer tecla para continuar...");
        getchar();
        getchar();
        printf("\n\n\n\n");
        break;
    case 17:
        
        break;
    case 18:
        
        break;
    
    default:
        printf("Opcao invalida!\n");
        break;
    }
    }
    return 0;
}

int conjuntoExiste(Conjunto *C, int j){
    if (j >= i){
        printf("Esse conjunto nao existe!\n");
        printf("___________________________________________________\n");
        printf("Pressione qualquer tecla para continuar...");
        getchar();
        getchar();
        printf("\n\n\n\n");
        return 0;
    }
    return 1;
}

int criaConjunto(Conjunto *C){
    C = malloc(sizeof(Conjunto));
    if(C == NULL){
        return 0;
    }
    C->v = (int*)malloc( 2 * sizeof(int));
    if(C->v == NULL){
        return 0;
    }
    C->chave = 0;
    return 1;
}

int conjuntoVazio(Conjunto *C){
    int i;
    for(i = 0; i < C->chave; i++){
        if(C->v != NULL){
            return 0;
        }
    }
    return 1;
}

int insereElementoConjunto(elem x, Conjunto *C){
    if(C == NULL){
        return 0;
    }
    if(x >= LONG_MAX || x < 0){
        return 0;
    }
    C->v = (int *)realloc(C->v, (C->chave + 1) * sizeof(int));
    if(C->v == NULL){
        return 0;
    }
    
    C->v [C->chave] = x;
    C->chave += 1;
    return 1;
}

int excluirElementoConjunto(elem x, Conjunto *C){
    if(x >= LONG_MAX || x < 0){
        return 0;
    }
    int i;
    int j;
    for(i = 0; i < C->chave; i++){
        if(C->v[i] == x){
            for(j = i; j < C->chave; j++){
                C->v[j] = C->v[j+1];
            }
        }
    }
    C->chave -= 1;
    return 1;
}

int tamanhoConjunto(Conjunto *C){
    return C->chave;
}

int maior(elem x,Conjunto *C){
    int i, aux = 0;
    for(i = 0; i < C->chave; i++){
        if(C->v[i] > x){
            aux ++;
        }
    }
    if(tamanhoConjunto(C) == 0){
        return 0;
    }
    return aux;
}

int menor(elem x,Conjunto *C){
    int i, aux = 0;
    for(i = 0; i < C->chave; i++){
        if(C->v[i] < x){
            aux ++;
        }
    }
    if(tamanhoConjunto(C) == 0){
        return 0;
    }
    return aux;
}

int pertenceConjunto(elem x, Conjunto *C){
    if(x >= LONG_MAX || x < 0){
        return 0;
    }
    int i;
    for(i = 0; i < C->chave; i++){
        if(C->v[i] == x){
            return 1;
        }
    }
    return 0;
}

int conjuntosIdenticos(Conjunto *C1,Conjunto *C2){
    int i;
    if(tamanhoConjunto(C1) != tamanhoConjunto(C2)){
        return 0;
    }
    for(i = 0; i < C1->chave; i++){
        if(C1->v[i] != C2->v[i]){
            return 0;
        }
    }
    return 1;
}

int subconjunto(Conjunto *C1, Conjunto* C2){
    int i;
    for(i = 0; i < C1->chave; i++){
        if(pertenceConjunto(C1->v[i], C2) == 0){
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
    for(i = 0; i < C2->chave; i++){
        if(!pertenceConjunto(C2->v[i], C1)){
            C3->v[C3->chave] = C2->v[i];
            C3->chave ++;
        }
    }
    return C3;
}

Conjunto* uniao(Conjunto *C1, Conjunto *C2){
    Conjunto *C3;
    criaConjunto(C3);
    int i;
    for(i = 0; i < C1->chave; i++){
        C3->v[C3->chave] = C1->v[i];
        C3->chave ++;
    }
    for(i = 0; i < C2->chave; i++){
        C3->v[C3->chave] = C2->v[i];
        C3->chave ++;
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
    for(i = 0; i < C1->chave; i++){
        if(pertenceConjunto(C1->v[i], C2)){
            C3->v[C3->chave] = C1->v[i];
            C3->chave ++;
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
    for(i = 0; i < C1->chave; i++){
        if(!pertenceConjunto(C1->v[i], C2)){
            C3->v[C3->chave] = C1->v[i];
            C3->chave ++;
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

void mostraConjunto(Conjunto *C, int ordem){
    Conjunto *A;
    criaConjunto(A);
    A = C;
    if(ordem == 1){
        quick_sort_crescente(A, 0, A->chave -1);
    }
    else{
        quick_sort_decrescente(A, 0, A->chave -1);
    }
    int i;
    for(i = 0; i < A->chave; i++){
        printf("%d\n", A->v[i]);
    }
}

int copiarConjunto(Conjunto *C1, Conjunto *C2){
    int i;
    if(conjuntoVazio(C1)){
        return 0;
    }
    for(i = 0; i < C1->chave; i++){
        C2->v[C2->chave] = C1->v[i];
        C2->chave ++;
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