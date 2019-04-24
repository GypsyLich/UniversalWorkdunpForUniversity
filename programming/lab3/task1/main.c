#include "task1.h"
#include <assert.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define N 1000000

int main() {
    FILE *fileG = NULL;
    FILE *fileB = NULL;
    fileB = fopen("uncompressed.bin", "wb");
    fileG = fopen("compressed.bin", "wb");

    uint32_t number;
    uint8_t *buf = (uint8_t *)malloc(sizeof(uint8_t));
    size_t size;

    for (int i = 0; i < N; i++) {

        number = generate_number();

        fwrite(&number, sizeof(uint32_t), 1, fileB);

        // buf = &number;
        size = encode_varint(number, buf);
        fwrite(buf, sizeof(uint8_t), size, fileG);
    }

    fseek(fileB, 0, SEEK_SET);
    fseek(fileG, 0, SEEK_SET);
    int k, j;
    uint32_t numberBad, numberGood;
    uint8_t *bufer = (uint8_t *)malloc(sizeof(uint8_t));

    for (k = 0, j = 0; j < N; k++, j++) {

        fseek(fileG, k, SEEK_SET);
        fread(bufer, sizeof(uint8_t), 4, fileG);
        numberGood = decode_varint((const uint8_t **)&bufer);
        fread(&numberBad, sizeof(uint32_t), 1, fileB);
        if (numberGood > 127)
            k++;
        if (numberGood > 16383)
            k++;
        if (numberGood > 2097151)
            k++;

        if (numberBad != numberGood) {
            printf("!!!!!!!!!!!!!!\n");
            break;
        }
    }

    fclose(fileB);
    fclose(fileG);

    return 0;
}
