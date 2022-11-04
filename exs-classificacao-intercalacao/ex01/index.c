#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define t 100

void insertion_sort(int *list, int tam) {
  for (int i = 1; i < tam; i++) {
    int key = list[i];
    int j = i - 1;

    while (j >= 0 && list[j] > key) {
      list[j + 1] = list[j];
      j--;
    }

    list[j + 1] = key;
  }
}

void print_v(int *v, int tam) {
  printf("[");
  for (int i = 0; i < tam; i++) {
    printf("%d", v[i]);
    if (i < tam - 1)
      printf(",");
  }
  printf("]\n");
}

int main() {
  srand(time(NULL));

  int v[t];

  for (int i = 0; i < t; i++)
    v[i] = rand() % 100;

  printf("Unsorted array: \n");
  print_v(v, t);

  insertion_sort(v, t);

  printf("Sorted array: \n");
  print_v(v, t);
}