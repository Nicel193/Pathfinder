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

char *mx_strstr(const char *haystack, const char *needle)
{
    while (*haystack)
    {
        if (mx_strncmp(haystack, needle, mx_strlen(needle)) != 0)
        {
            haystack++;
        }
        else
        {
            break;
        }

        haystack = mx_strchr(haystack, *needle);
    }

    return (*haystack != '\0') ? (char *)haystack : '\0';
}

