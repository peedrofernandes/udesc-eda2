#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sortVet(int *vet, int tam) {
  for (int i = 0; i < tam; i++) {
    for (int j = i + 1; j < tam; j++) {
      if (vet[j] < vet[i]) {
        int aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
      }
    }
  }
}

void printVet(int *vet, int tam) {
  printf("[");
  for (int i = 0; i < tam; i++) {
    printf("%d", vet[i]);
    if (i != tam - 1)
      printf(",");
  }
  printf("]\n");
}

int main() {
  srand(time(NULL));
  int tam;

  do {
    printf("Digite o tamanho do vetor (max: 16): ");
    scanf("%d", &tam);

    if (tam < 0 || tam > 16)
      printf("Tamanho invalido!\n");
  } while (tam < 0 || tam > 16);

  int *vet = malloc(tam * sizeof(int));

  for (int i = 0; i < tam; i++)
    vet[i] = rand() % 10;

  printf("Vetor gerado: \n");
  printVet(vet, tam);

  sortVet(vet, tam);

  int min = 1;

  for (int i = 0; i < tam; i++) {
    if (vet[i] == min)
      min++;
  }

  printf("Menor inteiro que nao esta no vetor: %d\n", min);

  free(vet);
}