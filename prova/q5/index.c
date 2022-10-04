#include <stdio.h>
#include <stdlib.h>

int main() {
  int input[] = {6, 5, 2, 3, 5, 2, 2, 1};
  size_t sizeInput = sizeof(input) / sizeof(int);
  int totalPares = 0;

  for (int i = 0; i < sizeInput; i++) {
    if (input[i] == 0)
      continue;

    int n = input[i];
    int qtd = 0;

    for (int j = i; j < sizeInput; j++) {
      if (input[j] == n) {
        qtd++;
        input[j] = 0;
      }
    }

    totalPares += qtd / 2;
  }

  printf("Total de pares: %d\n", totalPares);
}

// kitten
// sitting