#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

uint32_t generate_number() {
    const int r = rand();
    const int p = r % 100;
    if (p < 90) {
        return r % 128;
    }
    if (p < 95) {
        return r % 16384;
    }
    if (p < 99) {
        return r % 2097152;
    }
    return r % 268435455;
}

size_t encode_varint(uint32_t value, uint8_t *buf) {
    assert(buf != NULL);
    uint8_t *cur = buf;
    while (value >= 0x80) {
        const uint8_t byte = (value & 0x7f) | 0x80;
        *cur = byte;
        value >>= 7;
        ++cur;
    }
    *cur = value;
    ++cur;
    return cur - buf;
}

uint32_t decode_varint(const uint8_t **bufp) {
    const uint8_t *cur = *bufp;
    uint8_t byte = *cur++;
    uint32_t value = byte & 0x7f;
    size_t shift = 7;
    while (byte >= 0x80) {
        byte = *cur++;
        value += (byte & 0x7f) << shift;
        shift += 7;
    }
    *bufp = cur;
    return value;
}

int main() {
    srand(time(NULL));
    FILE *uncompressed;
    uncompressed = fopen("uncompressed.dat", "w+");
    FILE *compressed;
    compressed = fopen("compressed.dat", "w");
    int i;
    uint32_t number;
    uint8_t *buf = (uint8_t *)malloc(sizeof(uint8_t) * 256);
    const uint8_t **bufp = *buf;
    for (i = 0; i < 10; i++) {
        number = generate_number();
        fprintf(uncompressed, "%d ", number);
        printf("%4d %d \n", number, i);
        encode_varint(number, buf);
        fprintf(compressed, "%d ", *buf);
        printf("%4d %4d\n", number, *buf);
    }
    for (int i = 0; i < 10; ++i) {

        fscanf(compressed, "%ls ", bufp);
        fscanf(uncompressed, "%d ", &number);
        decode_varint(bufp);
        printf("%s\n", *bufp);
        if (**bufp == number) {
            printf("pass\n");
        }
    }
    return 0;
}