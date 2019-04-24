#include "coder.h"
#include "command.h"
#include <assert.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encode(uint32_t code_point, CodeUnits *code_units) {
    if (code_point < 128) {
        code_units->length = 1;
        code_units->code[0] = code_point & 127;
    }
    if (127 < code_point && code_point < 2048) {
        code_units->length = 2;
        code_units->code[1] = ((code_point)&63) + 128;
        code_units->code[0] = ((code_point >> 6) & 31) + 192;
    }
    if (2047 < code_point && code_point < 65536) {
        code_units->length = 3;
        code_units->code[2] = ((code_point)&63) + 128;
        code_units->code[1] = ((code_point >> 6) & 63) + 128;
        code_units->code[0] = ((code_point >> 12) & 15) + 224;
    }
    if (65535 < code_point && code_point < 2097152) {
        code_units->length = 4;
        code_units->code[3] = ((code_point)&63) + 128;
        code_units->code[2] = ((code_point >> 6) & 63) + 128;
        code_units->code[1] = ((code_point >> 12) & 63) + 128;
        code_units->code[0] = ((code_point >> 18) & 7) + 240;
    }

    return 0;
}

uint32_t decode(const CodeUnits *code_units) {

    if (code_units->length == 1) {
        return code_units->code[0];
    }
    if (code_units->length == 2) {
        return (((code_units->code[0] - 192) << 6) + code_units->code[1] - 128);
    }
    if (code_units->length == 3) {
        return (
            ((((code_units->code[0] - 224) << 6) + code_units->code[1] - 128)
             << 6) +
            code_units->code[2] - 128);
    }
    if (code_units->length == 4) {
        return (
            ((((((code_units->code[0] - 240) << 6) + code_units->code[1] - 128)
               << 6) +
              code_units->code[2] - 128)
             << 6) +
            code_units->code[3] - 128);
    }

    return 0;
}

int name(int size, CodeUnits *code_units, FILE *in) {
    code_units->length = size;
    for (int i = 1; i < size; i++) {
        fread(&code_units->code[i], sizeof(uint8_t), 1, in);
        if (code_units->code[i] > 191 || code_units->code[i] < 128)
            return -1;
    }
    return 0;
}

int read_next_code_unit(FILE *in, CodeUnits *code_units) {

    uint8_t k;
    fread(&k, sizeof(uint8_t), 1, in);
    if (k > 240) {
        code_units->code[0] = k;
        if (name(4, code_units, in) == -1)
            return -1;
    }
    if (240 > k && k > 224) {
        code_units->code[0] = k;
        if (name(3, code_units, in) == -1)
            return -1;
    }
    if (224 > k && k > 192) {
        code_units->code[0] = k;
        if (name(2, code_units, in) == -1)
            return -1;
    }
    if (k < 128) {
        code_units->length = 1;
        code_units->code[0] = k;
    }
    if ((193 > k && k > 127) || k == 224 || k == 240)
        return -1;

    return 0;
}

int write_code_unit(FILE *out, const CodeUnits *code_units) {

    fwrite(code_units->code, sizeof(uint8_t), code_units->length, out);

    return 0;
}
