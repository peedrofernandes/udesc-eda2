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

  printf("Digite um numero inteiro: ");
  scanf("%d", &n);

  char *status = "false";

  do {
    printf("Digite o tamanho do vetor (max: 32): ");
    scanf("%d", &vetSize);

    if (vetSize > 32 || vetSize < 1)
      printf("Tamanho invalido!\n");

  } while (vetSize > 32 || vetSize < 1);

  int *vet = malloc(vetSize * sizeof(int));

  for (int i = 0; i < vetSize; i++) {
    vet[i] = rand() % 100;
    if (status == "false") {
      for (int j = 0; j < i; j++) {
        if (vet[i] + vet[j] == n) {
          status = "true";
          printf("vet[%d] = %d\n", i, vet[i]);
          printf("vet[%d] = %d\n", j, vet[j]);
        }
      } 
    }
  }

  printVet(vet, vetSize);

  printf("%s\n", status);

  free(vet);

  return 0;
}