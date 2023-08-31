// http://www.teachsolaisgames.com/articles/balanced_left_leaning.html

#include <stdio.h>
#include <stdlib.h>
//#include "ArvoreLLRB.h" //inclui os Prot�tipos

#define RED 1
#define BLACK 0

typedef struct ArvLLRB No;
struct ArvLLRB{
    int dado;
    No *esq;
    No *dir;
    int cor;
};

// =================================
// CRIA��O DA ARVORE
// =================================
 No* cria_ArvLLRB(){
     No* raiz = ( No*) malloc(sizeof(No));
    if(raiz != NULL){
        raiz = NULL;
    }
    return raiz;
}
// =================================
// LIBERAR
// =================================
void libera_no(No* no){
    if(no == NULL)
        return;
    libera_no(no->esq);
    libera_no(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvLLRB( No **raiz){
    if(raiz == NULL)
        return;
    libera_no(*raiz);//libera cada n�
    free(raiz);//libera a raiz
}
// =================================
// CONSULTA �RVORE
// =================================
int busca_no( No **raiz, int valor){
    if(raiz == NULL)
        return 0;
    No* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->dado){
            return 1;
        }
        if(valor > atual->dado)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}
// =================================
// ROTA��O
// =================================
No* rotacionaEsquerda(No* A){
    No* B = A->dir;
    A->dir = B->esq;
    B->esq = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

No* rotacionaDireita(No* A){
    No* B = A->esq;
    A->esq = B->dir;
    B->dir = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}
// =================================
// PROPRIEDADES
// =================================
int cor( No* H){
    if(H == NULL)
        return BLACK;
    else
        return H->cor;
}

void trocaCor( No* H){
    H->cor = !H->cor;
    if(H->esq != NULL)
        H->esq->cor = !H->esq->cor;
    if(H->dir != NULL)
        H->dir->cor = !H->dir->cor;
}

// =================================
// INSERCAO
// =================================
 No* insere_no( No* H, int valor, int *resp){
    if(H == NULL){
         No *novo;
        novo = ( No*)malloc(sizeof( No));
        if(novo == NULL){
            *resp = 0;
            return NULL;
        }

        novo->dado = valor;
        novo->cor = RED;
        novo->dir = NULL;
        novo->esq = NULL;
        *resp = 1;
        return novo;
    }

    if(valor == H->dado)
        *resp = 0;// Valor duplicado
    else{
        if(valor < H->dado)
            H->esq =  insere_no(H->esq,valor,resp);
        else
            H->dir =  insere_no(H->dir,valor,resp);
    }

    //n� Vermelho � sempre filho � esquerda
    if(cor(H->dir) == RED && cor(H->esq) == BLACK)
        H = rotacionaEsquerda(H);

    //Filho e Neto s�o vermelhos
    //Filho vira pai de 2 n�s vermelhos
    if(cor(H->esq) == RED && cor(H->esq->esq) == RED)
        H = rotacionaDireita(H);

    //2 filhos Vermelhos: troca cor!
    if(cor(H->esq) == RED && cor(H->dir) == RED)
        trocaCor(H);

    return H;
}

int insere_ArvLLRB( No **raiz, int valor){
    int resp;

    *raiz =  insere_no(*raiz,valor,&resp);
    if((*raiz) != NULL)
        (*raiz)->cor = BLACK;

    return resp;
}
// =================================
// REMO��O
// =================================
 No* balancear( No* H){
    //n� Vermelho � sempre filho � esquerda
    if(cor(H->dir) == RED)
        H = rotacionaEsquerda(H);

    //Filho da direita e neto da esquerda s�o vermelhos
    //if(H->esq != NULL && cor(H->dir) == RED && cor(H->esq->esq) == RED)

    //Filho da esquerda e neto da esquerda s�o vermelhos
    if(H->esq != NULL && cor(H->esq) == RED && cor(H->esq->esq) == RED)
        H = rotacionaDireita(H);

    //2 filhos Vermelhos: troca cor!
    if(cor(H->esq) == RED && cor(H->dir) == RED)
        trocaCor(H);

    return H;
}

 No* move2EsqRED( No* H){
    trocaCor(H);
    if(cor(H->dir->esq) == RED){
        H->dir = rotacionaDireita(H->dir);
        H = rotacionaEsquerda(H);
        trocaCor(H);
    }
    return H;
}

 No* move2DirRED( No* H){
    trocaCor(H);
    if(cor(H->esq->esq) == RED){
        H = rotacionaDireita(H);
        trocaCor(H);
    }
    return H;
}

 No* removerMenor( No* H){
    if(H->esq == NULL){
        free(H);
        return NULL;
    }
    if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK)
        H = move2EsqRED(H);

    H->esq = removerMenor(H->esq);
    return balancear(H);
}

// tirei a recurs�o, assim fica igual a usada na AVL
 No* procuraMenor( No* atual){
     No *no1 = atual;
     No *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

 No* remover( No* H, int valor){
    if(valor < H->dado){
        if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK)
            H = move2EsqRED(H);

        H->esq = remover(H->esq, valor);
    }else{
        if(cor(H->esq) == RED)
            H = rotacionaDireita(H);

        if(valor == H->dado && (H->dir == NULL)){
            free(H);
            return NULL;
        }

        if(cor(H->dir) == BLACK && cor(H->dir->esq) == BLACK)
            H = move2DirRED(H);

        if(valor == H->dado){
             No* x = procuraMenor(H->dir);
            H->dado = x->dado;
            H->dir = removerMenor(H->dir);
        }else
            H->dir = remover(H->dir, valor);
    }
    return balancear(H);
}

int remove_no(No **raiz, int valor){
    if(busca_no(raiz,valor)){
         No* h = *raiz;
        *raiz = remover(h,valor);
        if(*raiz != NULL)
            (*raiz)->cor = BLACK;
        return 1;
    }else
    {
        printf("Nao foi possivel remover o no\n");
        return 0;
    }
}
// =================================
// PROPRIEDADES �RVORE
// =================================
int estaVazia_ArvLLRB( No **raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int quantidade_de_no(No **raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;

    int alt_esq = quantidade_de_no(&((*raiz)->esq));
    int alt_dir = quantidade_de_no(&((*raiz)->dir));
    return (alt_esq + alt_dir + 1);
}

int altura_arvore( No **raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_arvore(&((*raiz)->esq));
    int alt_dir = altura_arvore(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

void imprimir(No *root,int esp)
{
if(root)
{
    esp+=10;
    imprimir(root->dir,esp);
    printf("\n\n");
        for(int i= 10; i<esp; i++)
        {
            printf(" ");
        }
    printf("%d(%d)",root->dado,root->cor);
    imprimir(root->esq,esp);
}
}


