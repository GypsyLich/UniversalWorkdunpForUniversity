#include "RadixSort.h"
#include "misc.h"
#include <stdio.h>

void radixSort(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    for (int divider = 1; max / divider > 0; divider = divider * 10) {
        countSort(arr, size, divider);
    }
}