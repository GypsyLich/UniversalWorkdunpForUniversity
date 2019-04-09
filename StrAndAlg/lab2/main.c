#include "main.h"
#include "bstree.h"
#include "hashtab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

int getrand(int min, int max) {
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}
double wtime() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

void shuffle() {
    size_t i;
    for (i = 0; i < ROWS - 1; i++) {
        size_t j = i + getrand(i, ROWS - 1);
        char t[COLS];
        strcpy(t, words[j]);
        strcpy(words[j], words[i]);
        strcpy(words[i], t);
    }
}
int main(int argc, char const *argv[]) {

    srand(time(NULL));
    FILE *fp;
    fp = fopen("text2.txt", "r");
    int i;
    for (i = 0; i <= ROWS; ++i) {
        fscanf(fp, "%s ", words[i]);
    }

    shuffle();

    struct bstree *tree = bstree_create(words[0], 0);
    struct listnode *hashtab[HASHTAB_SIZE];
    double addTimer = 0, lookupTimer = 0, lookupTemp = 0, addTemp = 0;
    hashtab_init(hashtab);

    FILE *bstreeLookup = fopen("bstreeLookup.dat", "w");
    FILE *hashtabLookup = fopen("hashtabLookup.dat", "w");
    FILE *bstreeAdd = fopen("bstreeAdd.dat", "w");
    FILE *hashtabAdd = fopen("hashtabAdd.dat", "w");

    addTimer = wtime();
    for (i = 1; i <= ROWS; ++i) {
        bstree_add(tree, words[i], i);
        if (i % 300 == 0) {
            char *searchKey = words[getrand(0, i)];
            lookupTimer = wtime();
            struct bstree *treeNode = bstree_lookup(tree, searchKey);
            lookupTemp += wtime() - lookupTimer;
            addTemp += wtime() - addTimer;
        }
        if (i % 6000 == 0) {
            fprintf(bstreeAdd, "%d %f\n", i, addTemp * 50);
            fprintf(bstreeLookup, "%d %f\n", i, lookupTemp * 50);
            addTemp = 0;
            lookupTemp = 0;
            //берем среднее значение между 20 замерами и
            //переводим в милисекунды
        }
    }
    lookupTemp = 0;
    addTemp = 0;
    addTimer = wtime();
    for (i = 1; i <= ROWS; ++i) {
        hashtab_add(hashtab, words[i], i);
        if (i % 300 == 0) {
            char *searchKey = words[getrand(0, i)];
            lookupTimer = wtime();
            struct listnode *hashNode = hashtab_lookup(hashtab, searchKey);
            lookupTemp += wtime() - lookupTimer;
            addTemp += wtime() - addTimer;
        }
        if (i % 6000 == 0) {
            fprintf(hashtabAdd, "%d %f\n", i, addTemp * 50);
            fprintf(hashtabLookup, "%d %f\n", i, lookupTemp * 50);
            addTemp = 0;
            lookupTemp = 0;
        }
    }
    /*for (i = 1; i < ROWS; ++i) {
        bstree_add(tree, words[i], i);
        hashtab_add(hashtab, words[i], i);
        if (i % 6000 == 0) {
            char *searchKey = words[getrand(0, i)];
            printf("%s\n", searchKey);
            t = wtime();
            struct bstree *treeNode = bstree_lookup(tree, searchKey);
            t = wtime() - t;
            t *= 1000;
            printf("%.10f\n", t);
            fprintf(bstreeLookup, "%d %f\n", i, t);

            t = wtime();
            struct listnode *hashNode = hashtab_lookup(hashtab, searchKey);
            t = wtime() - t;
            t *= 1000;
            printf("%.8f\n\n", t);
            fprintf(hashtabLookup, "%d %f\n", i, t);*/
    /*        }*/
    /*    }*/

    return 0;
}