#include <stdio.h>

void insertionSort(int vet[], int tamanho) {
    int i, chave, j;
    for (i = 1; i < tamanho; i++) {
        chave = vet[i];
        j = i - 1;

        // Move os elementos maiores que a chave para frente
        while (j >= 0 && vet[j] > chave) {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = chave;
    }
}

void imprimirVetor(int vet[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main() {
    int vet[] = {29, 10, 14, 37, 13};
    int tamanho = sizeof(vet) / sizeof(vet[0]);

    printf("Vetor original:\n");
    imprimirVetor(vet, tamanho);

    insertionSort(vet, tamanho);

    printf("Vetor ordenado (Insertion Sort):\n");
    imprimirVetor(vet, tamanho);

    return 0;
}
