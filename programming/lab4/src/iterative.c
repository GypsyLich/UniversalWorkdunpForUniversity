#include <stdio.h>

int febo(int previous, int current, int counter, int targetNumber) {
    if (counter == targetNumber) {
        return current;
    }
    return febo(current, current + previous, counter + 1, targetNumber);
}

int febo_iterative(int n) { return febo(1, 1, 2, n); }

////////////////////////////////////////////////////////////////////
int sum_array(int *array, int arrSize, int container) {
    if (arrSize == 0) {
        return container;
    } else {
        return sum_array(array, arrSize - 1, container + array[arrSize - 1]);
    }
}

int sum_array_iterative(int *array, int arrSize) {
    return sum_array(array, arrSize, 0);
}