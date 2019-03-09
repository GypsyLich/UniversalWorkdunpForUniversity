#include "vector.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    vector *v = vector_init(5);
    size_t n = (size_t)(vector_get_capacity(v) + 3);
    for (size_t i = 0; i < n; ++i) {
        vector_push_back(v, (int)i);
        printf("%d\n", vector_get_item(v, i));
    }
    vector_free(v);
    return 0;
}