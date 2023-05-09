#ifndef _CELL_H
#define _CELL_H
typedef  float data_type;

typedef struct{
    int line;
    int column;
    data_type value;
    struct cell *next_line;
    struct cell *next_column;
}Cell;


Cell *cell_construct(int line, int column, data_type value);
void cell_print(Cell *cell);
void cell_destroy(Cell *cell);

#endif