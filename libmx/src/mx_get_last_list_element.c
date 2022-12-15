#include "../inc/libmx.h"

t_list *mx_get_last_list_element(t_list *list)
{
    while (list != NULL)
    {
        if (list->next == NULL)
        {
            return list;
        }

        list = list->next;
    }

    return list;
}

