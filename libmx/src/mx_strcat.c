#include "../inc/libmx.h"

char *mx_strcat(char* restricts1, const char* restricts2)
{
    char *ptr = restricts1 + mx_strlen(restricts1);

    while (*restricts2)
        *(ptr++) = *(restricts2++);

    *ptr = '\0';

    return restricts1;
}

