#include "../inc/libmx.h"

bool mx_isword(const char *str)
{
    if (str == NULL)
    {
        return false;
    }

    for (int i = 0; str[i]; i++)
    {
        if (!mx_isalpha(str[i]))
        {
            return false;
        }
    }

    return true;
}

bool mx_isdigit_word(const char *str)
{
     if (str == NULL)
    {
        return false;
    }

    for (int i = 0; str[i]; i++)
    {
        if (!mx_isdigit(str[i]))
        {
            return false;
        }
    }

    return true;
}

