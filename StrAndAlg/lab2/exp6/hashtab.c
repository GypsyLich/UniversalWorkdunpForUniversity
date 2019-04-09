#include "hashtab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KRHASHTAB_SIZE 131313
#define ADDHASHTAB_SIZE 120000

unsigned int KRHash(char *s) {
    unsigned int h = 0, hash_mul = 31;
    while (*s)
        h = h * hash_mul + (unsigned int)*s++;
    return h % KRHASHTAB_SIZE;
}

unsigned int AddHash(char *s) {
    unsigned int h = 0;
    while (*s)
        h += (unsigned int)*s++;
    return h % ADDHASHTAB_SIZE;
}

void hashtab_init(struct listnode **hashtab, int hashtabSize) {
    int i;
    for (i = 0; i < hashtabSize; i++)
        hashtab[i] = NULL;
}

void hashtab_add(struct listnode **hashtab, char *key, int value, int hshtype) {
    struct listnode *node;
    int index;
    if (hshtype == 0) {
        index = AddHash(key);
    } else {
        index = KRHash(key);
    }
    node = malloc(sizeof(*node));
    if (node != NULL) {
        node->key = key;
        node->value = value;
        node->next = hashtab[index];
        hashtab[index] = node;
    }
}

struct listnode *hashtab_lookup(struct listnode **hashtab, char *key,
                                int hshtype) {
    struct listnode *node;
    int index;
    if (hshtype == 0) {
        index = AddHash(key);
    } else {
        index = KRHash(key);
    }
    for (node = hashtab[index]; node != NULL; node = node->next) {
        if (0 == strcmp(node->key, key)) {
            return node;
        }
        if (hshtype == 0) {
            Addcounter++;
        } else {
            KRcounter++;
        }
    }
    return NULL;
}

void hashtab_delete(struct listnode **hashtab, char *key, int hshtype) {
    struct listnode *node, *prev = NULL;
    int index;
    if (hshtype == 0) {
        index = AddHash(key);
    } else {
        index = KRHash(key);
    }
    for (node = hashtab[index]; node != NULL; node = node->next) {
        if (0 == strcmp(node->key, key)) {
            if (prev == NULL)
                hashtab[index] = node->next;
            else
                prev->next = node->next;
            free(node);
            return;
        }
        prev = node;
    }
}