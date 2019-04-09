#include "coder.h"
#include "command.h"

void helper()
{
    fprintf(stderr,
            "Usage:\n"
            "coder encode <in-file-name> <out-file-name>\n"
            "coder decode <in-file-name> <out-file-name>\n");
}

int main(int argc, char** argv)
{
    if (argc < 4) {
        helper();
        exit(EXIT_FAILURE);
    }
    if (strcmp("encode", argv[1]) && strcmp("decode", argv[1])) {
        helper();
        exit(EXIT_FAILURE);
    }
    int in_descriptor = -1;
    int out_descriptor = -1;
    if ((in_descriptor = open(argv[2], O_RDONLY)) == -1) {
        fprintf(stderr, "File open error: %s\n", argv[2]);
        helper();
        exit(EXIT_FAILURE);
    }
    if ((out_descriptor = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0666))
        == -1) {
        fprintf(stderr, "File open error: %s\n", argv[3]);
        helper();
        exit(EXIT_FAILURE);
    }

    if (!strcmp("encode", argv[1])) {
        encode_file(argv[2], argv[3]);
    } else if (!strcmp("decode", argv[1])) {
        decode_file(argv[2], argv[3]);
    }

    exit(EXIT_SUCCESS);
}
