#include "forward_list.h"
#include <stdio.h>
#include <stdlib.h>

ForwardList *forward_list_construct() {
  ForwardList *ll = (ForwardList *)calloc(1, sizeof(ForwardList));
  return ll;
}

int forward_list_size(ForwardList *l) { return l->size; }

void forward_list_push_front_h(ForwardList *l, data_type data, int line,
                               int col) {
  Node *n = node_construct(data, line, col, NULL, l->head);
  l->head = n;
  l->size++;
}

void forward_list_push_front_v(ForwardList *l, data_type data, int line,
                               int col) {
  Node *n = node_construct(data, line, col, l->head, NULL);
  l->head = n;
  l->size++;
}

void forward_list_set_front_v(ForwardList *l, Node *n) {
  n->next_line = l->head;
  l->head = n;
}

void forward_list_set_front_h(ForwardList *l, Node *n) {
  n->next_col = l->head;
  l->head = n;
}

void forward_list_print_h(ForwardList *l, void (*print_fn)(data_type)) {
  Node *n = l->head;
  printf("[");
  while (n != NULL) {
    print_fn(n->value);
    n = n->next_col;
    if (n != NULL)
      printf(", ");
  }
  printf("]");
}

void forward_list_print_v(ForwardList *l, void (*print_fn)(data_type)) {
  Node *n = l->head;
  printf("[");
  while (n != NULL) {
    print_fn(n->value);
    n = n->next_line;
    if (n != NULL)
      printf(", ");
  }
  printf("]");
}

void forward_list_insert_between_h(ForwardList *l, Node *node, Node *prev,
                                   Node *next) {
  if (!prev) {
    node->next_col = l->head;
    l->head = node;
  } else {
    node->next_col = next;
    prev->next_col = node;
  }
}

void forward_list_insert_between_v(ForwardList *l, Node *node, Node *prev,
                                   Node *next) {
  if (!prev) {
    node->next_line = l->head;
    l->head = node;
  } else {
    node->next_line = next;
    prev->next_line = node;
  }
}

void forward_list_remove_v(ForwardList *l, Node *prev, Node *node) {
  if (!prev) {
    l->head = node->next_line;
  } else {
    prev->next_line = node->next_line;
  }
}

void forward_list_remove_h(ForwardList *l, Node *prev, Node *node) {
  if (!prev) {
    l->head = node->next_col;
  } else {
    prev->next_col = node->next_col;
  }
}

data_type forward_list_get_h(ForwardList *l, int i) {
  Node *n = l->head;
  int k = 0;

  if (i < 0 || i >= l->size) {
    printf("Error: %d is not a avaliable position\n", i);
    exit(EXIT_FAILURE);
  }

  while (n != NULL) {
    if (i == k) {
      break;
    }
    n = n->next_col;
    k++;
  }
  return n->value;
}

data_type forward_list_get_v(ForwardList *l, int i) {
  Node *n = l->head;
  int k = 0;

  if (i < 0 || i >= l->size) {
    printf("Error: %d is not a avaliable position\n", i);
    exit(EXIT_FAILURE);
  }

  while (n != NULL) {
    if (i == k) {
      break;
    }
    n = n->next_line;
    k++;
  }
  return n->value;
}

data_type forward_list_pop_front_h(ForwardList *l) {
  if (l->head == NULL) {
    printf("Error: A lista está vazia!\n");
    exit(EXIT_FAILURE);
  }

  Node *n = l->head;
  l->head = n->next_col;
  data_type value = n->value;
  l->size--;
  node_destroy(n);
  return value;
}

data_type forward_list_pop_front_v(ForwardList *l) {
  if (l->head == NULL) {
    printf("Error: A lista está vazia!\n");
    exit(EXIT_FAILURE);
  }

  Node *n = l->head;
  l->head = n->next_line;
  data_type value = n->value;
  l->size--;
  node_destroy(n);
  return value;
}

void forward_list_destroy_h(ForwardList *l) {
  Node *n = l->head;
  while (n != NULL) {
    Node *next = n->next_col;
    //node_print(n); // asdasd
    node_destroy(n);
    n = next;
  }

  // free(l);
}
