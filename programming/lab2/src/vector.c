#include "vector.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vector_init(vector *v) {
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

size_t vector_get_size(vector *v) { return v->size; }

size_t vector_get_capacity(vector *v) { return v->capacity; }

int vector_push_back(vector *v, void *e) {
    if (v->capacity == 0) {
        v->capacity = 2;
        v->data = malloc(sizeof(void *) * v->capacity);
        if (v->data == NULL) {
            return -1;
        }
        memset(v->data, '\0', sizeof(void *) * v->capacity);
    }

    if (v->capacity == v->size) {
        v->capacity *= 2;
        v->data = realloc(v->data, sizeof(void *) * v->capacity);
    }

    v->data[v->size] = e;
    v->size++;
    return 0;
}

void vector_pop_back(vector *v) {}

void vector_shrink_to_fit(vector *v) {
    if (v->capacity != v->size) {
        v->capacity = v->size;
        v->data = realloc(v->data, sizeof(void *) * v->capacity);
    }
}

int vector_resize(vector *v, size_t new_size) {
    if (v->size < new_size) {
        for (size_t i = v->size + 1; i = < new_size; ++i) {
            vector_push_back(v, 0);
        }
    }
}

int vector_reserve(vector *v, size_t new_capacity) {
    if (v->capacity < new_capacity) {
        v->capacity = new_capacity;
        v->data = realloc(v->data, sizeof(void *) * v->capacity);
    }
}

void vector_set_item(vector *v, size_t index, void *e) {
    if (index >= v->size) {
        return;
    }

    v->data[index] = e;
}

void *vector_get_item(vector *v, size_t index) {
    if (index >= v->size) {
        return NULL;
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

void vector_free(vector *v) { free(v->data); }