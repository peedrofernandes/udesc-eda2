#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printVet(int *vet, int vetSize) {
  printf("Vetor gerado: \n[");
  for (int i = 0; i < vetSize; i++) {
    printf("%d", vet[i]);
    if (i != vetSize - 1)
      printf(",");
  }
  printf("]\n");
}

int main() {
  srand(time(NULL));
  int vetSize, n;

  do {
    printf("Digite o tamanho do vetor (max: 32): ");
    scanf("%d", &vetSize);

    if (vetSize > 32 || vetSize < 1)
      printf("Tamanho invalido!\n");

  } while (vetSize > 32 || vetSize < 1);

  int *vet = malloc(vetSize * sizeof(int));

  for (int i = 0; i < vetSize; i++)
    vet[i] = rand() % 10;

  printVet(vet, vetSize);

  int maxValue = 0;

  for (int i = 0; i < vetSize; i++) {
    int init = i % 2 == 0 ? 0 : 1;
    int sum = 0;
    for (int j = init; j < vetSize; j += 2)
      sum += vet[j];
    if (sum > maxValue)
      maxValue = sum;
  }

  printf("Maior soma de elementos nao-adjacentes: %d\n", maxValue);
}