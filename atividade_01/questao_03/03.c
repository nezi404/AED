/*
    Nome: Nezi Pimentel Ribeiro Neta
    Mat: 2215310058

*/

#include <stdio.h>
#include "processamento.c"

int main (int argc, char** argv)
{
    int i;
    int notas[4];
    float media;


    //entrada de dados
    for (i=0; i < 4; i++)
        scanf("%d", &notas[i]);

    //processamento dos dados
    media = calcular_media(4, notas);

    //saida
    printf("%f\n", media);

    return 0;
}
