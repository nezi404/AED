int checar_mat_quadrado_magico(int numero_colunas_linhas, int mat[][numero_colunas_linhas])
{
    int i, j;
    int linha[numero_colunas_linhas], coluna[numero_colunas_linhas], diagonal_principal=0, diagonal_secundaria=0, ver_matriz_magica=1;

    for (i =0; i<numero_colunas_linhas; i++){
        for (j=0; j<numero_colunas_linhas; j++){

            if ( i ==j)
                diagonal_principal+= mat[i][i];

            if (j+ 1 + i + 1 == numero_colunas_linhas + 1)
                diagonal_secundaria+= mat[i][j];

        }
    }

    for (j=0; j<numero_colunas_linhas; j++){

            linha[j] = 0;

            coluna[j] = 0;

    }

    for (i=0; i<numero_colunas_linhas; i++){
        for (j=0; j<numero_colunas_linhas; j++){

            linha[i] += mat[i][j];

            coluna[i] += mat[j][i];

        }
    }

    if (diagonal_secundaria==diagonal_principal){

        for(i=0; i<numero_colunas_linhas; i++){
            if (coluna[i]!= linha[i])
                ver_matriz_magica =0;

        }

        if (ver_matriz_magica != 0)
            printf("Eh quadrado magico\n");

        if (ver_matriz_magica == 0)
            printf("Nao eh quadrado magico\n");

    }

    if (diagonal_principal != diagonal_secundaria)
        printf("Nao eh quadrado magico\n");

    return 0;

}
