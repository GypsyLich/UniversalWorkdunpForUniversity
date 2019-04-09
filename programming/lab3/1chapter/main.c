#include "coder.h"
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *myfile;
  FILE *result;
  FILE *code;
  myfile = fopen("uncompressed.dat", "wt");
  code = fopen("compressed.dat", "wt");
  result = fopen("result.dat", "w");

  if (myfile == NULL || code == NULL || result == NULL) {
    printf("No file\n");
    return 1;
  }
  uint32_t i, j;
  uint8_t *buf = (uint8_t *)malloc(sizeof(uint8_t) * 256);
  uint32_t z;
  uint32_t tmp;

  for (i = 0; i < 100; i++) {
    z = generate_number();
    fprintf(myfile, "%d\n", z);
    fprintf(result, "%d\t", z);
    size_t size = encode_varint(z, buf);
    fprintf(code, "%lu\t", size);
    fprintf(result, "| coder: %lu\t", size);
    for (j = 0; j < size; ++j) {
      fprintf(result, "%u\t", (uint32_t)buf[j]);
      fprintf(code, "%u\t", (uint32_t)buf[j]);
    }
    fprintf(code, "\n");

    if ((tmp = decode_varint(&buf)) != z) {
      printf("Error %u, %u\n", tmp, z);
    }
    fprintf(result, "| decoder: %u\n", tmp);
  }
  fclose(myfile);
  fclose(code);
  fclose(result);
  printf("Done\n");
  return 0;
}
