#include <stdio.h>
#include "sparse_matrix.h"

int main() {
  SparseMatrix *m = sparse_matrix_construct(3, 3);
  sparse_matrix_set(m, 0, 0, 1);
  sparse_matrix_set(m, 1, 1, 2);
  sparse_matrix_set(m, 2, 2, 3);
  sparse_matrix_set(m, 1, 2, 4);
  sparse_matrix_set(m, 2, 0, 5);

  char *dir = "matriz.bin";
  sparse_matrix_write_bin(m, dir);
  SparseMatrix *m_read = sparse_matrix_read_bin(dir);

  printf("Matriz original:\n");
  sparse_matrix_print(m);

  printf("\nMatriz lida do arquivo:\n");
  sparse_matrix_print(m_read);

  sparse_matrix_destruct(m);
  sparse_matrix_destruct(m_read);
  return 0;
}
/*
Saida esperada:
  Matriz original:
  |1.0000 0.0000 0.0000|
  |0.0000 2.0000 4.0000|
  |5.0000 0.0000 3.0000|
  
  Matriz lida do arquivo:
  |1.0000 0.0000 0.0000|
  |0.0000 2.0000 4.0000|
  |5.0000 0.0000 3.0000|

*/
