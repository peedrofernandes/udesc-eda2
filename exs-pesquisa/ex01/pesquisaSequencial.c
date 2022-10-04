#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define t 100

void imprimirVetor(int v[], int tam) {
    printf("[");
    for (int i = 0; i < tam; i++) {
        printf("%d", v[i]);
        if (i != tam - 1)
            printf(",");
    }
    printf("]\n");
}

int pesquisaSequencial(int chave, int v[], int tam) {
    int i;
    int op = 0;

    for (int c = 0; c < tam; c++) {
        if(v[c] == chave) {
            i = c;
            printf("Pesquisa sequencial finalizada.\n");
            printf("Numero de operacoes computacionais: %d\n", op);
            printf("Indice do elemento procurado: %d\n", i);
            return i;
        }
        op += 2;
    }
    op ++;

    printf("Pesquisa sequencial finalizada.\n");
    printf("Numero de operacoes computacionais: %d\n", op);
    printf("O elemento buscado não foi encontrado!\n");
    return -1;
}

int main() {
    double elapsed = clock();
    srand(time(NULL));
    int v[t];

    for (int i = 0; i < t; i++)
        v[i] = rand() % 100;

    printf("Vetor gerado:\n");
    imprimirVetor(v, t);
    printf("\n");

    pesquisaSequencial(50, v, t);
    printf("\n");

    printf("Tempo de execucao: %.2lfs\n\n", elapsed);
}