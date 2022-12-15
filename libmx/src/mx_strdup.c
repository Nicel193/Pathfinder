#include "../inc/libmx.h"

char *mx_strdup(const char *s1)
{
    char *new_str = mx_strnew(mx_strlen(s1));

    return mx_strcpy(new_str, s1);
}

