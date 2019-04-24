#include "coder.h"
#include "command.h"
#include <assert.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("\nUsage:\ncoder encode <in-file-name> <out-file-name>\ncoder "
               "decode <in-file-name> <out-file-name>\n");
        return -1;
    }

    if (strcmp(argv[1], "encode") == 0) {
        encode_file(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decode") == 0) {
        decode_file(argv[2], argv[3]);
    } else {
        printf("Invalid command\n");
        return -1;
    }

    return 0;
}
