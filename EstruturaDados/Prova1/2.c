/*Gustavo Antunes Rocha*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 1
#define FALHA -1
#define CHAVE_INVALIDA 0

typedef struct Produto* ApontadorProduto;

typedef struct Descritor* ApontadorDescritor;

struct Descritor{
    ApontadorProduto prim;
    int tam;
    ApontadorProduto ult;
} Descritor;

struct Produto{
    ApontadorProduto ant;
    int codigo;
    int chave;
    ApontadorProduto prox;
} Produto;

int Iguais(ApontadorDescritor p1, ApontadorDescritor p2, ApontadorDescritor* p3);
int PertenceLista(ApontadorDescritor p1, int codigo);
int CriarListaVazia(ApontadorDescritor* d);
int CriarListaChave(ApontadorDescritor* d, struct Produto produto);
int InsInicio(ApontadorDescritor* d, struct Produto produto);
int InsFinal(ApontadorDescritor* d, struct Produto produto);
int InsOrdem(ApontadorDescritor* d, struct Produto produto);
int RemInicio(ApontadorDescritor* d);
int RemFinal(ApontadorDescritor* d);
int RemChave(ApontadorDescritor* d, int chave);
int TamLista(ApontadorDescritor* d);
void MostraLista(ApontadorDescritor* d);
int RemValor(ApontadorDescritor* d);

int main(){
    ApontadorDescritor p1, p2;
    int chave, codigo;
    struct Produto produtoAuxiliar;
    CriarListaVazia(&p1);
    int elemLista1 = 0, elemLista2 = 0, i = 0;
    while (1){
        scanf("%d", &elemLista1);
        if (elemLista1 == -1){
            break;
        }
        produtoAuxiliar.chave = i;
        produtoAuxiliar.codigo = elemLista1;
        InsOrdem(&p1, produtoAuxiliar);
        i++;
    }
    i = 0;
    CriarListaVazia(&p2);
    while (1){
        scanf("%d", &elemLista2);
        if (elemLista2 == -1){
            break;
        }
        produtoAuxiliar.chave = i;
        produtoAuxiliar.codigo = elemLista2;
        InsOrdem(&p2, produtoAuxiliar);
        i++;
    }
    ApontadorDescritor p3;
    CriarListaVazia(&p3);
    int count;
    count = Iguais(p1, p2, &p3);
    if (p3->tam == 0){
        printf("iguais %d", count);
    }
    else{
        printf("diferentes ");
        MostraLista(&p3);
    }
    free(p1);
    free(p2);
    free(p3);
    return 1;
}
int Iguais(ApontadorDescritor p1, ApontadorDescritor p2, ApontadorDescritor* p3){
    int i, count = 1;
    ApontadorProduto r1, r2;
    struct Produto produto;
    if (p1->tam == 0 && p2->tam != 0){
        (*p3) = p2;
        return FALHA;
    }
    else if (p2->tam == 0 && p1->tam != 0){
        (*p3) = p1;
        return FALHA;
    }
    if (p1->tam >= p2->tam){
        r1 = p1->prim;
        while (r1 != NULL){
            
            if (PertenceLista(p2, r1->codigo) == FALHA){
                produto.chave = r1->chave;
                produto.codigo = r1->codigo;
                InsFinal(p3, produto);
            }
            if(r1->prox == NULL){
                break;
            }
            if(r1->codigo != r1->prox->codigo){
                count ++;
            }
            r1 = r1->prox;
        }
        return count;
    }

    if (p1->tam < p2->tam){
        r2 = p2->prim;
        while (r2 != NULL){
            
            if (PertenceLista(p1, r2->codigo) == FALHA){
                produto.chave = r2->chave;
                produto.codigo = r2->codigo;
                InsFinal(p3, produto);
            }
            if(r2->prox == NULL){
                break;
            }
            if(r2->codigo != r2->ant->codigo){
                count ++;
            }
            r2 = r2->prox;
        }
        return count;
    }
}

int PertenceLista(ApontadorDescritor p1, int codigo){
    ApontadorProduto r;
    r = p1->prim;
    while (r != NULL){
        if (r->codigo == codigo){
            return SUCESSO;
        }
        r = r->prox;
    }
    return FALHA;
}

void MostraLista(ApontadorDescritor* d){
    ApontadorProduto r;
    int i;
    r = (*d)->prim;
    for (i = 0; i < (*d)->tam; i++){
        printf("%d ", r->codigo);
        r = r->prox;
    }
}

int CriarListaVazia(ApontadorDescritor* d){
    (*d) = (ApontadorDescritor)malloc(sizeof(struct Descritor));
    if ((*d) == NULL){
        return (FALHA);
    }
    else{
        (*d)->prim = (ApontadorProduto)NULL;
        (*d)->tam = 0;
        (*d)->ult = (ApontadorProduto)NULL;
        return (SUCESSO);
    }
}

int CriarListaChave(ApontadorDescritor* d, struct Produto produto){
    int intResultado;

    intResultado = CriarListaVazia(d);
    if (intResultado == FALHA){
        return (FALHA);
    }
    else{
        return (InsInicio(d, produto));
    }
}

int InsInicio(ApontadorDescritor* d, struct Produto produto){
    ApontadorProduto q;

    q = (ApontadorProduto)malloc(sizeof(Produto));
    if (q == NULL){
        return (FALHA);
    }
    else{
        q->chave = produto.chave;
        q->codigo = produto.codigo;
        q->ant = (ApontadorProduto)NULL;
        q->prox = (*d)->prim;

        if ((*d)->tam == 0){
            (*d)->prim = q;
            (*d)->ult = q;
        }
        else{
            ((*d)->prim)->ant = q;
            (*d)->prim = q;
        }
        (*d)->tam++;
        return (SUCESSO);
    }
}

int InsFinal(ApontadorDescritor* d, struct Produto produto){
    ApontadorProduto q;

    if ((*d)->tam == 0){
        return (InsInicio(d, produto));
    }
    else{
        q = (ApontadorProduto)malloc(sizeof(Produto));
        if (q == NULL){
            return (FALHA);
        }
        else{
            q->chave = produto.chave;
            q->codigo = produto.codigo;
            q->prox = (ApontadorProduto)NULL;
            q->ant = (*d)->ult;

            ((*d)->ult)->prox = q;
            (*d)->ult = q;
            (*d)->tam++;

            return (SUCESSO);
        }
    }
}

int InsOrdem(ApontadorDescritor* d, struct Produto produto){
    ApontadorProduto q, r;

    if ((*d)->tam == 0){
        return (InsInicio(d, produto));
    }
    else{
        if (produto.codigo < (*d)->prim->codigo){
            return (InsInicio(d, produto));
        }
        if (produto.codigo >= (*d)->ult->codigo){
            return (InsFinal(d, produto));
        }
        q = (ApontadorProduto)malloc(sizeof(Produto));
        if (q == NULL){
            return (FALHA);
        }
        else{
            q->chave = produto.chave;
            q->codigo = produto.codigo;
            r = (*d)->prim;
            while ((r->codigo <= produto.codigo)){
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

int RemInicio(ApontadorDescritor* d){
    ApontadorProduto q;

    if ((*d)->tam == 0){
        return (FALHA);
    }
    else{
        if ((*d)->tam == 1){
            q = (*d)->prim;
            (*d)->prim = (ApontadorProduto)NULL;
            (*d)->ult = (ApontadorProduto)NULL;
        }
        else{
            q = (*d)->prim;
            (*d)->prim = q->prox;
            ((*d)->prim)->ant = (ApontadorProduto)NULL;
        }
        free(q);
        (*d)->tam--;
        return (SUCESSO);
    }
}

int RemFinal(ApontadorDescritor* d){
    ApontadorProduto q;
    if ((*d)->tam == 0){
        return (FALHA);
    }
    else{
        if ((*d)->tam == 1){
            return (RemInicio(d));
        }
        else{
            q = (*d)->ult;
            (*d)->ult = q->ant;
            ((*d)->ult)->prox = (ApontadorProduto)NULL;
            free(q);
            (*d)->tam--;
            return (SUCESSO);
        }
    }
}

int RemChave(ApontadorDescritor* d, int chave){
    ApontadorProduto r;

    if ((*d)->tam == 0){
        return (FALHA);
    }
    else{
        if ((*d)->tam == 1){
            if (((*d)->prim)->chave == chave){
                return (RemInicio(d));
            }
            else{
                return (FALHA);
            }
        }
        else{
            if (((*d)->prim)->chave == chave){
                return (RemInicio(d));
            }
            else{
                if (((*d)->ult)->chave == chave){
                    return (RemFinal(d));
                }
                else{
                    r = (*d)->prim;
                    while ((r->chave != chave) && (r->prox != NULL)){
                        r = r->prox;
                    }
                    if (r->prox == NULL){
                        return (FALHA);
                    }
                    else{
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

int TamLista(ApontadorDescritor* d){
    return ((*d)->tam);
}