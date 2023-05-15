#include <stdio.h>
#include "sparse_matrix.h"

int main() {
  SparseMatrix *m1 = sparse_matrix_construct(2, 2);
  sparse_matrix_set(m1, 0, 0, 1);
  sparse_matrix_set(m1, 0, 1, 2);
  sparse_matrix_set(m1, 1, 0, 3);
  sparse_matrix_set(m1, 1, 1, 4);

  SparseMatrix *m2 = sparse_matrix_construct(2, 2);
  sparse_matrix_set(m2, 0, 0, 5);
  sparse_matrix_set(m2, 0, 1, 6);
  sparse_matrix_set(m2, 1, 0, 7);
  sparse_matrix_set(m2, 1, 1, 8);

  SparseMatrix *m_mult = sparse_matrix_mult_point_by_point(m1, m2);
  if (m_mult) {
    sparse_matrix_print(m_mult);
  }

  sparse_matrix_destruct(m1);
  sparse_matrix_destruct(m2);
  sparse_matrix_destruct(m_mult);

  return 0;
}
