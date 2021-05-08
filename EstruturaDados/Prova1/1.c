/* Gustavo Antunes Rocha*/

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

int TamanhoLista();

int CriarListaVazia() {
    prim = (Apontador)malloc(sizeof(struct Nodo));
    if (prim == NULL) {
        return (FALHA);
    } else {
        prim = (Apontador)NULL;
        return (SUCESSO);
    }
}

int InsInicio(struct Nodo nodo) {
    Apontador q;
    q = (Apontador)malloc(sizeof(struct Nodo));
    if (q == NULL) {
        return (FALHA);
    } else {
        q->chave = nodo.chave;
        q->dado = nodo.dado;
        q->prox = (Apontador)prim;
        prim = q;
        return (SUCESSO);
    }
}

int InsFinal(struct Nodo nodo) {
    if(prim == NULL){
        return InsInicio(nodo);
    }
    Apontador q, r;
    q = (Apontador)malloc(sizeof(struct Nodo));
    if (q == NULL) {
        return (FALHA);
    } else {
        q->chave = nodo.chave;
        q->dado = nodo.dado;
        q->prox = (Apontador)NULL;
        r = prim;
        while (r->prox != NULL) {
            r = r->prox;
        }
        r->prox = q;
        return (SUCESSO);
    }
}

int TamanhoLista() {
    Apontador r;
    int tam = 0;
    if (prim == NULL) {
        return 0;
    } else {
        tam = 1;
        r = prim;
        while (r->prox != NULL) {
            tam++;
            r = r->prox;
        }
        return tam;
    }
}

int RemoverLista() {
    while (prim->prox != NULL) {
        free(prim);
        prim = prim->prox;
    }
    return SUCESSO;
}

int MostraLista() {
    Apontador r;
    if (prim == NULL) {
        return FALHA;
    } else {
        r = prim;
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
int InsereMeio(int chave, float dado) {
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
    int tam = TamanhoLista();
    int i, j = tam / 2;
    r = prim;
    if (tam == 1 || tam == 0) {
        InsInicio(node);
        return SUCESSO;
    }
    for (i = 0; i < j; i++) {
        r = r->prox;
    }
    q->prox = r;
    r = prim;
    for (i = 0; i < j - 1; i++) {
        r = r->prox;
    }
    r->prox = q;
    return SUCESSO;
}
int RemInicio() {
    Apontador r;
    if (prim == NULL) {
        return FALHA;
    } else {
        r = prim;
        prim = prim->prox;
        free(r);
        return SUCESSO;
    }
}
int RemChave(int chave) {
    Apontador r, q;
    if (prim == NULL) {
        return FALHA;
    } else {
        int count = 0;
        r = prim;
        q = prim;
        if (r->prox == NULL) {
            if (r->chave == chave) {
                RemInicio();
                return SUCESSO;
            } else {
                return FALHA;
            }
        } else {
            if (r->chave == chave) {
                RemInicio();
                return SUCESSO;
            } else {
                while (r->prox != NULL && r->chave != chave) {
                    q = r;
                    r = r->prox;
                    count++;
                }
                if(r->chave == chave){
                    q->prox = r->prox;
                    free(r);
                    return SUCESSO;
                } else{
                    return FALHA;
                }
            }
        }
    }
}
int main() {
    Apontador q;
    struct Nodo nodo;
    int chave;
    CriarListaVazia();

    nodo.chave = 0;
    nodo.dado = 45;
    InsInicio(nodo);

    nodo.chave = 1;
    nodo.dado = 658;
    InsFinal(nodo);

    nodo.chave = 2;
    nodo.dado = 98745;
    InsFinal(nodo);

    nodo.chave = 3;
    nodo.dado = 555;
    InsFinal(nodo);

    nodo.chave = 4;
    nodo.dado = 4333;
    InsFinal(nodo);

    nodo.chave = 5;
    nodo.dado = 99999;
    InsFinal(nodo);

    nodo.chave = 6;
    nodo.dado = 77777;
    InsFinal(nodo);

    InsereMeio(7, 99);

    MostraLista();
    RemChave(3);
    printf("Após remover: \n");
    MostraLista();
    RemoverLista();
    return 0;
}