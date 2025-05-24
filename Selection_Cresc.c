#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de ordenação Selection Sort em ordem crescente
void selectionSortCrescente(int vet[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int min_idx = i;

        // Encontra o índice do menor valor na parte não ordenada
        for (int j = i + 1; j < tamanho; j++) {
            if (vet[j] < vet[min_idx]) {
                min_idx = j;
            }
        }

        // Troca o menor valor encontrado com o da posição atual
        int temp = vet[i];
        vet[i] = vet[min_idx];
        vet[min_idx] = temp;
    }
}

// Função para imprimir os elementos do vetor
void imprimirVetor(int vet[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

// Função para preencher o vetor com valores aleatórios
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
