#include <stdio.h>
#include "sparse_matrix.h"

int main() {
  SparseMatrix *m = sparse_matrix_construct(5, 5);
  sparse_matrix_set(m, 1, 2, 1);
  sparse_matrix_set(m, 2, 1, 2);
  sparse_matrix_set(m, 2, 2, 3);
  sparse_matrix_set(m, 2, 3, 4);
  sparse_matrix_set(m, 3, 2, 5);
  sparse_matrix_set(m, 4, 0, 6);
  sparse_matrix_set(m, 4, 4, 7);

  SparseMatrix *m_out = sparse_matrix_slice(m, 1, 1, 3, 3);
  sparse_matrix_print(m_out);

  sparse_matrix_destruct(m);
  sparse_matrix_destruct(m_out);

  printf("\n");

  m = sparse_matrix_construct(4, 4);
  sparse_matrix_set(m, 1, 1, 1);
  sparse_matrix_set(m, 2, 2, 2);
  sparse_matrix_set(m, 3, 3, 3);
  sparse_matrix_set(m, 0, 0, 4);
  sparse_matrix_set(m, 0, 3, 5);
  sparse_matrix_set(m, 3, 0, 6);

  m_out = sparse_matrix_slice(m, 0, 0, 3, 3);
  sparse_matrix_print(m_out);

  sparse_matrix_destruct(m);
  sparse_matrix_destruct(m_out);

  printf("\n");

  m = sparse_matrix_construct(3, 3);
  sparse_matrix_set(m, 0, 0, 1);
  sparse_matrix_set(m, 1, 1, 2);
  sparse_matrix_set(m, 2, 2, 3);

  m_out = sparse_matrix_slice(m, 2, 2, 4, 4);
  sparse_matrix_print(m_out);

  sparse_matrix_destruct(m);
  sparse_matrix_destruct(m_out);

  printf("\n");

  m = sparse_matrix_construct(5, 5);

  m_out = sparse_matrix_slice(m, 1, 1, 3, 3);
  sparse_matrix_print(m_out);

  sparse_matrix_destruct(m);
  sparse_matrix_destruct(m_out);

  return 0;
}
/*
3 4 
0 0 

1 2 0 
0 3 4 
0 5 0 

0 

Coordenadas invalidas para gerar uma submatriz
*/