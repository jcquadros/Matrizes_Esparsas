#ifndef _SPARCE_MATRIX_H
#define _SPARCE_MATRIX_H
#include "cell.h"
#include "vector.h"

typedef struct{
    int rows;
    int cols;
    int size;
    Vector *vector_rows;
    Vector *vector_cols;
} SparseMatrix;

SparseMatrix *sparse_matrix_construct(int rows, int cols);
void sparse_matrix_set(SparseMatrix *matrix, int row, int col, cell_type value); 
cell_type *sparse_matrix_get_value(SparseMatrix *matrix, int row, int col);
Cell *sparse_matrix_get_cell(SparseMatrix *matrix, int row, int col);
void sparse_matrix_destroy(SparseMatrix *matrix);
void sparse_matrix_print(SparseMatrix * matrix);

#endif
