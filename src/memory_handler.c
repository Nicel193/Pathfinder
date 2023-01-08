#include "../inc/pathfinder.h"

void delete_list(t_list *list)
{
    while (list != NULL)
    {
        mx_pop_back(&list);
    }
}

void delete_list_nodes(t_list *list)
{
    while (list != NULL)
    {
        delete_node(mx_get_last_list_element(list)->data);
        mx_pop_back(&list);
    }
}

void delete_node(t_node *node)
{
    free(node->first_vertex);
    free(node->second_vertex);
    free(node);
}

void delete_pathfinder_data(t_pathfinder_data data)
{
    free(data.file_text);
    if (data.nodes != NULL)delete_list_nodes(data.nodes);
    if (data.names_vertices != NULL)delete_list(data.names_vertices);
}

