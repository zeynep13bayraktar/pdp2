#include "../include/str.h"

char *strdup(const char *s) {
    char *d = malloc(strlen(s) + 1);  // Bellek ayırma
    if (d) strcpy(d, s);              // Kopyalama
    return d;
}