#include <stdio.h>
#include <stdlib.h>
#include "arvore_rubro_negra.h"

int main(int arc[], int *agv[])
{
    Raiz *raiz;
    int esc=10, alt=0,num;
    raiz = criar_raiz();


    while(esc!=0)
    {   
        printf("1-inserir\n2-imprimir\n3-verificar altura\n");
        scanf("%d", &esc);

        switch (esc)
        {
        case 1:
            scanf("%d", &num);
            raiz->conteudo = inserir_no(raiz->conteudo, num);
            break;
        case 2:
            imprimir(raiz->conteudo);
            printf("\n");
            break;
        case 3:
            alt=altura(raiz->conteudo);  
            printf("A altura eh %d\n", alt); 
            break;
        case 0:
            printf("\n\n\n\n\n\ntchauuu 0/"); 
            break;  
        default:
            printf("Entrada invalida");
            break;
        }
    }
}