#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10  // Tamanho do vetor

// ---------- Função para imprimir o vetor ----------
void imprimirVetor(int vet[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

// ---------- Função para copiar vetores ----------
void copiarVetor(int origem[], int destino[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

// ---------- Bubble Sort ----------
void bubbleSort(int vet[], int tamanho, int crescente) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if ((crescente && vet[j] > vet[j + 1]) || (!crescente && vet[j] < vet[j + 1])) {
                int temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
    }
}

// ---------- Quick Sort ----------
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int vet[], int baixo, int alto, int crescente) {
    int pivo = vet[alto];
    int i = baixo - 1;

    for (int j = baixo; j < alto; j++) {
        if ((crescente && vet[j] < pivo) || (!crescente && vet[j] > pivo)) {
            i++;
            trocar(&vet[i], &vet[j]);
        }
    }
    trocar(&vet[i + 1], &vet[alto]);
    return i + 1;
}

void quickSort(int vet[], int baixo, int alto, int crescente) {
    if (baixo < alto) {
        int pi = particionar(vet, baixo, alto, crescente);
        quickSort(vet, baixo, pi - 1, crescente);
        quickSort(vet, pi + 1, alto, crescente);
    }
}

// ---------- Função Principal ----------
int main() {
    int vetorOriginal[TAM], bubble[TAM], quick[TAM];

    // Geração de números aleatórios
    srand(time(NULL));
    printf("Vetor gerado aleatoriamente:\n");
    for (int i = 0; i < TAM; i++) {
        vetorOriginal[i] = rand() % 100;  // Números de 0 a 99
        printf("%d ", vetorOriginal[i]);
    }
    printf("\n\n");

    // Bubble Sort crescente
    copiarVetor(vetorOriginal, bubble, TAM);
    bubbleSort(bubble, TAM, 1);
    printf("Bubble Sort - Ordem Crescente:\n");
    imprimirVetor(bubble, TAM);

    // Bubble Sort decrescente
    copiarVetor(vetorOriginal, bubble, TAM);
    bubbleSort(bubble, TAM, 0);
    printf("Bubble Sort - Ordem Decrescente:\n");
    imprimirVetor(bubble, TAM);

    // Quick Sort crescente
    copiarVetor(vetorOriginal, quick, TAM);
    quickSort(quick, 0, TAM - 1, 1);
    printf("Quick Sort - Ordem Crescente:\n");
    imprimirVetor(quick, TAM);

    // Quick Sort decrescente
    copiarVetor(vetorOriginal, quick, TAM);
    quickSort(quick, 0, TAM - 1, 0);
    printf("Quick Sort - Ordem Decrescente:\n");
    imprimirVetor(quick, TAM);

    return 0;
}
