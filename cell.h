#ifndef _CELL_H
#define _CELL_H
typedef float cell_type;
typedef struct cell {
  int row;
  int column;
  cell_type value;
  struct cell *next_row;
  struct cell *next_column;
} Cell;

Cell *cell_construct(int row, int column, cell_type value, Cell *next_row,
                     Cell *next_column);
void cell_insert(Cell *cell, Cell *prev_row, Cell *prev_column, Cell *next_row,
                 Cell *next_column);
void cell_insert_column(Cell *cell, Cell *prev, Cell *next);
void cell_insert_row(Cell *cell, Cell *prev, Cell *next);
void cell_print(Cell *cell);
void cell_destroy(Cell *cell);

#endif