#ifndef _CELL_H
#define _CELL_H
typedef  float cell_type;

typedef struct cell{
    int line;
    int column;
    cell_type value;
    struct cell *next_line;
    struct cell *next_column;
}Cell;


Cell *cell_construct(int line, int column, cell_type value);
void cell_print(Cell *cell);
void cell_destroy(Cell *cell);


void cell_set_next(Cell *c, Cell *next_line, Cell *next_column);
int cell_its_eq_line(Cell *c1, Cell *c2);
int cell_its_eq_column(Cell *c1, Cell *c2);
#endif