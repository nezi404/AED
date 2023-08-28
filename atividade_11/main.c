#include <stdio.h>
#include <stdlib.h>
#include "arvore_rubro_negra.h"

int main(int arc[], int *agv[])
{
    No *raiz = NULL;
    int esc=10, alt=0,num;


    while(esc!=0)
    {   
        printf("1-inserir\n2-imprimir\n3-verificar altura\n4-imprimir nos e seus pais\n5-imprimir cores\n0-sair\n");
        scanf("%d", &esc);

        switch (esc)
        {
        case 1:
            scanf("%d", &num);
            
            //raiz = inserir_no(raiz, num);
            inserir_no_3(&raiz, num);
            printf("%d dadosssss\n", raiz->dado);
            break;
        case 2:
            imprimir(raiz);
            printf("\n");
            break;
        case 3:
            alt=altura(raiz);  
            printf("A altura eh %d\n", alt); 
            break;
        case 5:
            imprimir_cores(raiz);
            printf("\n");
            break;
        case 0:
            printf("\n\n\n\ntchauuu 0/\n\n\n\n"); 
            break; 
        case 4:
            if (raiz!=NULL)
                imprimir_pais(raiz);
            else
                printf("Nao ha nos para imprimir\n");
            break; 
        default:
            printf("Entrada invalida\n");
            break;
        }
    }
}