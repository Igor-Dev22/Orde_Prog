#include <stdio.h>   
#include <stdlib.h>  
#include <time.h> 

// Função de ordenação Insertion Sort em ordem crescente
void insertionSortCrescente(int vet[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int aux = vet[i];
        int j = i - 1;
        // Move os elementos maiores que 'aux' uma posição para frente
        while (j >= 0 && vet[j] > aux) {
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = aux; // Coloca o elemento na posição correta
    }
}

// Função de ordenação Insertion Sort em ordem decrescente
void insertionSortDecrescente(int vet[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int aux = vet[i];
        int j = i - 1;
        // Move os elementos menores que 'aux' uma posição para frente
        while (j >= 0 && vet[j] < aux) {
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = aux;
    }
}

// Função de ordenação Selection Sort em ordem crescente
void selectionSortCrescente(int vet[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int min_idx = i;
        // Encontra o menor valor do restante do vetor
        for (int j = i + 1; j < tamanho; j++) {
            if (vet[j] < vet[min_idx]) {
                min_idx = j;
            }
        }
        // Troca o menor valor com a posição atual
        int temp = vet[i];
        vet[i] = vet[min_idx];
        vet[min_idx] = temp;
    }
}

// Função de ordenação Selection Sort em ordem decrescente
void selectionSortDecrescente(int vet[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int max_idx = i;
        // Encontra o maior valor do restante do vetor
        for (int j = i + 1; j < tamanho; j++) {
            if (vet[j] > vet[max_idx]) {
                max_idx = j;
            }
        }
        // Troca o maior valor com a posição atual
        int temp = vet[i];
        vet[i] = vet[max_idx];
        vet[max_idx] = temp;
    }
}

// Função para imprimir os elementos do vetor
void imprimirVetor(int vet[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]); // Imprime cada número seguido de espaço
    }
    printf("\n"); // Pula linha após imprimir todos os elementos
}

// Função que gera um vetor de números aleatórios entre 0 e (tamanho - 1)
void gerarVetorAleatorio(int vet[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vet[i] = rand() % tamanho; // Gera número aleatório no intervalo [0, tamanho)
    }
}

// Função para copiar o conteúdo de um vetor para outro
void copiarVetor(int origem[], int destino[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i]; // Copia elemento a elemento
    }
}

int main() {
    int metodo, escolha, tam_vetor;

    printf("ORDENADOR DE NUMEROS\n");
    printf("Seja bem vindo ao ordenador de numeros!\nEsse programa gera um vetor de numeros aleatorios e voce escolhe como ele sera ordenado\n");

    // Solicita ao usuário o tamanho do vetor desejado
    printf("Insira o tamanho do vetor que deseja gerar (entre 2 e 9999):\n");
    scanf("%d", &tam_vetor);

    // Verifica se o tamanho informado é válido
    if (tam_vetor < 2 || tam_vetor > 9999) {
        printf("Valor invalido, encerrando o programa...\n");
        return 1;
    }

    srand(time(NULL)); 

    int vet_original[tam_vetor];
    int vet[tam_vetor];          

    gerarVetorAleatorio(vet_original, tam_vetor);

    // Loop para permitir que o usuário escolha diferentes métodos de ordenação
    do {
        copiarVetor(vet_original, vet, tam_vetor); // Copia o vetor original antes de ordenar

        // Menu de escolha do método de ordenação
        printf("\nEscolha seu metodo de ordenacao:\n");
        printf("1 - Insertion Sort (Crescente)\n");
        printf("2 - Insertion Sort (Decrescente)\n");
        printf("3 - Selection Sort (Crescente)\n");
        printf("4 - Selection Sort (Decrescente)\n");
        scanf("%d", &metodo);

        printf("Vetor original:\n");
        imprimirVetor(vet, tam_vetor);

        // Aplica o método escolhido
        switch (metodo) {
            case 1:
                insertionSortCrescente(vet, tam_vetor);
                printf("Vetor ordenado (Insertion Crescente):\n");
                break;
            case 2:
                insertionSortDecrescente(vet, tam_vetor);
                printf("Vetor ordenado (Insertion Decrescente):\n");
                break;
            case 3:
                selectionSortCrescente(vet, tam_vetor);
                printf("Vetor ordenado (Selection Crescente):\n");
                break;
            case 4:
                selectionSortDecrescente(vet, tam_vetor);
                printf("Vetor ordenado (Selection Decrescente):\n");
                break;
            default:
                printf("Metodo invalido.\n");
                continue; // Volta para o início do laço sem imprimir vetor ordenado
        }

        imprimirVetor(vet, tam_vetor); // Mostra o vetor após a ordenação

        // Pergunta ao usuário se deseja repetir com outro método
        printf("\nDeseja testar outro metodo?\n1 - Sim\n2 - Nao\n");
        scanf("%d", &escolha);

    } while (escolha == 1); // Repete enquanto o usuário quiser continuar

    printf("Encerrando o programa...\n");
    return 0;
}
