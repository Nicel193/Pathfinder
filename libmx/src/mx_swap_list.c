#include "../inc/libmx.h"

void mx_swap_list(t_list *list, char *first, char *second)
{
    char *dup_first = mx_strdup(first);
    char *dup_second = mx_strdup(second);
    while (list != NULL)
    {
        if (mx_strcmp(dup_first, list->data) == 0)
        {
            list->data = second;
            list = list->next;
            continue;
        }

        if(mx_strcmp(dup_second, list->data) == 0)
        {
            list->data = first;
        }

        list = list->next;
    }
    free(dup_first);
    free(dup_second);
}
