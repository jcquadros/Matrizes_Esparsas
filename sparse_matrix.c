#include "sparse_matrix.h"
#include <stdio.h>
#include <stdlib.h>

// O(1)
SparseMatrix *sparse_matrix_construct(int l, int c) {
  SparseMatrix *m = (SparseMatrix *)calloc(1, sizeof(SparseMatrix));
  m->num_lines = l;
  m->num_columns = c;
  m->size = 0;
  m->columns = (ForwardList *)calloc(c, sizeof(ForwardList));
  m->lines = (ForwardList *)calloc(l, sizeof(ForwardList));
  return m;
}

// O(m) elementos nao nulos das linhas e elementos nao nulos das colunas
void sparse_matrix_set(SparseMatrix *m, int l, int c, data_type value) {
  if (l >= m->num_lines || c >= m->num_columns || l < 0 || c < 0) {
    printf("Valores invalidos %d %d para uma matriz de tamanho %d %d\n", l, c,
           m->num_lines, m->num_columns);
    return;
  }

  ForwardList *list_h = &m->lines[l];
  ForwardList *list_v = &m->columns[c];
  Node *node_h = list_h->head;
  Node *prev_h = NULL;
  Node *node_v = list_v->head;
  Node *prev_v = NULL;

  while (node_h != NULL && node_h->col < c) {
    prev_h = node_h;
    node_h = node_h->next_col;
  }

  while (node_v != NULL && node_v->line < l) {
    prev_v = node_v;
    node_v = node_v->next_line;
  }

  if ((node_h != NULL && node_h->col == c) &&
      (node_v != NULL && node_v->line == l)) {
    if (value == 0.0) {
      forward_list_remove_h(list_h, prev_h, node_h);
      forward_list_remove_v(list_v, prev_v, node_v);
      free(node_h);
      m->size--;

    } else {
      node_h->value = value;
    }

  } else if (value != 0.0) {
    Node *new_node = node_construct(value, l, c, NULL, NULL);
    forward_list_insert_between_h(list_h, new_node, prev_h, node_h);
    forward_list_insert_between_v(list_v, new_node, prev_v, node_v);
    m->size++;
  } else {
    printf("Nada a ser adicionado\n");
  }
}
// O(n) nao nulos da linha
data_type sparse_matrix_get(SparseMatrix *matrix, int l, int c) {
  if (l >= matrix->num_lines || c >= matrix->num_columns || l < 0 || c < 0) {
    printf("Valores invalidos %d %d para uma matriz de tamanho %d %d\n", l, c,
           matrix->num_lines, matrix->num_columns);
    return 0.0;
  }
  ForwardList *list_h = &matrix->lines[l];
  Node *node_h = list_h->head;

  while (node_h != NULL && node_h->col < c) {
    node_h = node_h->next_col;
  }
  if (node_h != NULL && node_h->col == c) {
    return node_h->value;
  } else {
    return 0.0;
  }
}

// O(n * m) numero de linhas + numero elementos nao nulos * ordem da função de
// setar a matriz
SparseMatrix *sparse_matrix_swap_col(SparseMatrix *m, int col_1, int col_2) {
  if (!m) {
    return NULL;
  }
  if (col_1 >= m->num_columns || col_2 >= m->num_columns || col_1 < 0 ||
      col_2 < 0) {
    printf("valores invalidos de colunas %d e %d\n", col_1, col_2);
    return NULL;
  }
  SparseMatrix *m_out = sparse_matrix_construct(m->num_lines, m->num_columns);
  for (int i = 0; i < m->num_lines; i++) {
    Node *node = m->lines[i].head;
    while (node) {
      if (node->col == col_1) {
        sparse_matrix_set(m_out, node->line, col_2, node->value);
      } else if (node->col == col_2) {
        sparse_matrix_set(m_out, node->line, col_1, node->value);
      } else {
        sparse_matrix_set(m_out, node->line, node->col, node->value);
      }
      node = node->next_col;
    }
  }
  return m_out;
}

// O(n * m) numero de linhas + numero elementos nao nulos * ordem da função de
// setar a matriz
SparseMatrix *sparse_matrix_swap_line(SparseMatrix *m, int line_1, int line_2) {
  if (!m) {
    return NULL;
  }
  if (line_1 >= m->num_columns || line_2 >= m->num_columns || line_1 < 0 ||
      line_2 < 0 || line_1 == line_2) {
    printf("valores invalidos de colunas %d e %d\n", line_1, line_2);
    return NULL;
  }

  SparseMatrix *m_out = sparse_matrix_construct(m->num_lines, m->num_columns);

  for (int i = 0; i < m->num_lines; i++) {
    Node *node = m->lines[i].head;
    while (node) {
      if (node->line == line_1) {
        sparse_matrix_set(m_out, line_2, node->col, node->value);
      } else if (node->line == line_2) {
        sparse_matrix_set(m_out, line_1, node->col, node->value);
      } else {
        sparse_matrix_set(m_out, node->line, node->col, node->value);
      }
      node = node->next_col;
    }
  }
  return m_out;
}

// O(n * m) numero de elementos nao nulos dentro do intervalo de linhas
// percorrido + o intervalo de linhas percorrido * a ordem da funcao de setar
// matriz
SparseMatrix *sparse_matrix_slice(SparseMatrix *m, int col_left, int line_up,
                                  int col_right, int line_down) {
  if (!m) {
    return NULL;
  }

  int new_num_lines = line_down - line_up + 1;
  int new_num_columns = col_right - col_left + 1;

  // Caso a submatriz esteja fora dos limites da matriz
  if (col_left >= col_right || line_up >= line_down ||
      col_left >= m->num_columns || col_left < 0 ||
      col_right >= m->num_columns || col_right < 0 || line_up >= m->num_lines ||
      line_up < 0 || line_down >= m->num_lines || line_down < 0) {
    printf("Coordenadas invalidas para gerar uma submatriz\n");
    return NULL;
  }
  
  SparseMatrix *m_out = sparse_matrix_construct(new_num_lines, new_num_columns);

  for (int i = line_up; i <= line_down; i++) {
    Node *node = m->lines[i].head;
    while (node) {
      if (node->col >= col_left && node->col <= col_right) {
        sparse_matrix_set(m_out, node->line - line_up, node->col - col_left,
                          node->value);
      }
      node = node->next_col;
    }
  }

  return m_out;
}

// O(n^2)
void sparse_matrix_print(SparseMatrix *matrix) {
  if (!matrix) {
    return;
  }
  for (int i = 0; i < matrix->num_lines; i++) {
    Node *node = matrix->lines[i].head;
    for (int j = 0; j < matrix->num_columns; j++) {
      if (node != NULL && node->col == j) {
        printf("%.2f \t", node->value);
        node = node->next_col;
      } else {
        printf("0.00 \t");
      }
    }
    printf("\n");
  }
}

// O(n * m) nao nulos das duas matrizes + numero de linhas * ordem da funcao de setar a matriz
SparseMatrix *sparse_matrix_sum(SparseMatrix *m1, SparseMatrix *m2) {
  if (m1->num_lines != m2->num_lines || m1->num_columns != m2->num_columns) {
    printf("Impossivel somar duas matrizes de tamanhos diferentes:\n Matriz 1: "
           "(%d,%d) != Matriz 2: (%d,%d)\n",
           m1->num_lines, m1->num_columns, m2->num_lines, m2->num_columns);
    return NULL;
  }

  SparseMatrix *m_sum = sparse_matrix_construct(m1->num_lines, m1->num_columns);

  for (int i = 0; i < m_sum->num_lines; i++) {
    Node *node_m1 = m1->lines[i].head;
    Node *node_m2 = m2->lines[i].head;
    while (node_m1 || node_m2) {
      if (node_m1 && node_m2) {
        if (node_m1->col == node_m2->col) {
          data_type sum = node_m1->value + node_m2->value;
          if (sum != 0.0) {
            sparse_matrix_set(m_sum, i, node_m1->col, sum);
          }
          node_m1 = node_m1->next_col;
          node_m2 = node_m2->next_col;
        } else if (node_m1->col < node_m2->col) {
          sparse_matrix_set(m_sum, i, node_m1->col, node_m1->value);
          node_m1 = node_m1->next_col;
        } else { // node_m2->col < node_m1->col
          sparse_matrix_set(m_sum, i, node_m2->col, node_m2->value);
          node_m2 = node_m2->next_col;
        }
      } else if (node_m1) {
        sparse_matrix_set(m_sum, i, node_m1->col, node_m1->value);
        node_m1 = node_m1->next_col;
      } else { // node_m2
        sparse_matrix_set(m_sum, i, node_m2->col, node_m2->value);
        node_m2 = node_m2->next_col;
      }
    }
  }

  return m_sum;
}

// O(n * m) = n nao nulos da matriz + numero de linhas * ordem da funcao de setar matrizes
SparseMatrix *sparse_matrix_mult_by_scalar(SparseMatrix *matrix,
                                           data_type num) {
  if (!matrix) {
    printf("A matriz nao existe!\n");
    return NULL;
  }
  SparseMatrix *matrix_mult =
      sparse_matrix_construct(matrix->num_lines, matrix->num_columns);
  if (num == 0.0) {
    return matrix_mult;
  }
  for (int i = 0; i < matrix->num_lines; i++) {
    Node *node = matrix->lines[i].head;
    while (node) {
      sparse_matrix_set(matrix_mult, node->line, node->col, node->value * num);
      node = node->next_col;
    }
  }
  return matrix_mult;
}

// O(n^3) = tem tres loops dos quais  um itera sobre os elementos nao nulos da
// matrix
SparseMatrix *sparse_matrix_mult_matrix_by_matrix(SparseMatrix *m1,
                                                  SparseMatrix *m2) {
  printf("\n\n\n");

  if (!m1 || !m2) {
    printf("Uma das matrizes nao existe!\n");
    return NULL;
  }
  if (m1->num_columns != m2->num_lines) {
    printf("Impossivel de multiplicar essas duas matrizes: numero de colunas "
           "de m1 diferente do numero de linhas de m2.\n");
    return NULL;
  }
  SparseMatrix *matrix_mult =
      sparse_matrix_construct(m1->num_lines, m2->num_columns);

  for (int i = 0; i < m1->num_lines; i++) {
    for (int j = 0; j < m2->num_columns; j++) {
      Node *node_m1_h = m1->lines[i].head;
      Node *node_m2_v = m2->columns[j].head;
      // printf("Calculando linha %d coluna %d:\n", i, j);
      data_type total = 0;
      while (node_m1_h && node_m2_v) {
        if (node_m1_h->col == node_m2_v->line) {
          total += node_m1_h->value * node_m2_v->value;
          node_m1_h = node_m1_h->next_col;
          node_m2_v = node_m2_v->next_line;
        } else if (node_m1_h->col < node_m2_v->line) {
          node_m1_h = node_m1_h->next_col;
        } else {
          node_m2_v = node_m2_v->next_line;
        }
      }

      if (total != 0) {
        sparse_matrix_set(matrix_mult, i, j, total);
      }
    }
  }
  return matrix_mult;
}

// O(n * m) = numero de elementos nao nulos da matriz + numero de linhas * ordem da funcao de setar
SparseMatrix *sparse_matrix_mult_point_by_point(SparseMatrix *m1,
                                                SparseMatrix *m2) {
  if (m1->num_lines != m2->num_lines || m1->num_columns != m2->num_columns) {
    printf("Impossivel multiplicar ponto a ponto duas matrizes de tamanhos "
           "diferentes:\n Matriz 1: "
           "(%d,%d) != Matriz 2: (%d,%d)\n",
           m1->num_lines, m1->num_columns, m2->num_lines, m2->num_columns);
    return NULL;
  }
  if (!m1 || !m2) {
    printf("Uma das matrizes nao existe!\n");
    return NULL;
  }
  SparseMatrix *m_mult =
      sparse_matrix_construct(m1->num_lines, m1->num_columns);
  for (int i = 0; i < m1->num_lines; i++) {
    Node *node_m1 = m1->lines[i].head;
    Node *node_m2 = m2->lines[i].head;
    while (node_m1 && node_m2) {
      if (node_m1->col == node_m2->col) {
        data_type total = node_m1->value * node_m2->value;
        if (total != 0) {
          sparse_matrix_set(m_mult, node_m1->line, node_m1->col, total);
        }
        node_m1 = node_m1->next_col;
        node_m2 = node_m2->next_col;
      } else if (node_m1->col < node_m2->col) {
        node_m1 = node_m1->next_col;
      } else {
        node_m2 = node_m2->next_col;
      }
    }
  }
  return m_mult;
}

// O(n * m) numero de elementos nao nulos + o numero de linhas * funcao de setar a matriz
SparseMatrix *sparse_matrix_transpose(SparseMatrix *m) {
  if (!m) {
    return NULL;
  }
  SparseMatrix *m_t = sparse_matrix_construct(m->num_columns, m->num_lines);
  for (int i = 0; i < m->num_lines; i++) {
    Node *node = m->lines[i].head;
    while (node) {
      sparse_matrix_set(m_t, node->col, node->line, node->value);
      node = node->next_col;
    }
  }
  return m_t;
}

// O(n) numero de elementos nao nulos + o numero de linhas
void sparse_matrix_print_sparse_form(SparseMatrix *m) {
  if (!m) {
    return;
  }
  for (int i = 0; i < m->num_lines; i++) {
    Node *node = m->lines[i].head;
    while (node) {
      node_print(node);
      node = node->next_col;
    }
  }
}

// O(n) = numero de elementos nao nulos da matriz + numero de linhas
void sparse_matrix_write_bin(SparseMatrix *m, char *dir) {
  FILE *f = fopen(dir, "wb");
  if (!f) {
    printf("Erro ao abrir o arquivo:%s\n", dir);
    return;
  }
  fwrite(&m->num_lines, sizeof(int), 1, f);
  fwrite(&m->num_columns, sizeof(int), 1, f);
  fwrite(&m->size, sizeof(int), 1, f);

  for (int i = 0; i < m->num_lines; i++) {
    Node *node = m->lines[i].head;
    while (node) {
      fwrite(&node->line, sizeof(int), 1, f);
      fwrite(&node->col, sizeof(int), 1, f);
      fwrite(&node->value, sizeof(data_type), 1, f);
    }
  }
}

// O(n) = numero de elementos nao nulos da matriz + numero de linhas
SparseMatrix *sparse_matrix_read_bin(char *dir) {
  FILE *f = fopen(dir, "rb");
  if (!f) {
    printf("Erro ao abrir o arquivo:%s\n", dir);
    return NULL;
  }
  int lines, columns, size;
  if (fread(&lines, sizeof(int), 1, f) > 0 &&
      fread(&columns, sizeof(int), 1, f) > 0 &&
      fread(&size, sizeof(int), 1, f) > 0) {

    SparseMatrix *m = sparse_matrix_construct(lines, columns);
    for (int i = 0; i < size; i++) {
      int line, col, value;
      if (fread(&line, sizeof(int), 1, f) > 0 &&
          fread(&col, sizeof(int), 1, f) > 0 &&
          fread(&value, sizeof(data_type), 1, f) > 0) {
        sparse_matrix_set(m, line, col, value);
      } else {
        printf("Atencao! Algum valor nao foi lido corretamente e portanto nao "
               "adicionado na matriz\n");
      }
    }
    return m;
  } else {
    printf("Erro ao ler o arquivo binario\n");
    return NULL;
  }
}

// O(n^4) = percorre toda a matriz principal O(n^2) * o kernel O(k^2)
SparseMatrix *sparse_matrix_convolution(SparseMatrix *matrix,
                                        SparseMatrix *kernel) {
  if (!matrix || !kernel) {
    printf("Erro, uma das matrizes é invalida");
    return NULL;
  }
  if (kernel->num_lines != kernel->num_columns || kernel->num_lines % 2 == 0 ||
      kernel->num_columns % 2 == 0) {
    printf("Tamanho do kernel invalido. Nao eh uma matriz quadrada ou nao "
           "possui elemento central\n");
    return NULL;
  }
  int half_width = kernel->num_columns / 2;
  int half_height = kernel->num_lines / 2;
  data_type sum = 0;

  // Cria uma matriz com o mesmo tamanho da de entrada
  SparseMatrix *out_matrix =
      sparse_matrix_construct(matrix->num_lines, matrix->num_columns);

  for (int i = 0; i < matrix->num_lines; i++) {
    for (int j = 0; j < matrix->num_columns; j++) {
      sum = 0;

      // Loop para percorer diretamente sobre a submatriz dentro dos limites da
      // matriz principal como forma de otimizar o código e evitar criar outra
      // matriz com a funcao sparse_matrix_slice() e ainda mais outra com a
      // funcao de sparse_matrix_mult_point_by_point()
      for (int k = -half_height; k <= half_height; k++) {
        for (int l = -half_width; l <= half_width; l++) {
          int row = i + k;
          int col = j + l;
          // Se está dentro de um intervalo válido da matriz principal
          if (row >= 0 && row < matrix->num_lines && col >= 0 &&
              col < matrix->num_columns) {
            // Aqui recuperamos os valores que estao sobrepostos na submatriz e
            // do kernel. Nao é tao otimizado, mas deixa o codigo mais legivel
            data_type value = sparse_matrix_get(matrix, row, col);
            data_type kernel_value =
                sparse_matrix_get(kernel, k + half_height, l + half_width);
            sum += value * kernel_value;
          }
        }
      }
      // Insere o valor total na matriz principal
      if (sum != 0) {
        sparse_matrix_set(out_matrix, i, j, sum);
      }
    }
  }
  return out_matrix;
}

// O(n) = elementos nao nulos e linhas
void sparse_matrix_destruct(SparseMatrix *m) {
  if (!m) {
    return;
  }
  for (int i = 0; i < m->num_lines; i++) {
    forward_list_destroy_h(&m->lines[i]);
  }
  free(m->columns);
  free(m->lines);
  free(m);
}