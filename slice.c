#include <stdio.h>
#include "libs/sparse_matrix.h"

int main()
{
  SparseMatrix *m = sparse_matrix_construct(5, 5);
  sparse_matrix_set(m, 1, 2, 1);
  sparse_matrix_set(m, 2, 1, 2);
  sparse_matrix_set(m, 2, 2, 3);
  sparse_matrix_set(m, 2, 3, 4);
  sparse_matrix_set(m, 3, 2, 5);
  sparse_matrix_set(m, 4, 0, 6);
  sparse_matrix_set(m, 4, 4, 7);

  printf("Matriz original:\n");
  sparse_matrix_print(m);

  SparseMatrix *m_out = sparse_matrix_slice(m, 1, 1, 3, 3);

  printf("Submatriz da original das coordenadas (l,c): (1,1) a (3,3)\n");
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

  printf("Matriz original:\n");
  sparse_matrix_print(m);

  m_out = sparse_matrix_slice(m, 0, 0, 3, 3);
  printf("Submatriz da original das coordenadas (l,c): (0,0) a (3,3)\n");
  sparse_matrix_print(m_out);

  sparse_matrix_destruct(m);
  sparse_matrix_destruct(m_out);

  printf("\n");

  m = sparse_matrix_construct(3, 3);
  sparse_matrix_set(m, 0, 0, 1);
  sparse_matrix_set(m, 1, 1, 2);
  sparse_matrix_set(m, 2, 2, 3);

  printf("Matriz original:\n");
  sparse_matrix_print(m);

  m_out = sparse_matrix_slice(m, 2, 2, 4, 4);
  printf("Submatriz da original das coordenadas (l,c): (2,2) a (4,4)\n");
  sparse_matrix_print(m_out);

  sparse_matrix_destruct(m);
  sparse_matrix_destruct(m_out);

  printf("\n");

  m = sparse_matrix_construct(5, 5);

  printf("Matriz original:\n");
  sparse_matrix_print(m);

  m_out = sparse_matrix_slice(m, 1, 1, 3, 3);
  printf("Submatriz da original das coordenadas (l,c): (1,1) a (3,3)\n");
  sparse_matrix_print(m_out);

  sparse_matrix_destruct(m);
  sparse_matrix_destruct(m_out);

  return 0;
}
/*
Saída esperada:

Matriz original:
0.00    0.00    0.00    0.00    0.00 
0.00    0.00    1.00    0.00    0.00 
0.00    2.00    3.00    4.00    0.00 
0.00    0.00    5.00    0.00    0.00 
6.00    0.00    0.00    0.00    7.00 
Submatriz da original das coordenadas (l,c): (1,1) a (3,3)
0.00    1.00    0.00 
2.00    3.00    4.00 
0.00    5.00    0.00 

Matriz original:
4.00    0.00    0.00    5.00 
0.00    1.00    0.00    0.00 
0.00    0.00    2.00    0.00 
6.00    0.00    0.00    3.00 
Submatriz da original das coordenadas (l,c): (0,0) a (3,3)
4.00    0.00    0.00    5.00 
0.00    1.00    0.00    0.00 
0.00    0.00    2.00    0.00 
6.00    0.00    0.00    3.00 

Matriz original:
1.00    0.00    0.00 
0.00    2.00    0.00 
0.00    0.00    3.00
Coordenadas invalidas para gerar uma submatriz
Submatriz da original das coordenadas (l,c): (2,2) a (4,4)

Matriz original:
0.00    0.00    0.00    0.00    0.00
0.00    0.00    0.00    0.00    0.00
0.00    0.00    0.00    0.00    0.00
0.00    0.00    0.00    0.00    0.00
0.00    0.00    0.00    0.00    0.00
Submatriz da original das coordenadas (l,c): (1,1) a (3,3)
0.00    0.00    0.00
0.00    0.00    0.00
0.00    0.00    0.00
*/