#include <stdio.h>
#include "sparse_matrix.h"

int main() {
  SparseMatrix *m1 = sparse_matrix_construct(3, 4);
  SparseMatrix *m2 = sparse_matrix_construct(3, 4);
  SparseMatrix *m3 = sparse_matrix_construct(4, 2);

  sparse_matrix_set(m1, 0, 1, 2.0);
  sparse_matrix_set(m1, 1, 2, 4.0);
  sparse_matrix_set(m1, 2, 3, 6.0);

  sparse_matrix_set(m2, 0, 1, 1.0);
  sparse_matrix_set(m2, 1, 2, 2.0);
  sparse_matrix_set(m2, 2, 3, 3.0);

  sparse_matrix_set(m3, 0, 0, 1.0);
  sparse_matrix_set(m3, 0, 1, 2.0);
  sparse_matrix_set(m3, 1, 0, 3.0);
  sparse_matrix_set(m3, 1, 1, 4.0);
  sparse_matrix_set(m3, 2, 0, 5.0);
  sparse_matrix_set(m3, 2, 1, 6.0);
  sparse_matrix_set(m3, 3, 0, 7.0);
  sparse_matrix_set(m3, 3, 1, 8.0);

  SparseMatrix *m_sum = sparse_matrix_sum(m1, m2);
  SparseMatrix *m_scalar_mult = sparse_matrix_mult_by_scalar(m1, 2.0);
  SparseMatrix *m_matrix_mult = sparse_matrix_mult_matrix_by_matrix(m1, m3);

  printf("Matriz 1:\n");
  sparse_matrix_print(m1);
  printf("Matriz 2:\n");
  sparse_matrix_print(m2);
  printf("Matriz 3:\n");
  sparse_matrix_print(m3);
  printf("Soma de matriz 1 com matriz 2:\n");
  sparse_matrix_print(m_sum);
  printf("Multiplicação da matriz 1 por 2.0:\n");
  sparse_matrix_print(m_scalar_mult);
  printf("Multiplicação da matriz 1 por matriz 3:\n");
  sparse_matrix_print(m_matrix_mult);

  sparse_matrix_destruct(m1);
  sparse_matrix_destruct(m2);
  sparse_matrix_destruct(m3);
  sparse_matrix_destruct(m_sum);
  sparse_matrix_destruct(m_scalar_mult);
  sparse_matrix_destruct(m_matrix_mult);

  return 0;
}
