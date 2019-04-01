#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define N 100
#define MAX 100

void countSort(int arr[], int size, int maxNum) {
	int counter[maxNum + 1];
	int sorted[size];

	for (int i = 0; i < maxNum + 1; ++i){
		counter[i] = 0;
	}
	
	for (int i = 0; i < size; ++i) {
		++counter[arr[i]];
	}

	for (int i = 1; i <= maxNum; ++i) {
		counter[i] += counter[i - 1];
	}

	for (int i = size - 1; i >= 0; --i) {
		sorted[counter[arr[i]] - 1] = arr[i];
		--counter[arr[i]];
	}

	for (int i = 0; i < size; ++i) {
		arr[i] = sorted[i];
	}
}

double wtime() {
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand(int min, int max) {
	return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

int main() {
	srand(wtime());
	int arr[N];
	for (int i = 0; i < N; ++i)
	{
		arr[i] = getrand(0, MAX - 1);
		printf("%4d ", arr[i]);
	}

	countSort(arr, N, MAX);
	printf("\nsorted\n");

	for (int i = 0; i < N; ++i) 
	{
		printf("%4d ", arr[i]);
	}

	printf("\n");

	return 0;
}