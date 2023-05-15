#include <stdio.h>
#include "sparse_matrix.h"

int main() {
  int l = 4;
  int c = 5;

  SparseMatrix *m = sparse_matrix_construct(l, c);

  sparse_matrix_set(m, 0, 0, 1.0); // Insere na cabeça
  sparse_matrix_set(m, 0, 1, 2.0); // Insere no final
  sparse_matrix_set(m, 0, 2, 3.0); // Insere entre dois elementos
  sparse_matrix_set(m, 1, 1, 4.0); // Substitui um valor por outro número não nulo
  sparse_matrix_set(m, 2, 2, 0.0); // Substitui por um valor nulo
  sparse_matrix_set(m, -1, 0, 5.0); // Elemento fora dos limites da matriz

  printf("Forma Esparsa:\n");
  sparse_matrix_print_sparse_form(m);
  printf("\n");

  printf("Matriz Completa:\n");
  sparse_matrix_print(m);
  printf("\n");

  sparse_matrix_destruct(m);

  return 0;
}
