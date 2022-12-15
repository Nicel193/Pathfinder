#include "../inc/pathfinder.h"

void init_path(t_part_path path[], int n)
{
    for (int i = 0; i < n * n; i++)
    {
        path[i].name = NULL;
    }
}

int get_index_last_element(t_part_path path[])
{
    int index = 0;

    while (path[index].name != NULL)
        index++;

    return index;
}

void add_to_path(t_part_path path[], char *name_vertex, int distance)
{
    int index = get_index_last_element(path);

    path[index].name = name_vertex;
    path[index].length = distance;
}

void delete_from_path(t_part_path path[])
{
    int index = get_index_last_element(path) - 1;

    path[index].name = NULL;
    path[index].length = 0;
}

