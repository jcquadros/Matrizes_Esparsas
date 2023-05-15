#include <stdio.h>
#include "sparse_matrix.h"

int main() {
  // Criando uma matriz 2x3
  SparseMatrix *m = sparse_matrix_construct(2, 3);

  // Adicionando alguns valores
  sparse_matrix_set(m, 0, 0, 1.0);
  sparse_matrix_set(m, 0, 2, 2.0);
  sparse_matrix_set(m, 1, 1, 3.0);
  sparse_matrix_set(m, 1, 2, 4.0);

  // Testando alguns valores válidos
  printf("Valor em (0,0): %f (esperado: 1.0)\n", sparse_matrix_get(m, 0, 0));
  printf("Valor em (0,2): %f (esperado: 2.0)\n", sparse_matrix_get(m, 0, 2));
  printf("Valor em (1,1): %f (esperado: 3.0)\n", sparse_matrix_get(m, 1, 1));
  printf("Valor em (1,2): %f (esperado: 4.0)\n", sparse_matrix_get(m, 1, 2));

  // Testando alguns valores inválidos
  printf("Valor em (-1,0): %f (esperado: 0.0)\n", sparse_matrix_get(m, -1, 0));
  printf("Valor em (0,-1): %f (esperado: 0.0)\n", sparse_matrix_get(m, 0, -1));
  printf("Valor em (2,0): %f (esperado: 0.0)\n", sparse_matrix_get(m, 2, 0));
  printf("Valor em (0,3): %f (esperado: 0.0)\n", sparse_matrix_get(m, 0, 3));

  // Liberando a memória alocada pela matriz
  sparse_matrix_destruct(m);

  return 0;
}
