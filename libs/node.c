
#include <stdlib.h>
#include <stdio.h>
#include "node.h"

Node *node_construct(data_type value, int line, int col, Node *next_line, Node *next_col)
{
    Node *n = (Node *)calloc(1,sizeof(Node));
    n->value = value;
    n->next_line = next_line;
    n->next_col = next_col;
    n->col = col;
    n->line = line;
    //node_print(n);
    return n;
}

void node_set_next_line(Node * n, Node * next_line){
  n->next_line = next_line;
}

void node_print(Node *n){
  printf("(%d,%d) = %.2f\n", n->line, n->col, n->value);
}

void node_set_next_col(Node * n, Node * next_col){
  n->next_col = next_col;
}

void node_destroy(Node *n)
{
    free(n);
}