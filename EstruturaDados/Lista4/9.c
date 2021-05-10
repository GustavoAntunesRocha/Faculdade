/*Gustavo Antunes Rocha*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 1
#define FALHA -1
#define CHAVE_INVALIDA 0

typedef struct Caminho* ApontadorCaminho;

typedef struct Descritor* ApontadorDescritor;

struct Descritor{
    ApontadorCaminho prim;
    int tam;
    ApontadorCaminho ult;
} Descritor;

struct Caminho{
    ApontadorCaminho ant;
    char instrucao[21];
    int chave;
    ApontadorCaminho prox;
} Caminho;

int ImprimeInstrucoes(ApontadorDescritor *d);
int CriarListaVazia(ApontadorDescritor* d);
int CriarListaChave(ApontadorDescritor* d, struct Caminho caminho);
int InsInicio(ApontadorDescritor* d, struct Caminho caminho);
int InsFinal(ApontadorDescritor* d, struct Caminho caminho);
int InsOrdem(ApontadorDescritor* d, struct Caminho caminho);
int RemInicio(ApontadorDescritor* d);
int RemFinal(ApontadorDescritor* d);
int RemChave(ApontadorDescritor* d, int chave);
int TamLista(ApontadorDescritor* d);
void MostraLista(ApontadorDescritor* d);

int main(){
    ApontadorDescritor p1[10];
    int chave, casosDeTeste;
    struct Caminho caminhoAuxiliar;
    char instrucao[21];
    int elemLista1 = 0, elemLista2 = 0, i = 0, j = 0;
    CriarListaVazia(&p1[j]);
    scanf("%d", &casosDeTeste);
    while (j != casosDeTeste){
        scanf("%s", instrucao);
        if(!strcmp(instrucao, "ESCOLA")){
            j++;
            CriarListaVazia(&p1[j]);
        }
        
        caminhoAuxiliar.chave = i;
        strcpy(caminhoAuxiliar.instrucao, instrucao);
        InsFinal(&p1[j], caminhoAuxiliar);
        i++;
    }
    for(i = 0; i < casosDeTeste; i++){
        ImprimeInstrucoes(&p1[i]);
    }
    return 1;
}

int ImprimeInstrucoes(ApontadorDescritor *d){
    ApontadorCaminho r;
    int i, aux = 0;
    char instrucao[21];
    r = (*d)->ult;
    for (i = 0; i < (*d)->tam ; i++){
        if(!strcmp(r->instrucao, "ESQUERDA")){
            strcpy(instrucao, "DIREITA");
            printf("Vire a %s ", instrucao);
        } else if(!strcmp(r->instrucao, "DIREITA")){
            strcpy(instrucao, "ESQUERDA");
            printf("Vire a %s ", instrucao);
        } else if(r == (*d)->prim){
            strcpy(instrucao, "CASA");
            printf("na sua %s.\n", instrucao);
            aux = 1;
        }
        else{
            printf("na rua %s.\n", r->instrucao);
        }
        r = r->ant;
    }
    if(aux == 0)
        printf("na sua CASA.\n");
}

void MostraLista(ApontadorDescritor* d){
    ApontadorCaminho r;
    int i;
    r = (*d)->prim;
    for (i = 0; i < (*d)->tam; i++){
        printf("%s\n", r->instrucao);
        r = r->prox;
    }
}

int CriarListaVazia(ApontadorDescritor* d){
    (*d) = (ApontadorDescritor)malloc(sizeof(struct Descritor));
    if ((*d) == NULL){
        return (FALHA);
    }
    else{
        (*d)->prim = (ApontadorCaminho)NULL;
        (*d)->tam = 0;
        (*d)->ult = (ApontadorCaminho)NULL;
        return (SUCESSO);
    }
}

int CriarListaChave(ApontadorDescritor* d, struct Caminho caminho){
    int intResultado;

    intResultado = CriarListaVazia(d);
    if (intResultado == FALHA){
        return (FALHA);
    }
    else{
        return (InsInicio(d, caminho));
    }
}

int InsInicio(ApontadorDescritor* d, struct Caminho caminho){
    ApontadorCaminho q;

    q = (ApontadorCaminho)malloc(sizeof(Caminho));
    if (q == NULL){
        return (FALHA);
    }
    else{
        q->chave = caminho.chave;
        strcpy(q->instrucao, caminho.instrucao);
        q->ant = (ApontadorCaminho)NULL;
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

int InsFinal(ApontadorDescritor* d, struct Caminho caminho){
    ApontadorCaminho q;

    if ((*d)->tam == 0){
        return (InsInicio(d, caminho));
    }
    else{
        q = (ApontadorCaminho)malloc(sizeof(Caminho));
        if (q == NULL){
            return (FALHA);
        }
        else{
            q->chave = caminho.chave;
            strcpy(q->instrucao, caminho.instrucao);
            q->prox = (ApontadorCaminho)NULL;
            q->ant = (*d)->ult;

            ((*d)->ult)->prox = q;
            (*d)->ult = q;
            (*d)->tam++;

            return (SUCESSO);
        }
    }
}

int InsOrdem(ApontadorDescritor* d, struct Caminho caminho){
    ApontadorCaminho q, r;

    if ((*d)->tam == 0){
        return (InsInicio(d, caminho));
    }
    else{
        if (caminho.instrucao < (*d)->prim->instrucao){
            return (InsInicio(d, caminho));
        }
        if (caminho.instrucao >= (*d)->ult->instrucao){
            return (InsFinal(d, caminho));
        }
        q = (ApontadorCaminho)malloc(sizeof(Caminho));
        if (q == NULL){
            return (FALHA);
        }
        else{
            q->chave = caminho.chave;
            strcpy(q->instrucao, caminho.instrucao);
            r = (*d)->prim;
            while ((r->instrucao <= caminho.instrucao)){
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
    ApontadorCaminho q;

    if ((*d)->tam == 0){
        return (FALHA);
    }
    else{
        if ((*d)->tam == 1){
            q = (*d)->prim;
            (*d)->prim = (ApontadorCaminho)NULL;
            (*d)->ult = (ApontadorCaminho)NULL;
        }
        else{
            q = (*d)->prim;
            (*d)->prim = q->prox;
            ((*d)->prim)->ant = (ApontadorCaminho)NULL;
        }
        free(q);
        (*d)->tam--;
        return (SUCESSO);
    }
}

int RemFinal(ApontadorDescritor* d){
    ApontadorCaminho q;
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
            ((*d)->ult)->prox = (ApontadorCaminho)NULL;
            free(q);
            (*d)->tam--;
            return (SUCESSO);
        }
    }
}

int RemChave(ApontadorDescritor* d, int chave){
    ApontadorCaminho r;

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