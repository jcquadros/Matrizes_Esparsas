#include <stdio.h>
#include <stdlib.h>
#include "sparce_matrix.h"

SparseMatrix *sparse_matrix_construct(int rows, int cols)
{
    SparseMatrix *m = (SparseMatrix *)calloc(1, sizeof(SparseMatrix));
    m->rows = rows;
    m->cols = cols;
    m->vector_rows = vector_construct(rows);
    m->vector_cols = vector_construct(cols);
    return m;
}

void sparse_matrix_print(SparseMatrix *matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        int prev_col = 0;
        Cell *c = vector_get(matrix->vector_rows, i);
        while (c)
        {
            for (int j = prev_col; j < c->column; j++)
                printf("0.00 ");
            printf("%.2f ", c->value);
            prev_col = c->column + 1;
            c = c->next_column;
        }
        for (int j = prev_col; j < matrix->cols; j++)
        {
            printf("0.00 ");
        }
        printf("\n");
    }
}
void sparse_matrix_set(SparseMatrix *matrix, int row, int col, cell_type value)
{
    if (row >= matrix->rows || col >= matrix->cols || row < 0 || col < 0)
    {
        // coordenadas invalidas
        return;
    }
    Cell *cell = vector_get(matrix->vector_rows, row);
    while (cell != NULL && cell->column < col)
    {
        cell = cell->next_column;
    }
    if (cell != NULL && cell->column == col)
    {
        cell->value = value;
    }
    else
    {
        Cell *new_cell = cell_construct(row, col, value);
        if (cell == NULL)
        {
            vector_insert(matrix->vector_rows, row, new_cell);
        }
        else
        {
            new_cell->next_column = cell->next_column;
            cell->next_column = new_cell;
        }

        cell = vector_get(matrix->vector_cols, col);

        while (cell != NULL && cell->line < row)
        {
            cell = cell->next_line;
        }
        if (cell != NULL && cell->line == row)
        {
            cell->value = value;
        }
        else
        {
            if (cell == NULL)
            {
                vector_insert(matrix->vector_cols, col, new_cell);
            }
            else
            {
                new_cell->next_line = cell->next_line;
                cell->next_line = new_cell;
            }
        }
        matrix->size++;
    }
}

void sparse_matrix_destroy(SparseMatrix *m)
{
    for (int i = 0; i < vector_size(m->vector_rows); i++)
    {
        Cell *c = vector_get(m->vector_rows, i);
        while (c)
        {
            Cell *aux = c->next_line;
            cell_destroy(c);
            c = aux;
        }
    }
    vector_destroy(m->vector_rows);
    vector_destroy(m->vector_cols);
    free(m);
}