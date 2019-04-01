#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bstree {
    char *key;
    int *value;

    struct bstree *left;
    struct bstree *right;
};

struct bstree *bstree_create(char *key, int *value) {
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

void bstree_add(struct bstree *tree, char *key, int *value) {
    if (tree == NULL)
        return;
    struct bstree *parent, *node;
    while (tree != NULL) {
        parent = tree;
        if (strcmp(key, tree->key) < 0)
            tree = tree->left;
        else if (strcmp(key, tree->key) > 0)
            tree = tree->right;
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
    while (tree != NULL) {
        if (strcmp(key, tree->key) == 0)
            return tree;
        else if (strcmp(key, tree->key) < 0)
            tree = tree->left;
        else
            tree = tree->right;
    }
    return tree;
}

struct bstree *bstree_min(struct bstree *tree) {
    if (tree == NULL)
        return NULL;

    while (tree->left != NULL)
        tree = tree->left;
    return tree;
}

struct bstree *bstree_max(struct bstree *tree) {
    if (tree == NULL)
        return NULL;

    while (tree->right != NULL)
        tree = tree->right;
    return tree;
}

struct bstree *bstree_delete(struct bstree *tree, char *key) {
    if (tree == NULL)
        return tree;

    if (strcmp(key, tree->key) < 0) {
        tree->left = bstree_delete(tree->left, key);
    } else if (key > tree->key) {
        tree->right = bstree_delete(tree->right, key);
    } else {
        if (tree->left == NULL) {
            struct bstree *temp = tree->right;
            free(tree);
            return temp;
        } else if (tree->right == NULL) {
            struct bstree *temp = tree->left;
            free(tree);
            return temp;
        }

        struct bstree *temp = bstree_min(tree->right);

        tree->key = temp->key;

        tree->right = bstree_delete(tree->right, temp->key);
    }
    return tree;
}