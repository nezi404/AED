#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pilha2.h"

int main(int argc, char *argv[]){
    int n=10;
    int mat[n][n], mat_copia[n][n];
    int i, j;
    Pilha* pilha;

    pilha = criar_pilha();


    ler_arquivo(mat, n);
    print_array(mat, n);
    copiar_matriz(mat, mat_copia, n);
    /*
    pilha=adicionar_pilha(1,2,pilha);
    printf("pilha : %d ", pilha->i);
    pilha=adicionar_pilha(3,4,pilha);
    //pilha=remover_pilha(pilha);
    printf("pilha : %d ", pilha->prox->i);
    
    pilha=adicionar_pilha(1, 2, pilha);
    printf("O primeiro dado da pilha eh %d e %d\n", pilha->i, pilha->j);

    pilha=adicionar_pilha(3, 4, pilha);
    printf("O primeiro dado da pilha eh %d e %d\n", pilha->i, pilha->j);

    pilha=remover_pilha(pilha);
    printf("O primeiro dado da pilha eh %d e %d\n", pilha->i, pilha->j);
    printf("O proximo dado da pilha eh %d e %d\n", pilha->prox->i, pilha->prox->j);
    printf("O proximo dado da pilha eh %d e %d\n", pilha->prox->i, pilha->prox->j);
    printf("O proximo dado da pilha eh %d e %d\n", pilha->prox->i, pilha->prox->j);
    */
    
    pilha = achar_caminho(mat, n, pilha);
    
    printf("Caminho achado!\n");
    print_array(mat_copia, n);
    print_array(mat, n);
    printf("Esta funcionando 1111");
    printf(" %d %d" , pilha->i, pilha->j);
    mostrar_caminho_final(pilha, mat);
    printf("Esta funcionando 12222");
    print_array(mat, n);
    

}

