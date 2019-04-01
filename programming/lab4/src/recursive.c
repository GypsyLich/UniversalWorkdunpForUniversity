#include <stdio.h>

int febo_recursive(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return febo_recursive(n - 1) + febo_recursive(n - 2);
    }
}
////////////////////////////////////////////////////////////////////
int sum_array_recursive(int *array, int arrSize) {
    if (arrSize == 0) {
        return 0;
    } else {
        return array[arrSize - 1] + sum_array_recursive(array, arrSize - 1);
    }
}