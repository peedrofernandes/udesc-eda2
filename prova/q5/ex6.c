#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char strA[] = "cama";
  char strB[] = "caixa";
  int m = strlen(strA);
  int n = strlen(strB);
  int mat[m][n];
  int custo = 0;

  for (int i = 0; i < m; i++)
    mat[i][0] = i;
  for (int i = 0; i < n; i++)
    mat[0][i] = i;

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (strA[i] == strB[j])
          custo = 0;
        else
          custo = 1;
        mat[i][j] = min(
          mat[i-1][j] + 1,
          mat[i][j-1] + 1,
          mat[i-1][j-1] + custo
        );
      }
    }
    printf("%d\n", mat[n][m]);
}