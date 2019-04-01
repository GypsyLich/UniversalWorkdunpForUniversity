#include "iterative.h"
#include "recursive.h"
#include <stdio.h>
#define ARRAY_MAX 10

void intToStr(char *string, int n) {
    int j = 0;
    int i = 0;
    int array[11];
    if (n < 0) {
        string[0] = '-';
        n *= -1;
        ++j;
    }
    while (n > 0) {
        array[i++] = n % 10;
        n = n / 10;
    }
    i--;
    while (i >= 0) {
        string[j++] = (char)(48 + array[i--]);
    }
}
int main(int argc, char const *argv[]) {
    int array[ARRAY_MAX];
    char string[12] = {'\0'};
    for (int i = 0; i < ARRAY_MAX; ++i) {
        array[i] = i;
    }

    printf("febo_iterative of 6: %d\n", febo_iterative(6));
    printf("febo_recursive of 6: %d\n", febo_recursive(6));
    printf("iterative array sum of 0..9: %d\n",
           sum_array_iterative(array, ARRAY_MAX));
    printf("recursive array sum of 0..9: %d\n",
           sum_array_recursive(array, ARRAY_MAX));

    intToStr(string, -123456789);
    printf("%s\n", string);

    return 0;
}