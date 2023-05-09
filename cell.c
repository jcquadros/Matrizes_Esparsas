#include <stdio.h>
#include <stdlib.h>
#include "cell.h"

Cell *cell_construct(int line, int column, data_type value){
    Cell *cell = malloc(sizeof(Cell));
    cell->line = line;
    cell->column = column;
    cell->value = value;
    return cell;
}

void cell_print(Cell *cell){
    printf("(%d, %d) = %d\n", cell->line, cell->column, cell->value);
}

void cell_destroy(Cell *cell){
    free(cell);
}
