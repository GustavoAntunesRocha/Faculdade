#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 1
#define FALHA -1

typedef struct Nodo *Apontador;

struct Nodo {
    unsigned int chave;
    float dado;
    Apontador prox;
};

Apontador prim;

int TamanhoLista(Apontador *d);

int CriarListaVazia(Apontador *d) {
    (*d) = (Apontador)malloc(sizeof(struct Nodo));
    printf("Teste 10\n");
    if ((*d) == NULL) {
        return (FALHA);
    } else {
        printf("Teste 11\n");
        (*d) = (Apontador)NULL;
        printf("Teste 12\n");
        //(*d)->prox = (Apontador)NULL;
        printf("Teste 13\n");
        return (SUCESSO);
    }
}

int InsInicio(Apontador *d, struct Nodo nodo) {
    Apontador q;
    q = (Apontador)malloc(sizeof(struct Nodo));
    if (q == NULL) {
        return (FALHA);
    } else {
        q->chave = nodo.chave;
        q->dado = nodo.dado;
        q->prox = (Apontador)(*d);
        (*d) = q;
        return (SUCESSO);
    }
}

int InsFinal(Apontador *d, struct Nodo nodo) {
    Apontador q, r;
    q = (Apontador)malloc(sizeof(struct Nodo));
    if (q == NULL) {
        return (FALHA);
    } else {
        q->chave = nodo.chave;
        q->dado = nodo.dado;
        q->prox = (Apontador)NULL;
        r = (*d);
        while (r->prox != NULL) {
            r = r->prox;
        }
        r->prox = q;
        return (SUCESSO);
    }
}

int TamanhoLista(Apontador *d) {
    Apontador r;
    int tam = 0;
    if (d == NULL) {
        return FALHA;
    }
    if ((*d) == NULL) {
        return 0;
    } else {
        tam = 1;
        r = (*d);
        while (r->prox != NULL) {
            tam++;
            r = r->prox;
        }
        return tam;
    }
}

int RemoverLista(Apontador *d) {
    while ((*d)->prox != NULL) {
        free(*d);
        (*d) = (*d)->prox;
    }
    return SUCESSO;
}

int MostraLista(Apontador *d){
    Apontador r;
    if (d == NULL) {
        return FALHA;
    } else{
        r = (*d);
        printf("\n#---------------------#\nImprimindo a lista:\n");
        while (r->prox != NULL)
        {
            printf("[%f]\n",r->dado);
            r = r->prox;
        }
        return SUCESSO;
        
    }
}

int main(){
    Apontador q;
    struct Nodo nodo;
    int chave;
    nodo.chave = 0;
    nodo.dado = 45;
    printf("Teste 1\n");
    CriarListaVazia(&q);
    printf("Teste 2\n");
    InsInicio(&q, nodo);
    printf("Teste 3\n");
    nodo.chave = 1;
    nodo.dado = 658;
    printf("Teste 4\n");
    InsFinal(&q, nodo);
    printf("Teste 5\n");
    nodo.chave = 2;
    nodo.dado = 98745;
    printf("Teste 6\n");
    InsFinal(&q, nodo);
    printf("Teste 7\n");
    MostraLista(&q);
    printf("Teste 8\n");
    RemoverLista(&q);
    printf("Teste 9\n");
    return 0;
}