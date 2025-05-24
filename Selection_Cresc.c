#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSortCrescente(int vet[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < tamanho; j++) {
            if (vet[j] < vet[min_idx]) {
                min_idx = j;
            }
        }

        int temp = vet[i];
        vet[i] = vet[min_idx];
        vet[min_idx] = temp;
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

    selectionSortCrescente(vet, tamanho);

    printf("Vetor ordenado (Selection Sort - Crescente):\n");
    imprimirVetor(vet, tamanho);

    return 0;
}
