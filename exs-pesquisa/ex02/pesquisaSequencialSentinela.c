#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define t 100

void imprimirVetor(int v[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("v[%d]: %d\n", i, v[i]);
    }
}

void pesquisaSequencialSentinela(int chave, int v[], int tam) {
    v[tam] = chave;
    int op = 0;
    int i = 0;

    while (v[i] != chave) {
        i++;
        op++;
    }

    op++;
    printf("Pesquisa sequencial com sentinela finalizada.\n");
    printf("Numero de operacoes computacionais: %d\n", op);

    if (i < tam)
        printf("Índice do elemento encontrado: %d\n", i);
    else
        printf("O elemento não foi encontrado!\n");
}

int main() {
    srand(time(NULL));
    int v[t];

    for (int i = 0; i < t; i++)
        v[i] = rand() % 100;
    imprimirVetor(v, t);

    pesquisaSequencialSentinela(50, v, t);
}