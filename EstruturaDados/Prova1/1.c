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
    if ((*d) == NULL) {
        return (FALHA);
    } else {
        (*d) = (Apontador)NULL;
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

int MostraLista(Apontador *d) {
    Apontador r;
    if (d == NULL) {
        return FALHA;
    } else {
        r = (*d);
        printf("Imprimindo a lista:\n#---------------------#\n");
        while (r->prox != NULL) {
            printf("[%f]\n", r->dado);
            r = r->prox;
        }
        printf("[%f]\n", r->dado);
        printf("#---------------------#\n");
        return SUCESSO;
    }
}
int InsereMeio(Apontador *d, int chave, float dado) {
    Apontador q, r;
    struct Nodo node;
    node.chave = chave;
    node.dado = dado;
    q = (Apontador)malloc(sizeof(struct Nodo));
    if (q == NULL) {
        return (FALHA);
    }
    q->chave = chave;
    q->dado = dado;
    int tam = TamanhoLista(d);
    int i, j = tam / 2;
    r = (*d);
    if(tam == 1){
        InsInicio(d,node);
        return SUCESSO;
    }
    for (i = 0; i < j; i++) {
        r = r->prox;
    }
    q->prox = r;
    r = (*d);
    for (i = 0; i < j - 1; i++) {
        r = r->prox;
    }
    r->prox = q;
    return SUCESSO;
}
int main() {
    Apontador q;
    struct Nodo nodo;
    int chave;
    CriarListaVazia(&q);

    nodo.chave = 0;
    nodo.dado = 45;
    InsInicio(&q, nodo);

    nodo.chave = 1;
    nodo.dado = 658;
    InsFinal(&q, nodo);

    nodo.chave = 2;
    nodo.dado = 98745;
    InsFinal(&q, nodo);

    nodo.chave = 3;
    nodo.dado = 555;
    InsFinal(&q, nodo);

    nodo.chave = 4;
    nodo.dado = 4333;
    InsFinal(&q, nodo);

    nodo.chave = 5;
    nodo.dado = 99999;
    InsFinal(&q, nodo);

    nodo.chave = 6;
    nodo.dado = 77777;
    InsFinal(&q, nodo);

    InsereMeio(&q, 7, 99);

    MostraLista(&q);
    RemoverLista(&q);
    return 0;
}