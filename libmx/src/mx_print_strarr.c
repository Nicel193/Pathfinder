#include "../inc/libmx.h"

void mx_print_strarr(char **arr, const char *delim)
{
    if (arr == NULL || delim == NULL)
    {
        return;
    }

    for (int i = 0; arr != NULL; i++)
    {
       mx_printstr(*(arr++));
       mx_printchar((char)delim);
    }
}

