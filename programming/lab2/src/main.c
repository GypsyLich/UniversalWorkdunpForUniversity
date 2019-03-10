#include "vector.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    vector *v = vector_init(5);
    for (size_t i = 0; i < 8; ++i) {
        vector_push_back(v, (int)i);
        printf("data[%ld]: %d, capacity: %ld, size: %ld\n", i,
               vector_get_item(v, i), vector_get_capacity(v),
               vector_get_size(v));
    }
    vector_delete(v, 2);
    vector_set_item(v, 3, 20);
    vector_reserve(v, 15);
    printf("capacity after vector_reserve: %ld\n", vector_get_capacity(v));
    vector_shrink_to_fit(v);
    printf("capacity after vector_shrink_to_fit: %ld\n",
           vector_get_capacity(v));
    vector_resize(v, 10);
    printf("capacity after vector_resize: %ld\n", vector_get_capacity(v));

    vector *vCopied = vector_copy(v);
    printf("copied vector:\n");
    for (size_t i = 0; i < 10; ++i) {
        printf("data[%ld]: %d, capacity: %ld, size: %ld\n", i,
               vector_get_item(vCopied, i), vector_get_capacity(vCopied),
               vector_get_size(vCopied));
    }
    vector_free(v);
    return 0;
}