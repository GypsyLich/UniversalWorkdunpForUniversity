#include "command.h"
#include "coder.h"
#include <assert.h>
#include <inttypes.h>
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encode_file(const char *in_file_name, const char *out_file_name) {

    FILE *out_file = NULL;
    FILE *in_file = NULL;

    out_file = fopen(out_file_name, "w+");
    in_file = fopen(in_file_name, "r+t");

    char symbol;
    uint32_t number = 0;
    int error = 0;

    CodeUnits *code_units = malloc(sizeof(CodeUnits));

    for (; !feof(in_file);) {
        fscanf(in_file, "%c", &symbol);

        if ('0' <= symbol && symbol <= '9' && error == 0) {
            if (number == -1)
                number = 0;
            number = 16 * number + symbol - '0';
        } else if ('a' <= symbol && symbol <= 'f' && error == 0) {
            if (number == -1)
                number = 0;
            number = 16 * number + symbol - 'a' + 10;
        } else if (number < 2097152 && symbol == '\n' && error == 0) {
            encode(number, code_units);
            write_code_unit(out_file, code_units);
            number = -1;
            error = 0;
        } else if (symbol == '\n') {
            error = 0;
            number = -1;
            continue;
        } else {
            error = 1;
            number = -1;
        }
    }

    fclose(out_file);
    fclose(in_file);

    return 0;
}

int decode_file(const char *in_file_name, const char *out_file_name) {

    FILE *out_file = NULL;
    FILE *in_file = NULL;

    out_file = fopen(out_file_name, "w+");
    in_file = fopen(in_file_name, "r+t");

    CodeUnits *code_units = malloc(sizeof(CodeUnits));

    int k;
    uint32_t number;
    code_units->length = 1;
    for (k = 1;; k++) {
        ;

        if ((read_next_code_unit(in_file, code_units)) == -1)
            continue;
        number = decode(code_units);

        if (feof(in_file))
            break;

        fprintf(out_file, "%x%c", number, '\n');
        k += code_units->length - 1;
        fseek(in_file, k, SEEK_SET);
    }

    fclose(out_file);
    fclose(in_file);

    return 0;
}
