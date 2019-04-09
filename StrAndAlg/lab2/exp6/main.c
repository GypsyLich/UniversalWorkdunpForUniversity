#include "hashtab.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#define ROWS 120000
#define COLS 30
#define KRHASHTAB_SIZE 131313
#define ADDHASHTAB_SIZE 120000

int getrand(int min, int max) {
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}
double wtime() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main(int argc, char const *argv[]) {

    srand(time(NULL));
    FILE *fp;
    fp = fopen("text2.txt", "r");
    char words[ROWS][COLS];
    int i;
    for (i = 0; i <= ROWS; ++i) {
        fscanf(fp, "%s ", words[i]);
    }

    struct listnode *addhashtab[ADDHASHTAB_SIZE];
    struct listnode *krhashtab[KRHASHTAB_SIZE];
    hashtab_init(addhashtab, ADDHASHTAB_SIZE);
    hashtab_init(krhashtab, KRHASHTAB_SIZE);

    KRcounter = 0;
    Addcounter = 0;
    FILE *KRhashtabLookup = fopen("KRhashtabLookup.dat", "w");
    FILE *AddhashtabLookup = fopen("AddhashtabLookup.dat", "w");

    for (i = 1; i <= ROWS; ++i) {
        hashtab_add(addhashtab, words[i], i, 0);
        if (i % 300 == 0) {
            char *searchKey = words[getrand(0, i)];
            struct listnode *addhashNode =
                hashtab_lookup(addhashtab, searchKey, 0);
        }
        if (i % 6000 == 0) {
            fprintf(AddhashtabLookup, "%d %d\n", i, Addcounter);
        }
    }

    for (i = 1; i <= ROWS; ++i) {
        hashtab_add(krhashtab, words[i], i, 1);
        if (i % 300 == 0) {
            char *searchKey = words[getrand(0, i)];
            struct listnode *KRhashNode =
                hashtab_lookup(krhashtab, searchKey, 1);
        }
        if (i % 6000 == 0) {
            fprintf(KRhashtabLookup, "%d %d\n", i, KRcounter);
        }
    }

    return 0;
}