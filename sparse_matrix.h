#ifndef _SPARSE_MATRIX_H
#define _SPARSE_MATRIX_H
#include "forward_list.h"
#include "node.h"


typedef struct {
  int num_lines;
  int num_columns;
  int size;
  ForwardList *lines;
  ForwardList *columns;
} SparseMatrix;

SparseMatrix *sparse_matrix_construct(int l, int c);
void sparse_matrix_set(SparseMatrix *matrix, int line, int column,
                       data_type value);
void sparse_matrix_print(SparseMatrix *matrix);
data_type sparse_matrix_get(SparseMatrix *matrix, int l, int c);
SparseMatrix *sparse_matrix_sum(SparseMatrix *m1, SparseMatrix *m2);
SparseMatrix *sparse_matrix_mult_by_scalar(SparseMatrix *matrix, data_type num);
SparseMatrix *sparse_matrix_mult_matrix_by_matrix(SparseMatrix *m1,
                                                  SparseMatrix *m2);
SparseMatrix *sparse_matrix_mult_point_by_point(SparseMatrix *m1,
                                                SparseMatrix *m2);
SparseMatrix *sparse_matrix_transpose(SparseMatrix *m);
SparseMatrix *sparse_matrix_swap_col(SparseMatrix *m, int col_1, int col_2);
SparseMatrix *sparse_matrix_swap_line(SparseMatrix *m, int line_1, int line_2);
SparseMatrix *sparse_matrix_slice(SparseMatrix *m, int col_left, int line_up,
                                  int col_right, int line_down);
void sparse_matrix_print_sparse_form(SparseMatrix *m);
void sparse_matrix_write_bin(SparseMatrix *m, char * dir);
SparseMatrix *sparse_matrix_read_bin(char *dir);
SparseMatrix *sparse_matrix_convolution(SparseMatrix *matrix, SparseMatrix * kernel);
void sparse_matrix_destruct(SparseMatrix *m);
#endif