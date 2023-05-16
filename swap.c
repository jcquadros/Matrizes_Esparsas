#include "libs/sparse_matrix.h"
#include <stdio.h>

int main() {
 
  SparseMatrix *m = sparse_matrix_construct(3, 3);
  sparse_matrix_set(m, 0, 0, 1);
  sparse_matrix_set(m, 0, 1, 2);
  sparse_matrix_set(m, 0, 2, 3);
  sparse_matrix_set(m, 1, 0, 4);
  sparse_matrix_set(m, 1, 1, 5);
  sparse_matrix_set(m, 1, 2, 6);
  sparse_matrix_set(m, 2, 0, 7);
  sparse_matrix_set(m, 2, 1, 8);
  sparse_matrix_set(m, 2, 2, 9);

  printf("Matriz original:\n");
  sparse_matrix_print(m);

   // Teste da função sparse_matrix_swap_col
  SparseMatrix *m_swapped_col = sparse_matrix_swap_col(m, 0, 2);

  printf("Matriz com colunas 0 e 2 trocadas:\n");
  sparse_matrix_print(m_swapped_col);
  sparse_matrix_destruct(m_swapped_col);

  // Teste da função sparse_matrix_swap_line
  printf("Matriz original:\n");
  sparse_matrix_print(m);
  SparseMatrix *m_swapped_line = sparse_matrix_swap_line(m, 0, 2);

  printf("Matriz com linhas 0 e 2 trocadas:\n");
  sparse_matrix_print(m_swapped_line);
  sparse_matrix_destruct(m_swapped_line);

  // Teste de casos de erro
  SparseMatrix *m_swapped_col2 = sparse_matrix_swap_col(m, 0, 5);
  // coluna 5 fora dos limites

  sparse_matrix_destruct(m_swapped_col2);
  sparse_matrix_destruct(m);

  return 0;
}
/*
Saida esperada
Matriz original:
1.00    2.00    3.00 
4.00    5.00    6.00 
7.00    8.00    9.00 
Matriz com colunas 0 e 2 trocadas:
3.00    2.00    1.00
6.00    5.00    4.00
9.00    8.00    7.00
Matriz original:
1.00    2.00    3.00
4.00    5.00    6.00
7.00    8.00    9.00
Matriz com linhas 0 e 2 trocadas:
7.00    8.00    9.00
4.00    5.00    6.00
1.00    2.00    3.00
valores invalidos de colunas 0 e 5
*/
