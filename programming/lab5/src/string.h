#pragma once

unsigned int slen(const char *s);
char *stok(char **s, const char *ct);
short int scmp(const char *cs, const char *ct);
unsigned int sspn(const char *string, const char *reject);
char *scpy(char *destination, const char *src);