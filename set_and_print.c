#include <stdio.h>
#include "libs/sparse_matrix.h"

int main() {
  SparseMatrix *m = sparse_matrix_construct(4, 5);

  sparse_matrix_set(m, 0, 1, 2.0); // Insere no final/cabeca
  sparse_matrix_set(m, 0, 0, 1.0); // Insere na cabeça
  sparse_matrix_set(m, 0, 2, 3.0); // Insere entre dois elementos
  sparse_matrix_set(m, 1, 1, 4.0); // Substitui um valor por outro número não nulo
  sparse_matrix_set(m, 2, 2, 6.0); // Insere no final
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
/*
Saída esperada:
Valores invalidos -1 0 para uma matriz de tamanho 4 5
Forma Esparsa:
(0,0) = 1.00
(0,1) = 2.00
(0,2) = 3.00
(1,1) = 4.00

Matriz Completa:
1.00    2.00    3.00    0.00    0.00
0.00    4.00    0.00    0.00    0.00
0.00    0.00    0.00    0.00    0.00
0.00    0.00    0.00    0.00    0.00
*/
