#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para ordenar vetor com Insertion Sort em ordem crescente 
void insertionSortCrescente(int vet[], int tamanho) {
    int i, aux, j;
    for (i = 1; i < tamanho; i++) {
        aux = vet[i];
        j = i - 1;

        // Loop para mover os elementos maiores que aux para frente
        while (j >= 0 && vet[j] > aux) {
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = aux;
    }
}

// Essa Função vai ordenar vetor com Insertion Sort em ordem decrescente
void insertionSortDecrescente(int vet[], int tamanho) {
    int i, aux, j;
    for (i = 1; i < tamanho; i++) {
        aux = vet[i];
        j = i - 1;

        // Move os elementos menores que aux para frente
        while (j >= 0 && vet[j] < aux) {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = aux;
    }
}

//Essa Função vai ordenar vetor com Selection Sort em ordem crescente
void selectionSortCrescente(int vet[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int min_idx = i;

        // loop para Encontrar o menor valor no restante do vetor
        for (int j = i + 1; j < tamanho; j++) {
            if (vet[j] < vet[min_idx]) {
                min_idx = j;
            }
        }

        // Troca os valores
        int temp = vet[i];
        vet[i] = vet[min_idx];
        vet[min_idx] = temp;
    }
}

// Função para ordenar vetor com Selection Sort em ordem decrescente
void selectionSortDecrescente(int vet[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int max_idx = i;

        // loop para Encontrar o maior valor no restante do vetor
        for (int j = i + 1; j < tamanho; j++) {
            if (vet[j] > vet[max_idx]) {
                max_idx = j;
            }
        }

        // Troca os valores
        int temp = vet[i];
        vet[i] = vet[max_idx];
        vet[max_idx] = temp;
    }
}

// Função para imprimir o vetor na tela
void imprimirVetor(int vet[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

// Gera valores aleatórios no vetor
void vetor_aleatorio(int vet[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vet[i] = rand() % tamanho;
    }
}

int main() {
    int escolha;
    //  menu de opções
    printf("Bem vindo ao ordenador de numeros, qual metodo gostaria de utilizar?\n");
    printf("1 - Metodo Insertion (crescente)\n");
    printf("2 - Metodo Insertion (decrescente)\n");
    printf("3 - Metodo Selection (crescente)\n");
    printf("4 - Metodo Selection (decrescente)\n");
    scanf("%d", &escolha);

    // Inicializa semente da aleatoriedade
    srand(20);

    int tamanho = 50;
    int vet[tamanho];

    // Preenche o vetor com valores aleatórios
    vetor_aleatorio(vet, tamanho);

    // Executa o algoritmo escolhido e mostra o vetor antes/depois
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
