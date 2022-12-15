#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace)
{
    if (str == NULL || sub == NULL || replace == NULL || mx_strlen(str) <= mx_strlen(sub))
    {
        return NULL;
    }

    if(*sub == '\0')
    {
       return mx_strdup(str);
    }

    int count_sub = mx_count_substr(str, sub);
    char *new_str = mx_strnew((mx_strlen(str) - (mx_strlen(sub) * count_sub)) + (mx_strlen(replace) * count_sub));

    for (int i = 0, j = 0; str[i]; i++, j++)
    {
        while (!mx_strncmp(&str[i], (char *)sub, mx_strlen(sub)))
        {
            for (int k = 0; replace[k]; k++, j++)
                new_str[j] = replace[k];

            i += mx_strlen(sub);
        }

        new_str[j] = str[i];
    }

    return new_str;
}

