
#include <stdio.h>
#include "processamento.c"

int main( int argv, char** argc)
{
    int num, i, j;
    scanf("%d", &num);

    int  mat[num][num];


    for (i =0; i<num; i++){
        for (j=0; j<num; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    printf("\n\n");

     for (i =0; i<num; i++){
        for (j=0; j<num; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n\n");
    }

    checar_mat_quadrado_magico(num, mat);

    return 0;
}
