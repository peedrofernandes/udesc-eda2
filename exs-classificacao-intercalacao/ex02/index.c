#include <stdio.h>
#include <stdlib.h>

#define M 7

typedef struct elem {
  struct elem *prev;
  int value;
  struct elem *next;
} Elem;

typedef struct part {
  struct part *prev;
  Elem *first;
  int size;
  struct part *next;
} Part;

typedef struct partList {
  Part *first;
  int size;
} PartList;

typedef struct memoryItem {
  int value;
  int frozen;
} MemoryItem;

PartList *selection_substitution(FILE *file) {
  MemoryItem memory[M];

  PartList *list = malloc(sizeof(PartList));

  list->first = malloc(sizeof(Part));
  list->first->first = malloc(sizeof(Elem));

  Part *currentPart = list->first;
  Elem *currentElem = currentPart->first;
  int firstIteration = 1;

  list->size = 0;
  currentPart->size = 0;

  int result = 1;

  // 1 - Ler M registros do arquivo original para a memória;
  for (int i = 0; i < M; i++) {
    int elem;
    result = fscanf(file, "%d", &elem);
    memory[i].frozen = 0;
    if (result == -1)
      break;
    memory[i].value = elem;
  }

  while (result != -1) {
  // 2 - Selecionar, no vetor em memória, o registro com a menor chave;
    int iMin = -1;
    for (int i = 0; i < M; i++) {
      if (memory[i].frozen != 0)
        continue;
      if (iMin == -1 || memory[i].value < memory[iMin].value) {
        iMin = i;
      }
    }

    // 3 - Gravar esse registro na partição de saída;
    if (!firstIteration) {
      currentElem->next = malloc(sizeof(Elem));
      currentElem->next->prev = currentElem;
      currentElem = currentElem->next;
    } else {
      firstIteration = 0;
    }
    currentElem->value = memory[iMin].value;
    currentPart->size++;

    // 4 - Substituir, no vetor em memória, o registro que acabou de ser gravado pelo próximo registro no arquivo;
    int next;
    result = fscanf(file, "%d", &next);
    memory[iMin].value = next;

    // 5 - Se o registro do arquivo for menor do que o registro que foi substituído, o que substituiu será congelado e não fará parte do processamento;
    if (next < currentElem->value)
      memory[iMin].frozen = 1;

    // 6 - Se existir, no vetor em memória, registros não congelados, retornar ao passo 2;
    int all_frozen = 1;
    for (int i = 0; i < M; i++) {
      if (memory[i].frozen == 0) {
        all_frozen = 0;
        break;
      }
    }

    // 7 - Caso contrário:
    if (all_frozen) {
      // 1. Fechar a partição de saída;
      list->size++;
      currentPart->next = malloc(sizeof(Part));
      currentPart->next->prev = currentPart;
      currentPart = currentPart->next;
      currentPart->first = malloc(sizeof(Part));
      currentElem = currentPart->first;
      firstIteration = 1;

      // 2. Descongelar os registros congelados;
      for (int i = 0; i < M; i++)
        memory[i].frozen = 0;

      // 3. Abrir uma nova partição de saída;
      // Já feito

      // 4. Voltar ao passo 2;
    }
  }
  return list;
}

void print_parts(PartList *list) {
  Part *currentPart = list->first;

  int qtdParts = 0;

  while (currentPart != NULL) {
    Elem *currentElem = currentPart->first;
    qtdParts++;
    printf("Particao %d: \n[", qtdParts);

    while (1) {
      printf("%d", currentElem->value);
      if (currentElem->next == NULL)
        break;
      printf(",");
      currentElem = currentElem->next;
    }
    printf("]\n");

    currentPart = currentPart->next;
  }
}

int main() {
  FILE *file = fopen("file.csv", "r");

  PartList *list = selection_substitution(file);

  print_parts(list);
}