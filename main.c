#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirVetor(int vet[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void vetor_aleatorio(int vet[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vet[i] = rand() % tamanho;
    }
}

int main() {
    srand(time(NULL));

    int tamanho = 10;
    int vet[tamanho];

    vetor_aleatorio(vet, tamanho);

    printf("Vetor aleatorio de %d valores gerado:\n\n", tamanho);
    imprimirVetor(vet, tamanho);


    return 0;
}
