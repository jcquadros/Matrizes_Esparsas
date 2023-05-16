#include <stdio.h>
#include "libs/sparse_matrix.h"

int main() {
  SparseMatrix *m1 = sparse_matrix_construct(2, 2);
  sparse_matrix_set(m1, 0, 0, 1);
  sparse_matrix_set(m1, 1, 0, 3);
  sparse_matrix_set(m1, 1, 1, 4);

  SparseMatrix *m2 = sparse_matrix_construct(2, 2);
  sparse_matrix_set(m2, 0, 0, 5);
  sparse_matrix_set(m2, 0, 1, 6);
  sparse_matrix_set(m2, 1, 0, 7);
  sparse_matrix_set(m2, 1, 1, 8);
  
  SparseMatrix *m_mult = sparse_matrix_mult_point_by_point(m1, m2);
  
  printf("Matriz 1:\n");
  sparse_matrix_print(m1);
  printf("Matriz 2:\n");
  sparse_matrix_print(m2);
  printf("Multiplicacao ponto a ponto da matriz 1 pela matriz 2:\n");
  sparse_matrix_print(m_mult);

  sparse_matrix_destruct(m1);
  sparse_matrix_destruct(m2);
  sparse_matrix_destruct(m_mult);

  return 0;
}
/*
Saída esperada:
Matriz 1:
1.00    0.00
3.00    4.00
Matriz 2:
5.00    6.00
7.00    8.00
Multiplicacao ponto a ponto da matriz 1 pela matriz 2:
5.00    0.00
21.00   32.00
*/