#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSortCrescente(int vet[], int tamanho) {
    int i, aux, j;
    for (i = 1; i < tamanho; i++) {
        aux = vet[i];
        j = i - 1;

        while (j >= 0 && vet[j] > aux) {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = aux;
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

    insertionSortCrescente(vet, tamanho);

    printf("Vetor ordenado (Insertion Sort - Crescente):\n");
    imprimirVetor(vet, tamanho);

    return 0;
}
