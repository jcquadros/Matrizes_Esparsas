#include "libs/sparse_matrix.h"
#include <stdio.h>

int main() {
  SparseMatrix *m = sparse_matrix_construct(3, 3);
  sparse_matrix_set(m, 0, 0, 1);
  sparse_matrix_set(m, 0, 2, 2);
  sparse_matrix_set(m, 1, 1, 3);
  sparse_matrix_set(m, 2, 0, 4);
  sparse_matrix_set(m, 2, 2, 5);
  sparse_matrix_set(m, 1, 2, 6);

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
1.00    0.00    2.00 
0.00    3.00    6.00
4.00    0.00    5.00

Matriz transposta:
1.00    0.00    4.00
0.00    3.00    0.00
2.00    6.00    5.00

*/