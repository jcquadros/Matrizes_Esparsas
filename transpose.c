#include "sparse_matrix.h"
#include <stdio.h>

int main() {
  SparseMatrix *m = sparse_matrix_construct(3, 3);
  sparse_matrix_set(m, 0, 0, 1);
  sparse_matrix_set(m, 0, 2, 2);
  sparse_matrix_set(m, 1, 1, 3);
  sparse_matrix_set(m, 2, 0, 4);
  sparse_matrix_set(m, 2, 2, 5);

  printf("Matriz original:\n");
  sparse_matrix_print(m);

  SparseMatrix *m_t = sparse_matrix_transpose(m);

  printf("\nMatriz transposta:\n");
  sparse_matrix_print(m_t);

  sparse_matrix_destruct(m);
  sparse_matrix_destruct(m_t);

  return 0;
}
/*
Saida esperada:

  Matriz original:
  1 0 2
  0 3 0
  4 0 5

  Matriz transposta:
  1 0 4
  0 3 0
  2 0 5

*/