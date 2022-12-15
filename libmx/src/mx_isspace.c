#include "stdbool.h"

bool mx_isspace(int c)
{
    return c == 32 || (c >= 9 && c <= 13);
}

