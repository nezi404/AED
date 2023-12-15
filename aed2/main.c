// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int tam, tipo, algo=0, esc=0;
    int vet_ord100[100], vet_ord1000[1000], vet_ord10000[10000], vet_ord100000[100000], vet_ale100[100], vet_ale1000[1000], vet_ale10000[10000], vet_ale100000[100000], aux = 0, i, j;
    clock_t start_ord100, start_ord1000, start_ord10000, start_ord100000, end_ord100, end_ord1000, end_ord10000, end_ord100000;
    clock_t start_ale100, start_ale1000, start_ale10000, start_ale100000, end_ale100, end_ale1000, end_ale10000, end_ale100000;
    double  time_ord100, time_ord1000, time_ord10000, time_ord100000, time_ale100, time_ale1000, time_ale10000, time_ale100000;
    srand( (unsigned)time(NULL) );
    char ale_100[] = "alatorio100.txt", ale_1000[] = "alatorio1000.txt", ale_1000[] = "alatorio100.txt", ale_10000[] = "alatorio100.txt";
    FILE *fp = fopen(filename, "r");
    while(esc == 0){
        printf("Escolha o tamanho do vetor: 1- 100 2- 1000 3- 10000 4-100000\n");
        switch (tam){
            case 1:
                for(j=0; j<100; j++){
                    vet_ord100[j] = j;
                }
                for(j=0; j<100; j++){
                    vet_ale100[j] = rand()%1000;
                }
                esc=100
            case 2:
                for(j=0; j<1000; j++){
                    vet_ord1000[j] = j;
                }
                for(j=0; j<1000; j++){
                    vet_ale1000[j] = rand()%1000;
                }
                esc=1000;
            case 3:
                for(j=0; j<10000; j++){
                    vet_ord10000[j] = j;
                }
                for(j=0; j<10000; j++){
                    vet_ale10000[j] = rand()%1000;
                }
                esc=10000;
            case 4:
                for(j=0; j<100000; j++){
                    vet_ord10000[j] = j;
                }
                for(j=0; j<100000; j++){
                    vet_ale10000[j] = rand()%1000;
                }
                esc=100000;
            default:
                printf("Valor inserido invalido\n");
        }
        
        while(algo == 0){
            printf("Escolha o ")
            
        }
        
    }
    return 0;
}