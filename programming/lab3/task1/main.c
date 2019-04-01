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
    for (i = 0; i < 10; i++) {
        uint32_t number = generate_number();
        fprintf(uncompressed, "%d ", number);
        printf("%4d %d \n", number, i);
        uint8_t *buf = number;
        encode_varint(number, buf);
        fprintf(compressed, "%d ", *buf);
        printf("%4d\n", *buf);
    }
    return 0;
}