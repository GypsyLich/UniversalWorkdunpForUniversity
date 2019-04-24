#include <stdio.h>

unsigned int slen(const char *s) {
    const char *sc = s;
    while (*sc != '\0') {
        ++sc;
    }
    return sc - s;
}

char *stok(char **s, const char *ct) {
    char *sbegin = *s;
    const char *sc1, *sc2;

    if (sbegin == NULL) {
        return NULL;
    }

    for (sc1 = sbegin; *sc1 != '\0'; ++sc1) {
        for (sc2 = ct; *sc2 != '\0'; ++sc2) {
            if (*sc1 == *sc2) {
                return (char *)sc1;
            }
        }
    }

    return sbegin;
}

short int scmp(const char *cs, const char *ct) {
    char c1, c2;

    while (1) {
        c1 = *cs++;
        c2 = *ct++;
        if (c1 != c2) {
            return c1 < c2 ? -1 : 1;
        }
        if (!c1) {
            break;
        }
    }
    return 0;
}

unsigned int sspn(const char *string, const char *reject) {
    const char *p;
    const char *r;
    unsigned int count = 0;

    for (p = string; *p != '\0'; ++p) {
        for (r = reject; *r != '\0'; ++r) {
            if (*p == *r) {
                return count;
            }
        }
        ++count;
    }
    return count;
}

char *scpy(char *destination, const char *src) {
    char *temp = destination;

    while (*src != '\0') {
        *destination++ = *src++;
    }
    return temp;
}