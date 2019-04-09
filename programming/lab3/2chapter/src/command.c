#include "command.h"
#include "coder.h"
#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int encode_file(const char* in_file_name, const char* out_file_name)
{
    CodeUnits* new = (CodeUnits*)malloc(sizeof(CodeUnits));
    FILE* in_file = fopen(in_file_name, "r");
    FILE* out_file = fopen(out_file_name, "w");
    int code = 0;
    while (1) {
        code = read_next_code_unit(in_file, new);
        if (code == 0) {
            write_code_unit(out_file, new);
        } else if (code == 1) {
            printf("Error encode_file\n");
            return -1;
        } else {
            fprintf(stderr, "End of file\n");
            break;
        }
    }
    fclose(in_file);
    fclose(out_file);
    fprintf(stderr, "Success complete encode_file()\n");
    return 0;
}

int decode_file(const char* in_file_name, const char* out_file_name)
{
    CodeUnits* new = (CodeUnits*)malloc(sizeof(CodeUnits));
    FILE* in_file = fopen(in_file_name, "r");
    FILE* out_file = fopen(out_file_name, "w");
    int code = 0;
    while (1) {
        code = read_next(in_file, new);
        if (code == 0) {
            write_next(out_file, new);
        } else if (code == 1) {
            printf("Error dencode_file\n");
            return -1;
        } else {
            fprintf(stderr, "End of file\n");
            break;
        }
    }
    fclose(in_file);
    fclose(out_file);
    fprintf(stderr, "Success complete decode_file()\n");
    return 0;
}
