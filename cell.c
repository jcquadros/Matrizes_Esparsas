#include <stdio.h>
#include <stdlib.h>
#include "cell.h"

Cell *cell_construct(int line, int column, cell_type value)
{
    Cell *cell = (Cell*)calloc(1, sizeof(Cell));
    cell->line = line;
    cell->column = column;
    cell->value = value;
    cell->next_column = NULL;
    cell->next_line = NULL;
    return cell;
}

void cell_print(Cell *cell)
{
    printf("(%d, %d) = %.2f\n", cell->line, cell->column, cell->value);
}

void cell_set_next(Cell *c, Cell *next_line, Cell *next_column)
{
    c->next_line = next_line;
    c->next_column = next_column;
}

int cell_its_eq_line(Cell *c1, Cell *c2)
{
    if (c1->line < c2->line)
        return 1;
    else if (c1->line > c2->line)
        return -1;
    else
        return 0;
}

int cell_its_eq_column(Cell *c1, Cell *c2)
{
    if (c1->column < c2->column)
        return 1;
    else if (c1->column > c2->column)
        return -1;
    else
        return 0;
}

void cell_destroy(Cell *cell)
{
    free(cell);
}
