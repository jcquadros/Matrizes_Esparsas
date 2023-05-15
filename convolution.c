#include <stdio.h>
#include "sparse_matrix.h"

int main() {
  SparseMatrix *matrix = sparse_matrix_construct(5, 5);
  SparseMatrix *kernel = sparse_matrix_construct(3, 3);

  sparse_matrix_set(matrix, 0, 1, 1);
  sparse_matrix_set(matrix, 0, 3, 1);
  sparse_matrix_set(matrix, 1, 2, 1);
  sparse_matrix_set(matrix, 2, 1, 1);
  sparse_matrix_set(matrix, 3, 3, 1);
  sparse_matrix_set(matrix, 4, 2, 1);

  sparse_matrix_set(kernel, 0, 0, 1);
  sparse_matrix_set(kernel, 0, 1, 2);
  sparse_matrix_set(kernel, 0, 2, 1);
  sparse_matrix_set(kernel, 1, 0, 0);
  sparse_matrix_set(kernel, 1, 1, 0);
  sparse_matrix_set(kernel, 1, 2, 0);
  sparse_matrix_set(kernel, 2, 0, -1);
  sparse_matrix_set(kernel, 2, 1, -2);
  sparse_matrix_set(kernel, 2, 2, -1);

  SparseMatrix *out_matrix = sparse_matrix_convolution(matrix, kernel);

  printf("Matriz de entrada:\n");
  sparse_matrix_print(matrix);
  printf("\nKernel:\n");
  sparse_matrix_print(kernel);
  printf("\nMatriz de saída:\n");
  sparse_matrix_print(out_matrix);

  sparse_matrix_destruct(matrix);
  sparse_matrix_destruct(kernel);
  sparse_matrix_destruct(out_matrix);

  return 0;
}
