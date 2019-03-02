#include "OddEvenSort.h"
#include "misc.h"
#include <stdio.h>

void oddEvenSort(int arr[], int n) {
    int isSorted = 0;

    while (isSorted == 0) {
        isSorted = 1;

        for (int i = 1; i <= n - 2; i = i + 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr, i, (i + 1));
                isSorted = 0;
            }
        }

        for (int i = 0; i <= n - 2; i = i + 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr, i, (i + 1));
                isSorted = 0;
            }
        }
    }
}