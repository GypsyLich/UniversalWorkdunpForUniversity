#pragma once
int KRcounter;
int Addcounter;
typedef struct listnode {
    char *key;
    int value;
    struct listnode *next;
} listnode;
unsigned int KRHash(char *s);
unsigned int AddHash(char *s);
void hashtab_init(struct listnode **hashtab, int hashtabSize);
void hashtab_add(struct listnode **hashtab, char *key, int value, int hshtype);
struct listnode *hashtab_lookup(struct listnode **hashtab, char *key,
                                int hshtype);
void hashtab_delete(struct listnode **hashtab, char *key, int hshtype);