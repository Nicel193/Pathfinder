#include "../inc/libmx.h"

int mx_atoi(const char *str)
{
    int val = 0;
    bool is_negative = false;

    while (*(str++))
    {
        if (mx_isspace(*(str - 1)))
            continue;

        if (mx_isdigit(*(str - 1)))
        {
            (!is_negative) ? (val += *(str - 1) - '0') : (val -= *(str - 1) - '0');

            if (mx_isdigit(*(str)))
                val *= 10;
            else
                break;
        }
        else if (val == 0)
        {
            if (*(str - 1) == '-')
            {
                is_negative = true;

                continue;
            }

            break;
        }
    }

    return val;
}

