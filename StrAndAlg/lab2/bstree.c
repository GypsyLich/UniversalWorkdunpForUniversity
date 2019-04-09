#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bstree *bstree_create(char *key, int value) {
    struct bstree *node;

    node = malloc(sizeof(*node));
    if (node != NULL) {
        node->key = key;
        node->value = value;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

void bstree_add(struct bstree *tree, char *key, int value) {
    if (tree == NULL)
        return;
    struct bstree *parent, *CurrentTree, *node;
    CurrentTree = tree;
    while (CurrentTree != NULL) {
        parent = CurrentTree;
        if (strcmp(key, CurrentTree->key) < 0)
            CurrentTree = CurrentTree->left;
        else if (strcmp(key, CurrentTree->key) > 0)
            CurrentTree = CurrentTree->right;
        else
            return;
    }
    node = bstree_create(key, value);
    if (strcmp(key, parent->key) < 0)
        parent->left = node;
    else
        parent->right = node;
}
struct bstree *bstree_lookup(struct bstree *tree, char *key) {
    struct bstree *CurrentTree;
    CurrentTree = tree;
    while (CurrentTree != NULL) {
        if (strcmp(key, CurrentTree->key) == 0) {
            return CurrentTree;
        } else if (strcmp(key, CurrentTree->key) < 0) {
            CurrentTree = CurrentTree->left;
        } else {
            CurrentTree = CurrentTree->right;
        }
    }
    return CurrentTree;
}

struct bstree *bstree_min(struct bstree *tree) {
    if (tree == NULL)
        return NULL;
    struct bstree *CurrentTree;
    CurrentTree = tree;

    while (CurrentTree->left != NULL)
        CurrentTree = CurrentTree->left;
    return CurrentTree;
}

struct bstree *bstree_max(struct bstree *tree) {
    if (tree == NULL)
        return NULL;
    struct bstree *CurrentTree;
    CurrentTree = tree;

    while (CurrentTree->right != NULL)
        CurrentTree = CurrentTree->right;
    return CurrentTree;
}

struct bstree *bstree_delete(struct bstree *tree, char *key) {

    struct bstree *CurrentTree;
    CurrentTree = bstree_lookup(tree, key);

    if (CurrentTree == NULL)
        return CurrentTree;

    if (CurrentTree->left == NULL) {
        CurrentTree = CurrentTree->right;
        free(CurrentTree->right);
        return CurrentTree;
    } else if (CurrentTree->right == NULL) {
        CurrentTree = CurrentTree->left;
        free(CurrentTree->left);
        return CurrentTree;
    }

    struct bstree *temp = bstree_min(CurrentTree->right);

    CurrentTree->key = temp->key;

    bstree_delete(tree->right, temp->key);
    return tree;
}