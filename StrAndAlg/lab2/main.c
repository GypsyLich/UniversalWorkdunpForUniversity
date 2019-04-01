#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 80000
#define COLS 30

int main(int argc, char const *argv[]) {
    FILE *fp;
    fp = fopen("text2.txt", "r");
    char words[ROWS][COLS];
    int i;
    for (i = 0; i < ROWS; ++i) {
        fscanf(fp, "%s ", words[i]);
    }

    return 0;
}