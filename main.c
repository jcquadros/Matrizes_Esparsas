#include "cell.h"
#include "sparse_matrix.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int rows = 2, cols = 2;
  SparseMatrix *m = sparse_matrix_construct(rows, cols);
  printf("Construidos: \n");

  sparse_matrix_set(m,0,1,2);
  sparse_matrix_set(m,0,0,1);
     // sparse_matrix_set(m, 0, 2, 3);
  // sparse_matrix_set(m, 0, 3, 4);
  // sparse_matrix_set(m, 1, 0, 3);
  // sparse_matrix_set(m, 1, 1, 4);

  // Cell * cell = vector_get(m->vector_rows, 1);
  // if(cell){
  //     printf("%f ", cell->value);
  //     printf("%p ", cell->next_column);
  //     printf("%p ", cell->next_line);
  // }

  sparse_matrix_print(m);
  printf("\nDesalocados:\n");
  sparse_matrix_destroy(m);
  return 0;
}