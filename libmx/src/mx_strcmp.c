#include "../inc/libmx.h"


int mx_strcmp(const char *s1, const char *s2)
{
    if (*s1 == '\0' && *s2 == '\0')
        return 0;

    while (*(s1++) | *(s2++))
    {
        if (*(s1 - 1) > *(s2 - 1))
        {
            return 1;
        }
        if (*(s1 - 1) < *(s2 - 1))
        {
            return -1;
        }
    }

    return 0;
}

