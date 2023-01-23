#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
    unsigned char *str_p = (unsigned char *)str;

    if (n) {
        while (n--) {
            *str_p = c;
        }
    }
    
    return str;
}