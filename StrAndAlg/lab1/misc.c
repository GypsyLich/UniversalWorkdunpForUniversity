#include "misc.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void swap(int *arr, int a, int b) {
  int tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
}

int getrand(int min, int max) {
  return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

double wtime() {
  struct timeval t;
  gettimeofday(&t, NULL);
  return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

void countSort(int arr[], int size, int divider) {
  int counter[10] = {0};
  int sorted[size];
  int i;
  for (i = 0; i < size; ++i) {
    ++counter[(arr[i] / divider) % 10];
  }

  for (i = 1; i <= 9; ++i) {
    counter[i] += counter[i - 1];
  }

  for (i = size - 1; i >= 0; --i) {
    sorted[counter[(arr[i] / divider) % 10] - 1] = arr[i];
    --counter[(arr[i] / divider) % 10];
  }

  for (i = 0; i < size; ++i) {
    arr[i] = sorted[i];
  }
}