#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n)
{
    if((int)n > mx_strlen(s1) || n <= 0) return NULL;

    char *new_str = mx_strnew(n);

    return mx_strncpy(new_str, s1, n);
}

