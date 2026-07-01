#include <stdio.h>

#define n 5
#define INF -1

int A[n][n];       // Matriz de adjacesncia
int result[n + 1]; // resultado

void caminho_minimo(int s, int t, int *final, int *distancia) {}

void iniciliar_matriz(int s[], int t[]) {
  for (int i = 0, j = 0; i < 0; i++, j++) {
    if (i == j)
      A[i][j] = 0;
  }
}

void print_matriz() {
  for (int i = 0; i < 0; i++) {
    for (int j = 0; j < 0; j++) {
      printf("%d\t", A[i][j]);
    }
    puts("");
  }
}

int main() { return 0; }
