#include "sparse_matrix.h"
#include <stdio.h>
#include <stdlib.h>

SparseMatrix *sparse_matrix_construct(int rows, int cols) {
  SparseMatrix *m = (SparseMatrix *)calloc(1, sizeof(SparseMatrix));
  m->rows = rows;
  m->cols = cols;
  m->vector_rows = vector_construct();
  m->vector_cols = vector_construct();
  for (int i = 0; i < rows; i++) {
    vector_insert(m->vector_rows, i, NULL);
  }
  for (int i = 0; i < cols; i++) {
    vector_insert(m->vector_cols, i, NULL);
  }
  return m;
}

void sparse_matrix_print(SparseMatrix *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    int prev_col = 0;
    Cell *c = vector_get(matrix->vector_rows, i);
    while (c) {
      for (int j = prev_col; j < c->column; j++)
        printf("0.00 ");
      printf("%.2f ", c->value);
      prev_col = c->column + 1;
      c = c->next_column;
    }
    for (int j = prev_col; j < matrix->cols; j++) {
      printf("0.00 ");
    }
    printf("\n");
  }
}

void sparse_matrix_set(SparseMatrix *matrix, int row, int col, cell_type value) {
  if (!matrix || row >= matrix->rows || col >= matrix->cols || row < 0 || col < 0) {
    // coordenadas invalidas ou ponteiro nulo
    return;
  }
  Cell *cell = vector_get(matrix->vector_rows, row);
  Cell *prev = NULL;
  // percorrer ate a posicao certa para inserir
  while (cell != NULL && cell->column < col) {
    prev = cell;
    cell = cell->next_column;
  }
  // se já existia uma celula só altero o valor
  if (cell != NULL && cell->column == col) {
    printf("alterando o valor interno de %f para %f\n", cell->value, value);
    cell->value = value;
  } else {
    if(!cell){
      printf("valor nulo\n");
    }
    Cell *new_cell = cell_construct(row, col, value, NULL, NULL);
    
    // inserindo entre dois elementos
    if(cell!=NULL && cell->column > col && prev == NULL ){
      printf("inserindo uma celula na cabeca apontando para outro\n");
      cell_print(new_cell);
      cell_print(cell);
      new_cell->next_column = cell;
      vector_set(matrix->vector_rows, row, new_cell);
    }
    else if(cell != NULL && cell->column > col){
      printf("Inserindo entre dois elementos:\n");
      cell_print(new_cell);
      //  if(!prev){
      //   printf("e pra adicionar a cabeca\n");
      //   vector_insert(matrix->vector_rows, row, new_cell);
      //  }
      cell_insert_column(new_cell, prev, cell);
    }

    // inserir apos o ultimo
    else if (!cell) {
      printf("inserindo uma celula apos o ultimo elemento ");
      cell_print(new_cell);
      // se nao existiam elementos na linha, entao sera a cabeca do vetor
      if (!prev) {
        vector_set(matrix->vector_rows, row, new_cell);
      }
      cell_insert_column(new_cell, prev, NULL);
    }
    // // inserir entre dois elementos
    // else {
    //   cell_insert_column(new_cell, vector_get(matrix->vector_rows,row),NULL);
    //   if (!prev) {
    //     vector_set(matrix->vector_rows, row, new_cell);
    //   } else {
    //    cell_insert_column(new_cell, prev, NULL);
    //   }
    // }
  }
}

// void sparse_matrix_set(SparseMatrix *matrix, int row, int col,
//                        cell_type value) {
//   if (row >= matrix->rows || col >= matrix->cols || row < 0 || col < 0) {
//     // coordenadas invalidas
//     return;
//   }
//   Cell *cell = vector_get(matrix->vector_rows, row);
//   Cell *prev = NULL;
//   // percorrer ate a posicao certa para inserir
//   while (cell != NULL && cell->column < col) {
//     prev = cell;
//     cell = cell->next_column;
//   }
//   // se já existia uma celula só altero o valor
//   if (cell != NULL && cell->column == col) {
//     cell->value = value;

//   } else {
//     Cell *new_cell = cell_construct(row, col, value, NULL, NULL);
//     // inserir apos o ultimo
//     if (!cell) {
//       cell_insert_column(new_cell, prev, NULL);
//       // se nao existiam elementos na linha, entao sera a cabeca do vetor
//       if (!prev) {
//         vector_insert(matrix->vector_rows, row, new_cell);
//       }
//     }

//     // inserir entre dois elementos
//     else if (cell->column > col) {
//       cell_insert_column(new_cell, prev, cell);
//       if (!prev) {
//         vector_insert(matrix->vector_rows, row, new_cell);
//       }
//     }

//     // // agora é inserir na coluna
//     // cell = vector_get(matrix->vector_cols, col);
//     // while (cell != NULL && cell->row < row) {
//     //   prev = cell;
//     //   cell = cell->next_row;
//     // }

//     // if (!cell) {
//     //   cell_insert_row(new_cell, prev, NULL);
//     //   if (!prev) {
//     //     vector_insert(matrix->vector_cols, col, new_cell);
//     //   }
//     // }

//     // else if (cell->row > row) {
//     //   cell_insert_row(new_cell, prev, cell);
//     //   if (!prev) {
//     //     vector_insert(matrix->vector_cols, col, new_cell);
//     //   }
//     // }
//   }

//   matrix->size++;
//   // Cell *cell = vector_get(matrix->vector_rows, row);
//   // while (cell != NULL && cell->column < col) {
//   //   cell = cell->next_column;
//   // }
//   // if (cell != NULL && cell->column == col) {
//   //   cell->value = value;
//   // } else {
//   //   Cell *new_cell = cell_construct(row, col, value);
//   //   if (cell == NULL) {
//   //     vector_insert(matrix->vector_rows, row, new_cell);
//   //   } else {
//   //     new_cell->next_column = cell->next_column;
//   //     cell->next_column = new_cell;
//   //   }

//   //   cell = vector_get(matrix->vector_cols, col);

//   //   while (cell != NULL && cell->row < row) {
//   //     cell = cell->next_row;
//   //   }
//   //   if (cell != NULL && cell->row == row) {
//   //     cell->value = value;
//   //   } else {
//   //     matrix->size++;
//   //   }
//   //   if (cell == NULL) {
//   //     vector_insert(matrix->vector_cols, col, new_cell);
//   //   } else {
//   //     new_cell->next_row = cell->next_row;
//   //     cell->next_row = new_cell;
//   //   }
//   // }
// }

void sparse_matrix_destroy(SparseMatrix *m) {
  for (int i = 0; i < m->rows; i++) {
    Cell *c = vector_get(m->vector_rows, i);
    while (c) {
      cell_print(c);
      Cell *aux = c->next_column;
      cell_destroy(c);
      c = aux;
    }
  }
  vector_destroy(m->vector_rows);
  vector_destroy(m->vector_cols);
  free(m);
}