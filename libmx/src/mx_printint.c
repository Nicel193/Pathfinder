#include "../inc/libmx.h"

void mx_printint(int n)
{
    int buf[10];
    int len = 0;

    if (n == -2147483648)
    {
        mx_printstr("-2147483648");
        return;
    }

    if (n == 0)
    {
        mx_printchar('0');
        return;
    }

    if (n < 0)
    {
        mx_printchar('-');
        n = -n;
    }

    while (n != 0)
    {
        buf[len] = n % 10;
        n /= 10;
        len++;
    }

    for (int j = (len - 1); j >= 0; j--)
        mx_printchar(buf[j] + '0');
}

