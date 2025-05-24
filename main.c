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
            j--;
        }
        vet[j + 1] = aux;
    }
}

void insertionSortDecrescente(int vet[], int tamanho) {
    int i, aux, j;
    for (i = 1; i < tamanho; i++) {
        aux = vet[i];
        j = i - 1;

        while (j >= 0 && vet[j] < aux) {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = aux;
    }
}

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
    int escolha;
    printf("Bem vindo ao ordenador de numeros, qual metodo gostaria de utilizar?\n1-Metodo Insertion(crescente)\n2-Metodo Insertion(decrescente)\n3-Metodo Selection(crescente)\n4-Metodo Selection(decrescente)\n");
    scanf("%d", &escolha);
    srand(20);

    int tamanho = 50;
    int vet[tamanho];

    vetor_aleatorio(vet, tamanho);

    switch(escolha) {
        case 1:
        printf("Vetor original:\n");
        imprimirVetor(vet, tamanho);

        insertionSortCrescente(vet, tamanho);

        printf("Vetor ordenado (Insertion Sort - Crescente):\n");
        imprimirVetor(vet, tamanho);
        break;

         case 2:
        printf("Vetor original:\n");
        imprimirVetor(vet, tamanho);

        insertionSortDecrescente(vet, tamanho);

        printf("Vetor ordenado (Insertion Sort - Decrescente):\n");
        imprimirVetor(vet, tamanho);
        break;

         case 3:
        printf("Vetor original:\n");
        imprimirVetor(vet, tamanho);

        selectionSortCrescente(vet, tamanho);

        printf("Vetor ordenado (Selection Sort - Crescente):\n");
        imprimirVetor(vet, tamanho);
        break;

         case 4:
        printf("Vetor original:\n");
        imprimirVetor(vet, tamanho);

        selectionSortDecrescente(vet, tamanho);

        printf("Vetor ordenado (Selection Sort - Decrescente):\n");
        imprimirVetor(vet, tamanho);
        break;
    }

    return 0;
}