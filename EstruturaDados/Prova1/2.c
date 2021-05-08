/*Gustavo Antunes Rocha*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 1
#define FALHA -1
#define CHAVE_INVALIDA 0

typedef struct Produto *ApontadorProduto;

typedef struct Descritor *ApontadorDescritor;

struct Descritor {
    ApontadorProduto prim;
    int tam;
    ApontadorProduto ult;
} Descritor;

struct Produto {
    ApontadorProduto ant;
    int codigo;
    int chave;
    ApontadorProduto prox;
} Produto;

int CriarListaVazia(ApontadorDescritor *d);
int CriarListaChave(ApontadorDescritor *d, struct Produto produto);
int InsInicio(ApontadorDescritor *d, struct Produto produto);
int InsFinal(ApontadorDescritor *d, struct Produto produto);
int InsOrdem(ApontadorDescritor *d, struct Produto produto);
int RemInicio(ApontadorDescritor *d);
int RemFinal(ApontadorDescritor *d);
int RemChave(ApontadorDescritor *d, int chave);
int TamLista(ApontadorDescritor *d);
void MostraLista(ApontadorDescritor *d);
int RemValor(ApontadorDescritor *d);

int main() {
    ApontadorDescritor p1, p2;
    int chave, codigo;
    struct Produto produtoAuxiliar;
    CriarListaVazia(&p1);
    int elemLista1 = 0, elemLista2 = 0, i = 0;
    while (1) {
        scanf("%d", &elemLista1);
        if(elemLista1 == -1){
            break;
        }
        produtoAuxiliar.chave = i;
        produtoAuxiliar.codigo = elemLista1;
        InsOrdem(&p1, produtoAuxiliar);
        printf("\nLista 1: \n");
        MostraLista(&p1);
        i++;
    }
    i = 0;
    CriarListaVazia(&p2);
    while (1) {
        scanf("%d", &elemLista2);
        if(elemLista2 == -1){
            break;
        }
        produtoAuxiliar.chave = i;
        produtoAuxiliar.codigo = elemLista2;
        InsOrdem(&p2, produtoAuxiliar);
        printf("\nLista 2: \n");
        MostraLista(&p2);
        i++;
    }
    printf("\nLista 1: \n");
    MostraLista(&p1);
    printf("\nLista 2: \n");
    MostraLista(&p2);

    free(p1);
    free(p2);
    return 1;

}
void MostraLista(ApontadorDescritor *d) {
    ApontadorProduto r;
    int i;
    printf("\nLista:\n");
    if ((*d)->tam == 0) {
        printf("A lista esta VAZIA.\n\n");
    } else {
        r = (*d)->prim;
        for (i = 0; i < (*d)->tam; i++) {
            printf("[%d] ->", r->codigo);
            r = r->prox;
        }
        printf("\n");
    }
}

int CriarListaVazia(ApontadorDescritor *d) {
    (*d) = (ApontadorDescritor)malloc(sizeof(struct Descritor));
    if ((*d) == NULL) {
        return (FALHA);
    } else {
        (*d)->prim = (ApontadorProduto)NULL;
        (*d)->tam = 0;
        (*d)->ult = (ApontadorProduto)NULL;
        return (SUCESSO);
    }
}

int CriarListaChave(ApontadorDescritor *d, struct Produto produto) {
    int intResultado;

    intResultado = CriarListaVazia(d);
    if (intResultado == FALHA) {
        return (FALHA);
    } else {
        return (InsInicio(d, produto));
    }
}

int InsInicio(ApontadorDescritor *d, struct Produto produto) {
    ApontadorProduto q;

    q = (ApontadorProduto)malloc(sizeof(Produto));
    if (q == NULL) {
        return (FALHA);
    } else {
        q->chave = produto.chave;
        q->codigo = produto.codigo;
        q->ant = (ApontadorProduto)NULL;
        q->prox = (*d)->prim;

        if ((*d)->tam == 0) {
            (*d)->prim = q;
            (*d)->ult = q;
        } else {
            ((*d)->prim)->ant = q;
            (*d)->prim = q;
        }
        (*d)->tam++;
        return (SUCESSO);
    }
}

int InsFinal(ApontadorDescritor *d, struct Produto produto) {
    ApontadorProduto q;

    if ((*d)->tam == 0) {
        return (InsInicio(d, produto));
    } else {
        q = (ApontadorProduto)malloc(sizeof(Produto));
        if (q == NULL) {
            return (FALHA);
        } else {
            q->chave = produto.chave;
            q->codigo = produto.codigo;
            q->prox = (ApontadorProduto) NULL;
            q->ant = (*d)->ult;

            ((*d)->ult)->prox = q;
            (*d)->ult = q;
            (*d)->tam++;

            return (SUCESSO);
        }
    }
}

int InsOrdem(ApontadorDescritor *d, struct Produto produto) {
    ApontadorProduto q, r;

    if ((*d)->tam == 0) {
        return (InsInicio(d, produto));
    } else {
        if(produto.codigo < (*d)->prim->codigo){
            return (InsInicio(d, produto));
        }
        if(produto.codigo >= (*d)->ult->codigo){
            return (InsFinal(d, produto));
        }
        q = (ApontadorProduto)malloc(sizeof(Produto));
        if (q == NULL) {
            return (FALHA);
        } else {
            q->chave = produto.chave;
            q->codigo = produto.codigo;
            r = (*d)->prim;
            while ((r->codigo <= produto.codigo)) {
                r = r->prox;
            }
            
            q->prox = r;
            q->ant = r->ant;

            r->ant = q;
            q->ant->prox = q;

            (*d)->tam++;

            return (SUCESSO);
        }
    }
}

int RemInicio(ApontadorDescritor *d) {
    ApontadorProduto q;

    if ((*d)->tam == 0) {
        return (FALHA);
    } else {
        if ((*d)->tam == 1) {
            q = (*d)->prim;
            (*d)->prim = (ApontadorProduto)NULL;
            (*d)->ult = (ApontadorProduto)NULL;
        } else {
            q = (*d)->prim;
            (*d)->prim = q->prox;
            ((*d)->prim)->ant = (ApontadorProduto)NULL;
        }
        free(q);
        (*d)->tam--;
        return (SUCESSO);
    }
}

int RemFinal(ApontadorDescritor *d) {
    ApontadorProduto q;
    if ((*d)->tam == 0) {
        return (FALHA);
    } else {
        if ((*d)->tam == 1) {
            return (RemInicio(d));
        } else {
            q = (*d)->ult;
            (*d)->ult = q->ant;
            ((*d)->ult)->prox = (ApontadorProduto)NULL;
            free(q);
            (*d)->tam--;
            return (SUCESSO);
        }
    }
}

int RemChave(ApontadorDescritor *d, int chave) {
    ApontadorProduto r;

    if ((*d)->tam == 0) {
        return (FALHA);
    } else {
        if ((*d)->tam == 1) {
            if (((*d)->prim)->chave == chave) {
                return (RemInicio(d));
            } else {
                return (FALHA);
            }
        } else {
            if (((*d)->prim)->chave == chave) {
                return (RemInicio(d));
            } else {
                if (((*d)->ult)->chave == chave) {
                    return (RemFinal(d));
                } else {
                    r = (*d)->prim;
                    while ((r->chave != chave) && (r->prox != NULL)) {
                        r = r->prox;
                    }
                    if (r->prox == NULL) {
                        return (FALHA);
                    } else {
                        (r->ant)->prox = r->prox;
                        (r->prox)->ant = r->ant;
                        free(r);
                        (*d)->tam--;
                        return (SUCESSO);
                    }
                }
            }
        }
    }
}

int TamLista(ApontadorDescritor *d) {
    return ((*d)->tam);
}