#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str)
{
    if (str == NULL)
    {
        return NULL;
    }

    char *mem = mx_strnew(mx_strlen(str));

    int i = 0;
    int j = 0;

    while (str[i])
    {
        if (!(mx_isspace(str[i])))
        {
            mem[j] = str[i];
            j++;
        }
        if (!(mx_isspace(str[i])) && mx_isspace(str[i + 1]))
        {
            mem[j] = ' ';
            j++;
        }
        i++;
    }

    char *new_str = mx_strtrim(mem);
    mx_strdel(&mem);
    return new_str;
}

