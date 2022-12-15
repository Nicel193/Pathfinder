#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n)
{
    if (n <= 0)
    {
        return 0;
    }
    
    const unsigned char *str1 = (const unsigned char *)s1;
    const unsigned char *str2 = (const unsigned char *)s2;
    int i = 0;

    while (str1[i] == str2[i] && i != (int)n)
    {
        if (str1[i] == '\0' && str2[i] == '\0')
        {
            return 0;
        }

        i++;
    }
    return str1[i] - str2[i];
}

