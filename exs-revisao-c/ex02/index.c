#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printVet(int *vet, int tam) {
  printf("Vetor gerado: \n[");
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
    vet[i] = rand() % 5;

  printVet(vet, tam);

  int *newVet = malloc(tam * sizeof(int));

  for (int i = 0; i < tam; i++) {
    int acc = 1;

    for (int j = 0; j < tam; j++) {
      if (j != i)
        acc *= vet[j];
    }

    newVet[i] = acc;
  }

  printf("\nNovo vetor\n\n");

  printVet(newVet, tam);

  free(vet);
  free(newVet);
}