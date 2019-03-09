#include "vector.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

vector *vector_init(size_t initial_capacity) {
    vector *v = malloc(sizeof(*v));
    if (v != NULL) {
        if (initial_capacity > 0) {
            v->data = malloc(sizeof(int) * initial_capacity);
            memset(v->data, '\0', sizeof(int) * initial_capacity);
            v->size = 0;
            v->capacity = initial_capacity;
        }
    }
    return v;
}

vector *vector_copy(const vector *v) {
    vector *vCopy = vector_init(v->capacity);
    memcpy(vCopy, v, v->size);
    vCopy->size = v->size;
    return vCopy;
}

size_t vector_get_size(vector *v) { return v->size; }

size_t vector_get_capacity(vector *v) { return v->capacity; }

int vector_push_back(vector *v, int e) {
    if (v->capacity == 0) {
        v->capacity = 2;
        v->data = malloc(sizeof(void *) * v->capacity);
        if (v->data == NULL) {
            return -1;
        }
        memset(v->data, '\0', sizeof(int) * v->capacity);
    }

    if (v->capacity == v->size) {
        v->capacity *= 2;
        v->data = realloc(v->data, sizeof(int) * v->capacity);
    }

    v->data[v->size] = e;
    v->size++;
    return 0;
}

void vector_shrink_to_fit(vector *v) {
    if (v->capacity != v->size) {
        v->capacity = v->size;
        v->data = realloc(v->data, sizeof(int) * v->capacity);
    }
}

int vector_resize(vector *v, size_t new_size) {
    if (v->size < new_size) {
        v->capacity = new_size;
        memset(&v->data[v->size], 0, sizeof(int) * (v->capacity - 1));
        v->size = new_size;
        return 0;
        /*for (size_t i = v->size + 1; i = new_size; ++i) {
            vector_push_back(v, 0);
        }*/
    }
    return -1;
}

int vector_reserve(vector *v, size_t new_capacity) {
    if (v->capacity < new_capacity) {
        v->capacity = new_capacity;
        v->data = realloc(v->data, sizeof(int) * v->capacity);
        return 0;
    }
    return -1;
}

void vector_set_item(vector *v, size_t index, int e) {
    if (index >= v->size) {
        return;
    }

    v->data[index] = e;
}

int vector_get_item(vector *v, size_t index) {
    if (index >= v->size) {
        return -1;
    }

    return v->data[index];
}

void vector_delete(vector *v, size_t index) {
    if (index >= v->size) {
        return;
    }

    for (size_t i = index, j = index; i < v->size; i++) {
        v->data[j] = v->data[i];
        j++;
    }

    v->size--;
}

void vector_free(vector *v) {
    free(v->data);
    free(v);
}