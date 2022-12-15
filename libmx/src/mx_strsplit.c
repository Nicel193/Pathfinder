#include "../inc/libmx.h"

char **mx_strsplit(char const *s, char c)
{
    if(s == NULL)
    {
        return NULL;
    }

    int count_words = mx_count_words(s, c);

    char **arr = (char **)malloc(count_words * 8);

    int end = 0;
    int start = 0;

    for (int i = 0; i < count_words; i++)
    {
        int len = 0;
        start = end;

        for (int j = end; s[j]; j++)
        {
            if (s[j] != c)
            {
                len++;
            }
            else
            {
                if (len != 0)
                {
                    end = j;
                    break;
                }
                else
                {
                    start = j + 1;
                }
            }
        }

        char *new_word = mx_strnew(len);

        arr[i] = mx_strncpy(new_word, &s[start], len);
    }

    arr[count_words] = NULL;

    return arr;
}

