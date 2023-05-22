#include <stdio.h>

int main(int agcv, char** argv)
{
    int cont=5, num[5], i;


    for (i=0;i<cont; i++){
        scanf("%i", &num[i]);
    }

    for (i=0;i<cont; i++){
        printf(" %i\n", num[i]);
    }
}
