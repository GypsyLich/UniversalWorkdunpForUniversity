#include "MergeSort.h"
#include "misc.h"
#include <stdio.h>

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int lSize = middle - left + 1;
    int rSize = right - middle;
    int L[lSize], R[rSize];

    for (i = 0; i < lSize; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < rSize; j++) {
        R[j] = arr[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < lSize && j < rSize) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < lSize) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < rSize) {
        arr[k] = R[j];
        j++;
        k++;
    }
}