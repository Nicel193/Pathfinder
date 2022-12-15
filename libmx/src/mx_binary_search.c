#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count)
{
    int min = 0;
    int max = size - 1;

    if (!*arr)
        return -1;

    while (min <= max)
    {
        (*count)++;

        int mid = (min + max) / 2;

        if (mx_strcmp(arr[mid], s) == 0)
            return mid;

        (mx_strcmp(arr[mid], s) > 0) ? (max = mid - 1) : (min = mid + 1);
    }

    (*count) = 0;
    return -1;
}

