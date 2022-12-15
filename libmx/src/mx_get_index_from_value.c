#include "../inc/libmx.h"

int mx_get_index_from_value(t_list *list, char *name)
{
    int index = 0;

    while (list != NULL)
    {
        if (mx_strcmp(list->data, name) == 0)
        {
            return index;
        }

        list = list->next;
        index++;
    }

    return index;
}

