#include <stdio.h>
#include <stdlib.h>
#include "funcao.h"


int main(){
    int negosio, n, i;

    printf("tamanho do vetor: ");
    scanf("%d", &n);

    int* vetor = (int*)malloc(n * sizeof(int));

    printf("insira numero: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("\nqual metodo ?\n");
    printf("1 bubble Sort\n");
    printf("2 insertion Sort\n");
    scanf("%d", &negosio);

    switch (negosio) {
        case 1:
            bubble(vetor, n);
            printf("\nordem por bubble sort: ");
            printVetor(vetor, n);
            break;
        case 2:
            insert(vetor, n);
            printf("\nordem por insertion sort: ");
            printVetor(vetor, n);
            break;
    }

    return 0;
}
