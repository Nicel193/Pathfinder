#include "../inc/libmx.h"

int mx_long_len(unsigned long num)
{
    int len = 0;

    while (num != 0)
    {
        num /= 16;
        len++;
    }
    return len;
}

char *mx_nbr_to_hex(unsigned long nbr)
{
    int len = mx_long_len(nbr);

    char *hex = (char *)malloc(len);

    len -= 1;

    for (unsigned long num = nbr; num != 0; num /= 16)
    {
        unsigned long rem = num % 16;
        if (rem < 10)
            hex[len--] = rem + '0';
        else
            hex[len--] = rem + 'W';
    }

    return hex;
}

