#include "../inc/libmx.h"

char* mx_get_value_from_index(t_list *list, int index)
{
    while (list != NULL)
    {
        if (index == 0)
        {
            return list->data;
        }

        list = list->next;
        index--;
    }

    return NULL;
}

