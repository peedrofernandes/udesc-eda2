#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define qtdRegistros 1000
#define maxRegistros 10

int main() {
    srand(time(NULL));

    int arq[qtdRegistros];

    for (int i = 0; i < qtdRegistros; i++)
        arq[i] = rand() % 1000;
    
    
}
