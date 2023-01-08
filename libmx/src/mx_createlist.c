#include "../inc/libmx.h"

t_list **mx_createlist()
{
    t_list **new_list = malloc(sizeof(t_list *));
    *new_list = malloc(sizeof(t_list));

    return new_list;
}

