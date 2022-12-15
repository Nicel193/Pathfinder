#include "../inc/libmx.h"

int mx_count_words(const char *str, char delimiter)
{ 
    bool is_count = false;
    int count = 0;
    int temp = 0;

    while (*str)
    {
        if (*str == ' ')
        {
            temp = 0;
        }
        else if (temp == 0 && is_count)
        {
            temp = 1;

            count++;
        } 
        
        if (*str == delimiter) is_count = true;

        ++str;
    }

    return count;
}

