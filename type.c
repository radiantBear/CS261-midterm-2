#include "type.h"

/* djb2 from http://www.cse.yorku.ca/~oz/hash.html */
unsigned long string_hash(char *str) {
    unsigned long hash = 5381;
    int c;

    while((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}