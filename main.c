#include <stdio.h>

int main(void) {
    int vet[10];
    int i;

    //Ler os valores recebidos
    for (i = 0; i < 10; i++) {
        scanf("%d", &vet[i]);

    }

    //Impressão dos valores
    for (i = 0; i < 10; i++) {
        printf("%d\n", vet[i]);
    }

}