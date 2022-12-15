#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right)
{
    if (arr == NULL)
    {
        return -1;
    }

    int swaps = 0;

    if (left < right)
    {
        int k = left;
        int j = right;
        char *center = arr[(j + k) / 2];
        while (k <= j)
        {
            while (mx_strlen(arr[k]) < mx_strlen(center))
                k++;
            while (mx_strlen(arr[j]) > mx_strlen(center))
                j--;

            if (k <= j)
            {
                if (mx_strlen(arr[j]) != mx_strlen(arr[k]))
                {
                    char *temp = arr[k];
                    arr[k] = arr[j];
                    arr[j] = temp;
                    swaps++;
                }
                j--;
                k++;
            }
        }
        swaps += mx_quicksort(arr, left, j);
        swaps += mx_quicksort(arr, k, right);
    }

    return swaps;
}

