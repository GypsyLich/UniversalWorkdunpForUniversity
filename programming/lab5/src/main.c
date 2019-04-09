#include "string.h"
#include <stdio.h>
#define MAX_PATH 260

int input(char *delim, char *paths) {
    fputs("delim(':','+' or ' '):", stdout);
    fgets(&delim, 1, stdin);
    fputs("paths(max paths = 4):", stdout);
    fgets(paths, MAX_PATH * 4 + 4, stdin);
}
int check(char delim, char *paths, char *reject) {}
int process() {}
int output() {}

int main(int argc, char const *argv[]) {
    char delim;
    char paths[MAX_PATH * 4 + 4] = '\0';
    char reject[12] = {'\\', '/', ':', '*',   '?',   '\"',
                       '<',  '>', '|', delim, '\\0', '\0'};

    return 0;
}