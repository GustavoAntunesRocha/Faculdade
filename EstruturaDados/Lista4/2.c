/*Gustavo Antunes Rocha*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 1
#define FALHA -1
#define CHAVE_INVALIDA 0

typedef struct Crianca *ApontadorCrianca;

typedef struct Descritor *ApontadorDescritor;

struct Descritor {
    ApontadorCrianca prim;
    int tam;
    ApontadorCrianca ult;
} Descritor;

struct Crianca {
    ApontadorCrianca ant;
    char nome[31];
    int valor;
    int chave;
    ApontadorCrianca prox;
} Crianca;

int CriarListaVazia(ApontadorDescritor *d);
int CriarListaChave(ApontadorDescritor *d, struct Crianca crianca);
int InsInicio(ApontadorDescritor *d, struct Crianca crianca);
int InsFinal(ApontadorDescritor *d, struct Crianca crianca);
int InsOrdem(ApontadorDescritor *d, struct Crianca crianca);
int RemInicio(ApontadorDescritor *d);
int RemFinal(ApontadorDescritor *d);
int RemChave(ApontadorDescritor *d, int chave);
int TamLista(ApontadorDescritor *d);
void MostraLista(ApontadorDescritor *d);
int RemValor(ApontadorDescritor *d);

int main() {
    ApontadorDescritor d;
    int nCriancas, valor, i;
    char nome[31];
    struct Crianca criancaAuxiliar;

    CriarListaVazia(&d);

    scanf("%d", &nCriancas);
    scanf("%s", nome);
    scanf("%d", &valor);
    strcpy(criancaAuxiliar.nome, nome);
    criancaAuxiliar.valor = valor;
    criancaAuxiliar.chave = 0;
    CriarListaChave(&d, criancaAuxiliar);

    for (i = 1; i < nCriancas; i++) {
        scanf("%s", nome);
        scanf("%d", &valor);
        strcpy(criancaAuxiliar.nome, nome);
        criancaAuxiliar.valor = valor;
        criancaAuxiliar.chave = i;
        InsFinal(&d, criancaAuxiliar);
    }
    RemValor(&d);
    MostraLista(&d);
    free(d);
}

void MostraLista(ApontadorDescritor *d) {
    ApontadorCrianca r;
    int i;
    if ((*d)->tam == 0) {
        printf("A lista esta VAZIA.\n\n");
    } else {
        r = (*d)->prim;
        for (i = 0; i < (*d)->tam; i++) {
            printf("%s",r->nome);
            r = r->prox;
        }
    }
}

int CriarListaVazia(ApontadorDescritor *d) {
    (*d) = (ApontadorDescritor)malloc(sizeof(struct Descritor));
    if ((*d) == NULL) {
        return (FALHA);
    } else {
        (*d)->prim = (ApontadorCrianca)NULL;
        (*d)->tam = 0;
        (*d)->ult = (ApontadorCrianca)NULL;
        return (SUCESSO);
    }
}

int CriarListaChave(ApontadorDescritor *d, struct Crianca crianca) {
    int intResultado;

    intResultado = CriarListaVazia(d);
    if (intResultado == FALHA) {
        return (FALHA);
    } else {
        return (InsInicio(d, crianca));
    }
}

int InsInicio(ApontadorDescritor *d, struct Crianca crianca) {
    ApontadorCrianca q;

    q = (ApontadorCrianca)malloc(sizeof(Crianca));
    if (q == NULL) {
        return (FALHA);
    } else {
        q->chave = crianca.chave;
        strcpy(q->nome, crianca.nome);
        q->valor = crianca.valor;
        q->ant = (ApontadorCrianca)NULL;
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

int InsFinal(ApontadorDescritor *d, struct Crianca crianca) {
    ApontadorCrianca q;

    if ((*d)->tam == 0) {
        return (InsInicio(d, crianca));
    } else {
        q = (ApontadorCrianca)malloc(sizeof(Crianca));
        if (q == NULL) {
            return (FALHA);
        } else {
            q->chave = crianca.chave;
            strcpy(q->nome, crianca.nome);
            q->valor = crianca.valor;
            q->prox = (*d)->prim;
            q->ant = (*d)->ult;
            (*d)->prim->ant = q;

            ((*d)->ult)->prox = q;
            (*d)->ult = q;
            (*d)->tam++;

            return (SUCESSO);
        }
    }
}

int RemInicio(ApontadorDescritor *d) {
    ApontadorCrianca q;

    if ((*d)->tam == 0) {
        return (FALHA);
    } else {
        if ((*d)->tam == 1) {
            q = (*d)->prim;
            (*d)->prim = (ApontadorCrianca)NULL;
            (*d)->ult = (ApontadorCrianca)NULL;
        } else {
            q = (*d)->prim;
            (*d)->prim = q->prox;
            ((*d)->prim)->ant = (*d)->ult;
        }
        free(q);
        (*d)->tam--;
        return (SUCESSO);
    }
}

int RemFinal(ApontadorDescritor *d) {
    ApontadorCrianca q;
    if ((*d)->tam == 0) {
        return (FALHA);
    } else {
        if ((*d)->tam == 1) {
            return (RemInicio(d));
        } else {
            q = (*d)->ult;
            (*d)->ult = q->ant;
            ((*d)->ult)->prox = (*d)->prim;
            free(q);
            (*d)->tam--;
            return (SUCESSO);
        }
    }
}

int RemValor(ApontadorDescritor *d) {
    ApontadorCrianca r;
    int i, valor = (*d)->prim->valor;
    if ((*d)->tam == 0) {
        return (FALHA);
    } else {
        while ((*d)->tam > 1) {
            r = (*d)->prim;
            r = r->prox;
            if (valor % 2 != 0) {
                for (i = 1; i < valor; i++) {
                    r = r->prox;
                }
            } else {
                for (i = 0; i < valor; i++) {
                    r = r->ant;
                }
            }
            
            valor = r->valor;
            RemChave(d, r->chave);
        }
        return (SUCESSO);
    }
}

int RemChave(ApontadorDescritor *d, int chave) {
    ApontadorCrianca r;

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