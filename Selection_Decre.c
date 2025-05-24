#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSortDecrescente(int vet[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int max_idx = i;

        for (int j = i + 1; j < tamanho; j++) {
            if (vet[j] > vet[max_idx]) {
                max_idx = j;
            }
        }

        int temp = vet[i];
        vet[i] = vet[max_idx];
        vet[max_idx] = temp;
    }
}

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

    int tamanho = 1000;
    int vet[tamanho];

    vetor_aleatorio(vet, tamanho);

    printf("Vetor original:\n");
    imprimirVetor(vet, tamanho);

    selectionSortDecrescente(vet, tamanho);

    printf("Vetor ordenado (Selection Sort - Decrescente):\n");
    imprimirVetor(vet, tamanho);

    return 0;
}