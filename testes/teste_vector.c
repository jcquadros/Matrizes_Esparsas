#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main(){
    Vector *v = vector_construct();
    vector_push_back(v, 3);
    vector_push_back(v, 4);
    vector_push_back(v, 5);
    vector_push_back(v, 6);
    vector_push_back(v, 7);
    vector_push_back(v, 8);
    printf("normal: ");
    for( int i = 0; i < vector_size(v); i++){
        printf("%d ", vector_get(v, i));
    }
    printf("\n");

    vector_reverse(v);
    printf("reverso: ");
    for( int i = 0; i < vector_size(v); i++){
        printf("%d ", vector_get(v, i));
    }
    printf("\n");

    vector_pop_back(v);
    vector_pop_front(v);
    vector_remove(v,2);
    printf("depois de remover a posicao 0 2 e a ultima: ");
    for( int i = 0; i < vector_size(v); i++){
        printf("%d ", vector_get(v, i));
    }
    printf("\n");

    printf("posicao %d valor %d\n", vector_find(v,4), vector_get(v,vector_find(v,4)));

    vector_sort(v);
    printf("ordenado: ");
    for( int i = 0; i < vector_size(v); i++){
        printf("%d ", vector_get(v, i));
    }
    printf("\n");

    Vector *copy = vector_copy(v);
    printf("copia: ");
    for( int i = 0; i < vector_size(v); i++){
        printf("%d ", vector_get(copy, i));
    }
    vector_destroy(copy);
    vector_destroy(v);
    
}