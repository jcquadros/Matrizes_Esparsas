
#ifndef _NODE_H_
#define _NODE_H_

typedef float data_type;

typedef struct Node
{
    int line;
    int col;
    data_type value;
    struct Node *next_line;
    struct Node *next_col;
} Node;

Node *node_construct(data_type value, int line, int col, Node *next_line, Node *next_col);
void node_set_next_line(Node * n, Node * next_line);
void node_set_next_col(Node * n, Node * next_col);
void node_destroy(Node *n);
void node_print(Node *n);

#endif