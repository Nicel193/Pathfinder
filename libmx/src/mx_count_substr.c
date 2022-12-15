#include "../inc/libmx.h"

static char *mx_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == c)
            break;

        s++;
    }

    return (char *)s;
}

int mx_count_substr(const char *str, const char *sub)
{
    if (str == NULL || sub == NULL)
    {
        return -2;
    }

    int count = 0;

    while (*str)
    {
        mx_strstr(str, sub);

        count++;
        str++;

        str = mx_strchr(str, *sub);
    }

    return count;
}

