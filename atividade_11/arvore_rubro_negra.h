typedef struct arvore_rubro_negra No;

struct arvore_rubro_negra
{
    int dado;
    No *direito;
    No *esquerdo;
    No *pai;
    int cor;
    int altura;
};

typedef struct raiz
{
    No *conteudo;
    int cor;
}Raiz;

Raiz *criar_raiz()
{   
    Raiz *temp_raiz = (Raiz *)malloc(sizeof(Raiz));
    temp_raiz->conteudo =NULL;
    temp_raiz->cor=0;

    return temp_raiz;
}
/*
void inserir_direito(int dado, No *no)
{
    if(no->direito == NULL)
    {
        No *temp_no = (No *)malloc(sizeof(No));

        temp_no->dado = dado;
        temp_no->direito = NULL;
        temp_no->esquerdo = NULL;
        temp_no->pai = no;
        temp_no->cor = 1;

        no->direito = temp_no;
    }
    else
    {
        if (dado > no->direito->dado)
            inserir_direito(dado, no->direito);
        
        if (dado < no->esquerdo->dado)
            inserir_esquerdo(dado, no->direito);
    }


}

void inserir_esquerdo(int dado, No *no)
{
    if(no->esquerdo == NULL)
    {
        No *temp_no = (No *)malloc(sizeof(No));

        temp_no->dado = dado;
        temp_no->direito = NULL;
        temp_no->esquerdo = NULL;
        temp_no->pai = no;
        temp_no->cor = 1;

        no->esquerdo = temp_no;
    }
    else
    {
        if (dado > no->direito->dado)
            inserir_direito(dado, no->esquerdo);
        
        if (dado < no->esquerdo->dado)
            inserir_esquerdo(dado, no->esquerdo);
    }

}

No * adicionar_no(int dado, Raiz *raiz)
{
    No *temp_no = (No *)malloc(sizeof(No));

    if (raiz->conteudo == NULL)
    {
        temp_no->dado=dado;
        temp_no->direito=NULL;
        temp_no->esquerdo=NULL;
        temp_no->cor=0;
        temp_no->pai=NULL;
        raiz->conteudo = temp_no;
    
    } 

    else{
        if (dado > raiz->conteudo->dado)
            inserir_direito(dado, raiz->conteudo);
        
        if (dado < raiz->conteudo->dado)
            inserir_esquerdo(dado, raiz->conteudo);
    }


}
*/

/*
void inserir_versao_3(No **raiz, int num){
    No *aux = *raiz;
    while(aux){
        if(num < aux->dado)
            raiz = &aux->esquerdo;
        else
            raiz = &aux->direito;
        aux = *raiz;
    }
    aux = malloc(sizeof(No));
    aux->dado = num;
    aux->esquerdo = NULL;
    aux->direito= NULL;
    aux->altura=0;
    *raiz = aux;
}
*/
No* criar_no(int dado)
{
    No *temp_no = (No *)malloc(sizeof(No));
    temp_no->dado=dado;
    temp_no->direito=NULL;
    temp_no->esquerdo=NULL;
    temp_no->cor=0;
    temp_no->pai=NULL;
    temp_no->altura=0;

    return temp_no;
}

No * inserir_no(No *no, int dado)
{
    if(no == NULL)
        no = criar_no(dado);
    else
    {
        if(dado > no->dado)
            no->direito = inserir_no(no->direito, dado);

        else
        {   if(dado < no->dado)
            no->esquerdo = inserir_no(no->esquerdo, dado);
            else
                printf("Esse dado jah estah guardado!!!\n\n");
        }
    }
    if(altura(no->direito) > altura(no->esquerdo))
        no->altura = no->direito->altura; 

    if(altura(no->direito) < altura(no->esquerdo))
        no->altura = no->esquerdo->altura; 
    
    return no;
}

int altura(No *no)
{
    if (no==NULL){
        return -1;
    }

    else
    {   
       return no->altura;     
    }
    
}

No* balancear_arvore(No *no)

void imprimir(No *no)
{
    if(no != NULL)
    {   
        imprimir(no->esquerdo);
        printf("%d ", no->dado);
        imprimir(no->direito);
    }
}
