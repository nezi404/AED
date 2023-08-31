#include <stdio.h>
#include <stdlib.h>
#include "arn.c"

int main (){
    No *raiz = cria_ArvLLRB();
    int esc=10, alt=0,num,qnt;


    while(esc!=0)
    {   
        printf("1-inserir\n2-imprimir\n3-Remover no\n4-ver altura\n5-ver quantidade de no\n0-sair\n");
        scanf("%d", &esc);

        switch (esc)
        {
        case 1:
            scanf("%d", &num);
            insere_ArvLLRB(&raiz, num);
            break;
        case 2:
            imprimir(raiz,0);
            printf("\n");
            break;
        case 3:
            printf("Insira o numero pra ser removido: ");
            scanf("%d", &num);
            remove_no(&raiz, num);
            break;
        case 4:
            alt = altura_arvore(&raiz);
            printf("A altura da arvore eh %d\n", alt);
            break;
        case 5:
            qnt = quantidade_de_no(&raiz);
            printf("A quantidade de nos na arvore eh %d\n", qnt);
            break;
        case 0:
            printf("\n\n\n\ntchauuu 0/\n\n\n\n"); 
            break; 
        default:
            printf("Entrada invalida\n");
            break;
        }
    }
}