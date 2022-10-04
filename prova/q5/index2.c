#include <stdio.h>
#include <math.h>


int minimo(int a, int b, int c);
int tamanhosString(char *s);


int main() {
  char strA[] = "pedro";
  char strB[] = "passo";
  int m = strlen(strA);
  int n = strlen(strB);
  int mat[m][n];
  int custo = 0;
 
    for (i = 0; i <= m; i++)
        d[0][i] = i;
    for (j = 0; j <= n; j++)
        d[j][0] = j;
 
    for (j = 1; j <= m; j++) {
        for (i = 1; i <= n; i++) {
            if (str[i - 1] == str2[j - 1]) {
                custo = 0;
            } else {
                custo = 1;
            }
            d[i][j] = minimo((d[i-1][j]+1), (d[i][j-1]+1), (d[i-1][j-1]+custo));
        }
    }
    printf("A distância de Levinstein é %d\n", d[n][m]);
    return 0;
}

int tamanhosString(char *s){
    int count = 0;
    for(int i = 0; s[i] != '\0'; i++)
        count++;
    return count;
}

int minimo(int a, int b, int c){
    int menor = a;
    if(b < a)
        menor = b;
    if(c < menor)
        menor = c;
        
    return menor;
}