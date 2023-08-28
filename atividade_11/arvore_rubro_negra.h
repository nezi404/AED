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

No *criar_raiz(int dado)
{   
    No *temp_raiz = (No *)malloc(sizeof(No));
    temp_raiz->esquerdo =NULL;
    temp_raiz->direito = NULL;
    temp_raiz->altura=0;
    temp_raiz->pai = NULL;
    temp_raiz->dado = dado;
    temp_raiz->cor = 0;

    return temp_raiz;
}

int altura(No * no)
{ 
    if (no != NULL)
        return no->altura;
    else
        return -1;
}

int maior(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int verifica_balancear(No *no)
{
    if (no != NULL)
    {
        return (altura(no->esquerdo) - altura(no->direito));
    }
    return 0;
}

No* rotacao_esquerda(No *no)
{
    No * temp_no_filho_esquerdo, * temp_no_direito;

    temp_no_direito = no->direito;
    temp_no_filho_esquerdo = temp_no_direito->esquerdo;

    temp_no_direito->esquerdo=no;
    no->direito = temp_no_filho_esquerdo;

    no->altura = maior(altura(no->direito), altura(no->esquerdo)) + 1;
    temp_no_direito->altura = maior(altura(temp_no_direito->direito), altura(temp_no_direito->esquerdo)) + 1;
    temp_no_direito->pai = no;
    no->pai = temp_no_direito;

    return temp_no_direito;
}

No* rotacao_direita(No *no)
{
    No * temp_no_filho_direito, * temp_no_esquerdo;

    temp_no_esquerdo = no->esquerdo;
    temp_no_filho_direito = temp_no_esquerdo->direito;

    temp_no_esquerdo->direito=no;
    no->esquerdo = temp_no_filho_direito;

    no->altura = maior(altura(no->direito), altura(no->esquerdo)) + 1;
    temp_no_esquerdo->altura = maior(altura(temp_no_esquerdo->direito), altura(temp_no_esquerdo->esquerdo)) + 1;
    temp_no_esquerdo->pai = no;
    no->pai = temp_no_esquerdo;

    return temp_no_esquerdo;
}
    
No* rotacao_direita_esquerda(No *no)
{
    no->direito = rotacao_direita(no->direito);

    return rotacao_esquerda(no);
}

No* rotacao_esquerda_direita(No *no)
{
    no->esquerdo = rotacao_esquerda(no->esquerdo);
    
    return rotacao_direita(no);
}

No* colorir_arvore(No * no, No* root)
{   

    if (no->cor == 1)
    {   
        if(no->pai != NULL)
        {   
            if (no->pai->cor == 1)
            {   
                no->cor=0;
                
                //se o pai e o tio forem vermelhos
                if((no->pai != no->pai->pai->esquerdo && no->pai->pai->esquerdo != NULL) && no->pai->pai->esquerdo->cor == 1)
                {
                    printf("tio esquerdo vermelho!\n");
                    no->pai->pai->esquerdo->cor=0;
                    printf("tio esquerdo vermelho!\n");
                }
                if((no->pai != no->pai->pai->direito && no->pai->pai->direito != NULL) && no->pai->pai->direito->cor == 1)
                {   
                    printf("tio direito vermelho!\n");
                    no->pai->pai->direito->cor=0;
                    printf("tio direito vermelho!\n");
                }
            } 
        }
    }

    return no;
}

No* balancear_arvore(No *no)
{   
    int altura_raiz = verifica_balancear(no);

    //se a arvore tender para a direita (altura raiz < -1) e um filho a direita
    if((altura_raiz < -1) && verifica_balancear(no->direito)<=0)
    {   
        printf("desbalanceada, tende para a direita (altura raiz > -1) e um filho a direita\n");
        no = rotacao_esquerda(no);
        no->pai=NULL;

    }
    else
    {   
        // se o no estiver tendendo para esquerda (altura_raiz > 1) e um filho a esquerda
        if((altura_raiz > 1) && verifica_balancear(no->esquerdo) >= 0)
        {
            printf("desbalanceada, tendendo para esquerda (altura_raiz > 1) e um filho a esquerda\n");            
            no = rotacao_direita(no);
            no->pai=NULL;

        }        
        else
        {   
            //se a arvore tender para a direita (altura raiz < -1) e um filho a esquerda
            if((altura_raiz < -1) && verifica_balancear(no->direito) > 0)
            {
                printf("desbalanceada, tende para a direita (altura raiz < -1) e um filho a esquerda\n");                
                no = rotacao_direita_esquerda(no);
                no->pai=NULL;

            }
            else
            {   
                // se o no estiver tendendo para esquerda (altura_raiz > 1) e um filho a direita
                if((altura_raiz > 1) && verifica_balancear(no->esquerdo) < 0)
                    {
                        printf("desbalanceada, tendendo para esquerda (altura_raiz > 1) e um filho a direita\n");            
                        no = rotacao_esquerda_direita(no);
                        no->pai=NULL;

                    }
            }
        }
    }
    
    printf("Foi balanceada\n");
    return no;
}

/*
No * inserir_no(No *no, int dado)
{
    No *temp = (No *)malloc(sizeof(No));
    temp=no;

    if(temp == NULL){
        temp = criar_raiz(dado);
        printf("No %d \n", temp->dado);
    }
    else
    {   
        printf("Agora no else\n");
        if(dado > no->dado){
            temp->direito = inserir_no(temp->direito, dado);
            temp->direito->pai = no;
            temp->direito->cor = 1;
            temp->direito = colorir_arvore(temp->direito, no);
        }

        else
        {   if(dado < no->dado){
            temp->esquerdo = inserir_no(temp->esquerdo, dado);
            temp->esquerdo->pai = no;
            temp->esquerdo->cor = 1;
            temp->esquerdo = colorir_arvore(temp->esquerdo, no);
            }
            else
                printf("Esse dado jah estah guardado!!!\n\n");
        }
    }
    
        printf("NO primmm!!!!!!!\n");

    temp->altura = maior(altura(temp->esquerdo), altura(temp->direito)) + 1;
        printf("NO segggg!!!!!!!\n");
    
    temp = balancear_arvore(temp);
    printf("NO inserido/criado!!!!!!!!!!\n");
    return temp;
}
*/


void inserir_no_2(No ** no, int dado)
{   No *temp = (No*)malloc(sizeof(No));
    temp = criar_raiz(dado);

    if (*no == NULL)
    {
        *no = temp;
    }
    else
    {   
        No *temp_2 = (No*)malloc(sizeof(No));
        No *temp_3 = (No*)malloc(sizeof(No));
        temp_2 = NULL;
        temp_3 = *no;

        while (temp_3 != NULL)
        {
            temp_2 = temp_3;
            if (temp->dado < temp_3->dado)
                temp_3 = temp_3->esquerdo;
            if (temp->dado > temp_3->dado)
                temp_3 = temp_3->direito;
        }
        temp->pai = temp_2;
        if (temp->dado > temp_2->dado){
            temp_2->direito = temp;            
        }
        if (temp->dado < temp_2->dado){
            temp_2->esquerdo = temp;
        }
        temp->cor = 1; 
        temp->altura = maior(altura(temp->esquerdo), altura(temp->direito)) + 1;
        temp = balancear_arvore(temp);
        temp = colorir_arvore(temp, *no);
        
    }
}

void inserir_no_3(No **no, int dado)
{
// Allocate memory for new node
    No *z = (No*)malloc(sizeof(No));
    z->dado = dado;
    z->esquerdo = z->direito = z->pai = NULL;

     //if root is null make z as root
    if (*no == NULL)
    {
        z->cor = 0;
        *no = z;
    }
    else
    {
        No *y = NULL;
        No *x = *no;

        // Follow standard BST insert steps to first insert the node
        while (x != NULL)
        {
            y = x;
            if (z->dado < x->dado)
                x = x->esquerdo;
            else
                x = x->direito;
        }
        z->pai = y;
        if (z->dado > y->dado)
            y->direito = z;
        else
            y->esquerdo = z;
        z->cor = 1;
        z->altura = maior(altura(z->esquerdo), altura(z->direito)) + 1;
        z = balancear_arvore(z);
        z = colorir_arvore(z, *no);
      
    }
}

void imprimir(No *no)
{
    if(no != NULL)
    {   
        imprimir(no->esquerdo);
        printf("%d ", no->dado);
        imprimir(no->direito);
    }
}

void imprimir_pais(No *no)
{
    if(no != NULL)
    {   
        
        imprimir_pais(no->esquerdo);
        
        if(no->pai != NULL)
            printf("No %d , no->pai %d\n", no->dado, no->pai->dado); 
        else
            printf("No %d , no->pai @\n", no->dado);

        imprimir_pais(no->direito);
        
    }
        
}

void imprimir_cores(No *no)
{
    if(no != NULL)
    {   
        imprimir_cores(no->esquerdo);
        printf("No %d cor %d\n", no->dado, no->cor);
        imprimir_cores(no->direito);
    }
}
