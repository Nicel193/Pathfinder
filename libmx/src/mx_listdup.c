#include "../inc/libmx.h"

t_list *mx_listdup(t_list *list)
{
    t_list *new_list = NULL;

    while (list != NULL)
    {
        mx_push_back(&new_list, list->data);

        list = list->next;
    }

    return new_list;
}

