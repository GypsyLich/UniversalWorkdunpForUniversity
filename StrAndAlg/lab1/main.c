#include "MergeSort.h"
#include "OddEvenSort.h"
#include "RadixSort.h"
#include "misc.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 300000

void renewer(int *arr, int *newArr) {
    for (int i = 0; i < N; ++i) {
        newArr[i] = arr[i];
    }
}

int main() {
    srand(time(NULL));
    int arr[N];
    int arrToSort[N];
    for (int i = 0; i < N; ++i) {
        arr[i] = getrand(0, 1000000);
    }
    int size = (sizeof(arr) / sizeof(arr[0])) / 12;
    FILE *fp;
    double start, end;
    fp = fopen("rad.dat", "w+");
    for (int i = 1; i <= 11; ++i) {
        int sizet = i * size + size;
        start = wtime();
        renewer(arr, arrToSort);
        radixSort(arrToSort, sizet);
        end = wtime();
        printf("rad: %d %f\n", sizet, (end - start));
        fprintf(fp, "%d %f\n", sizet, (end - start));
    }
    fclose(fp);
    fp = fopen("oddEven.dat", "w+");
    for (int i = 1; i <= 11; ++i) {
        int sizet = i * size + size;
        start = wtime();
        renewer(arr, arrToSort);
        oddEvenSort(arrToSort, sizet);
        end = wtime();
        printf("oddEven: %d %f\n", sizet, (end - start));
        fprintf(fp, "%d %f\n", sizet, (end - start));
    }
    fclose(fp);
    fp = fopen("merge.dat", "w+");
    for (int i = 1; i <= 11; ++i) {
        int sizet = i * size + size;
        start = wtime();
        renewer(arr, arrToSort);
        mergeSort(arr, 0, sizet);
        end = wtime();
        printf("merge: %d %f\n", sizet, (end - start));
        fprintf(fp, "%d %f\n", sizet, (end - start));
    }
    fclose(fp);

    return 0;
}
