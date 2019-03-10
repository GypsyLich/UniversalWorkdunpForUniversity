
#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stddef.h>
typedef struct vector_ {
    int *data;
    size_t size;
    size_t capacity;
} vector;

vector *vector_init(size_t initial_capacity);
vector *vector_copy(const vector *v);
size_t vector_get_size(vector *);
size_t vector_get_capacity(vector *v);
void vector_shrink_to_fit(vector *v);
int vector_resize(vector *v, size_t new_size);
int vector_reserve(vector *v, size_t new_capacity);
int vector_push_back(vector *, int);
void vector_set_item(vector *, size_t, int);
int vector_get_item(vector *, size_t);
void vector_delete(vector *, size_t);
void vector_free(vector *);

#endif