#include <stdio.h>

int main()
{
    int cont=10, num[cont], i;


    for (i=0;i<cont; i++){
        scanf("%i", &num[i]);
    }

    for (i=0;i<cont; i++){
        printf(" %i\n", num[cont-i-1]);
    }
}
