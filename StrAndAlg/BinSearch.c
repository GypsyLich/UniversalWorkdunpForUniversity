#include <stdio.h>
#define N 100

int comparatorFunction (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

void binSearch(int *arr, int left, int right, int searchedNumber)
{
	int m = left + (right - left)/2;
	int sc = searchedNumber > arr[m] ? 2 : searchedNumber < arr[m] ? 1 : 0;
	sc = (right == left) && (sc != 0) ? -1 : sc;
	switch(sc){
		case 2:
			binSearch(arr, (m + 1), right, searchedNumber);
		break;
		case 1:
			binSearch(arr, left, m, searchedNumber);
		break;
		case 0:
		printf("\nindex: %d\n", m); 
		break;
		case -1:
		printf("\nthere is no searched number\n");
		break;
	}

}

double wtime()
{
struct timeval t;
gettimeofday(&t, NULL);
return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand(int min, int max)
{
return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

int main()
{
	srand(wtime());
	int arr[N];
	int searchedNumber = getrand(0, 100);
	printf("searchedNumber: %d\n", searchedNumber);
	for (int i = 0; i < N; ++i)
	{
		arr[i] = getrand(0, 100);
	}

	qsort(arr, N, sizeof(int), comparatorFunction);

	for (int i = 0; i < N; ++i)
	{
		printf("%d ", arr[i]);
	}

	int l = 0;
	int r = N;

	binSearch(arr, l, r, searchedNumber);

	return 0;
}