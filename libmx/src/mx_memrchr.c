#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n)
{
    if (n <= 0)
    {
        return 0;
    }

    unsigned char *ptr = (unsigned char *)s + mx_strlen(s);

    while (n != 0)
    {
        if (*ptr == (unsigned char)c)
        {
            return ptr;
        }

        ptr--;
        n--;
    }

    return NULL;
}

