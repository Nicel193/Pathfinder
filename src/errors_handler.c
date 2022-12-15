#include "../inc/pathfinder.h"

void error_invalid_number(int counted, char *file_text, t_pathfinder_data data)
{
    char *number = mx_strndup(file_text, (mx_get_char_index(file_text, '\n')));
    int file_count = mx_atoi(number);

    free(number);

    if (counted == file_count)
    {
        return;
    }

    mx_printstr("error: invalid number of islands\n");
    delete_pathfinder_data(data);
    exit(-1);
}

void error_sum_of_bridges_lengths(long int sum, t_pathfinder_data data, char *str_line)
{
    if (sum <= __INT_MAX__)
    {
        return;
    }

    mx_printstr("error: sum of bridges lengths is too big\n");
    free(str_line);
    delete_pathfinder_data(data);
    exit(-1);
}

void error_duplicate_bridges(t_list *nodes, t_pathfinder_data data)
{
    t_list *current_nodes = nodes;
    while (current_nodes != NULL)
    {
        t_list *temp_nodes = current_nodes->next;
        while (temp_nodes)
        {
            if (is_same_node(current_nodes->data, temp_nodes->data))
            {
                mx_printstr("error: duplicate bridges\n");
                delete_pathfinder_data(data);
                exit(-1);
            }

            temp_nodes = temp_nodes->next;
        }

        current_nodes = current_nodes->next;
    }
}

