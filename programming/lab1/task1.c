#include <stdio.h>
#include <stdlib.h>

void init(int **arr, int n) {
    *arr = malloc(sizeof(int) * n);
    int i;
    for (i = 0; i < n; ++i) {
        (*arr)[i] = i;
    }
}

int main() {
    int *arr = NULL;
    int n = 10;
    init(&arr, n);
    int i;
    for (i = 0; i < n; ++i)
        printf("%d\n", arr[i]);
    free(arr);
    return 0;
}
