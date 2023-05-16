
#ifndef _FORWARD_forward_list_H_
#define _FORWARD_forward_list_H_

#include "node.h"

typedef struct
{
    Node *head;
    int size;
} ForwardList;


ForwardList *forward_list_construct();

int forward_list_size(ForwardList *l);

void forward_list_push_front_h(ForwardList *l, data_type data, int line, int col);
void forward_list_push_front_v(ForwardList *l, data_type data, int line, int col);
void forward_list_set_front_v(ForwardList *l, Node *n);
void forward_list_set_front_h(ForwardList *l, Node *n);
void forward_list_insert_between_v(ForwardList *l, Node * node, Node * prev, Node * next);
void forward_list_insert_between_h(ForwardList *l, Node * node, Node * prev, Node * next);
void forward_list_print_h(ForwardList *l, void (*print_fn)(data_type));
void forward_list_print_v(ForwardList *l, void (*print_fn)(data_type));
void forward_list_remove_v(ForwardList *l, Node *prev, Node *node);
void forward_list_remove_h(ForwardList *l, Node *prev, Node *node);


data_type forward_list_get_h(ForwardList *l, int i);
data_type forward_list_get_v(ForwardList *l, int i);

data_type forward_list_pop_front_h(ForwardList *l);
data_type forward_list_pop_front_v(ForwardList *l);


void forward_list_destroy_h(ForwardList *l);

#endif