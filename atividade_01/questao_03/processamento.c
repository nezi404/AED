/*
    Nome: Nezi Pimentel Ribeiro Neta
    Mat: 2215310058

*/

float calcular_media(int numero, int *notas)
{
    float total = 0;
    float media;
    int i;

    for(i=0; i<numero; i++)
        total += notas[i];

    media = total/numero;

    return media;
}
