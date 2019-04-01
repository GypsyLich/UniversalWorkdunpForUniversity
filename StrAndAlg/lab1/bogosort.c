#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int correct(int *arr, int size) {
    while (--size > 0)
        if (arr[size - 1] > arr[size])
            return 0;
    return 1;
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void shuffle(int *arr, int size) {
    for (int i = 0; i < size; ++i){
        swap(&arr[i], &arr[(rand() % size)]); 
    }
}

void bogoSort(int *arr, int size) {
	srand(time(NULL));
	int j = 0;
    while (!correct(arr, size)){
		for (int i = 0; i < size; i++) {
			printf("%d ", arr[i]);
		}
		printf("			%d\n", j);
		++j;
        shuffle(arr, size);
    }
}

int getrand(int min, int max)
{
	return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	unsigned int size = 3;
	int *arr = (int *)malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++) {
	*(arr + i) = getrand(0, 100);
	}

	bogoSort(arr, size);
	return 0;
}