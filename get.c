#include <stdio.h>
#include "libs/sparse_matrix.h"

int main()
{
  SparseMatrix *m = sparse_matrix_construct(2, 3);

  sparse_matrix_set(m, 0, 0, 1.0);
  sparse_matrix_set(m, 0, 2, 2.0);
  sparse_matrix_set(m, 1, 1, 3.0);
  sparse_matrix_set(m, 1, 2, 4.0);

  // Testando alguns valores válidos
  printf("Valor em (0,0): %f (esperado: 1.0)\n", sparse_matrix_get(m, 0, 0));
  printf("Valor em (0,2): %f (esperado: 2.0)\n", sparse_matrix_get(m, 0, 2));
  printf("Valor em (1,1): %f (esperado: 3.0)\n", sparse_matrix_get(m, 1, 1));
  printf("Valor em (1,2): %f (esperado: 4.0)\n", sparse_matrix_get(m, 1, 2));

  // Testando alguns valores inválidos -- deve retornar zero e uma mensagem de erro
  printf("Valor em (-1,0): %f (esperado: 0.0)\n", sparse_matrix_get(m, -1, 0));
  printf("Valor em (0,-1): %f (esperado: 0.0)\n", sparse_matrix_get(m, 0, -1));
  printf("Valor em (2,0): %f (esperado: 0.0)\n", sparse_matrix_get(m, 2, 0));
  printf("Valor em (0,3): %f (esperado: 0.0)\n", sparse_matrix_get(m, 0, 3));

  sparse_matrix_destruct(m);

  return 0;
}
/*
Saida esperada
Valor em (0,0): 1.000000 (esperado: 1.0)
Valor em (0,2): 2.000000 (esperado: 2.0)
Valor em (1,1): 3.000000 (esperado: 3.0)
Valor em (1,2): 4.000000 (esperado: 4.0)
Valores invalidos -1 0 para uma matriz de tamanho 2 3
Valor em (-1,0): 0.000000 (esperado: 0.0)
Valores invalidos 0 -1 para uma matriz de tamanho 2 3
Valor em (0,-1): 0.000000 (esperado: 0.0)
Valores invalidos 2 0 para uma matriz de tamanho 2 3
Valor em (2,0): 0.000000 (esperado: 0.0)
Valores invalidos 0 3 para uma matriz de tamanho 2 3
Valor em (0,3): 0.000000 (esperado: 0.0)
*/
