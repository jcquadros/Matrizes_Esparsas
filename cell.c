#include "cell.h"
#include <stdio.h>
#include <stdlib.h>

Cell *cell_construct(int row, int column, cell_type value, Cell *next_row,
                     Cell *next_column) {
  Cell *cell = (Cell *)calloc(1, sizeof(Cell));
  cell->row = row;
  cell->column = column;
  cell->value = value;
  cell->next_column = next_column;
  cell->next_row = next_row;
  cell_print(cell);
  return cell;
}

void cell_print(Cell *cell) {
  printf("(%d, %d) = %.2f\n", cell->row, cell->column, cell->value);
}

void cell_insert(Cell *cell, Cell *prev_row, Cell *prev_column, Cell *next_row,
                 Cell *next_column) {
  cell_insert_row(cell, prev_row, next_row);
  cell_insert_column(cell, prev_column, next_column);
}

void cell_insert_column(Cell *cell, Cell *prev, Cell *next) {
  if (prev) {
    prev->next_column = cell;
  }
  cell->next_column = next;
}

void cell_insert_row(Cell *cell, Cell *prev, Cell *next) {
  if (prev) {
    prev->next_row = cell;
  }
  cell->next_row = next;
}

void cell_destroy(Cell *cell) { free(cell); }
