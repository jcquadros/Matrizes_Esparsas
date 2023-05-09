#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int VECTOR_CAPACITY = 10;
static int VECTOR_GROWTH_RATE = 2;

Vector *vector_construct() {
  Vector *v = (Vector *)calloc(1, sizeof(Vector));
  v->data = (vector_type*)calloc(VECTOR_CAPACITY, sizeof(vector_type));
  v->allocated = VECTOR_CAPACITY;
  return v;
}

void vector_push_back(Vector *v, vector_type val) {
  if (v->size == v->allocated) {
    v->allocated *= VECTOR_GROWTH_RATE;
    v->data = (vector_type *)realloc(v->data, v->allocated * sizeof(vector_type));
  }
  v->data[v->size] = val;
  v->size++;
}

vector_type vector_get(Vector *v, int i) {
  if (i >= v->size || i < 0) {
    printf("Erro: acesso indevido na posicao %d do vetor de tamanho %d\n", i,
           v->size);
    exit(1);
  }
  return v->data[i];
}

void vector_set(Vector *v, int i, vector_type val) {
  if (i >= v->size || i < 0) {
    printf("Erro: falha ao tentar setar um valor na posicao %d do vetor de "
           "tamanho %d\n",
           i, v->size);
    exit(1);
  }
  v->data[i] = val;
}

int vector_size(Vector *v) { return v->size; }

int vector_find(Vector *v, vector_type val) {
  for (int i = 0; i < v->size; i++) {
    if (v->data[i] == val) {
      return i;
    }
  }
  return -1;
}

vector_type vector_remove(Vector *v, int i) {
  if (i >= v->size || i < 0) {
    printf("Erro: falha ao tentar remover um valor na posicao %d do vetor "
           "de tamanho %d\n",
           i, v->size);
    exit(1);
  }
  vector_type aux = v->data[i];
  for (int j = i; j < v->size - 1; j++) {
    v->data[j] = v->data[j + 1];
  }
  v->size--;
  return aux;
}
vector_type vector_pop_front(Vector *v) { return vector_remove(v, 0); }

vector_type vector_pop_back(Vector *v) { return vector_remove(v, v->size - 1); }

void vector_insert(Vector *v, int i, vector_type val) {
  if (i >= v->size || i < 0) {
    printf("Erro: falha ao tentar inserir um valor na posicao %d do vetor "
           "de tamanho %d\n",
           i, v->size);
    exit(1);
  }
  if (v->size == v->allocated) {
    v->allocated *= VECTOR_GROWTH_RATE;
    v->data = realloc(v->data, v->allocated * sizeof(vector_type));
  }
  for (int j = v->size; j > i; j--) {
    v->data[j] = v->data[j - 1];
  }
  v->data[i] = val;
  v->size++;
}

void vector_swap(Vector *v, int i, int j) {
  if (i < 0 || i >= v->size || j < 0 || j >= v->size) {
    printf("Error: indices invalidos %d e %d para o vetor de tamanho %d.\n", i,
           j, v->size);
    exit(1);
  }

  vector_type aux = v->data[i];
  v->data[i] = v->data[j];
  v->data[j] = aux;
}

void vector_sort(Vector *v) { // bubble sort
  for (int i = 0; i < v->size - 1; i++) {
    int n_trocas = 0;
    for (int j = 0; j < v->size - i - 1; j++) {
      if (v->data[j] > v->data[j + 1]) {
        vector_swap(v, j, j + 1);
        n_trocas++;
      }
    }
    if (n_trocas == 0) {
      break;
    }
  }
}

int vector_binary_search(Vector *v, vector_type val) {
  int low = 0;
  int high = v->size - 1;
  int mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (v->data[mid] == val) {
      return mid;
    }
    if (v->data[mid] < val) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

void vector_reverse(Vector *v) {
  for (int i = 0; i < v->size / 2; i++) {
    vector_swap(v, i, v->size - i - 1);
  }
}

Vector *vector_copy(Vector *v) {
  Vector *copy = (Vector *)malloc(sizeof(Vector));

  copy->data = (vector_type *)malloc(v->allocated * sizeof(vector_type));
  copy->size = v->size;
  copy->allocated = v->allocated;

  memcpy(copy->data, v->data, v->size * sizeof(vector_type));
  return copy;
}

void vector_clear(Vector *v) { v->size = 0; }

void vector_destroy(Vector *v) {
  free(v->data);
  free(v);
}
