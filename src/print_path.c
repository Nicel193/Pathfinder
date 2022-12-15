#include "../inc/pathfinder.h"

void print_path(t_part_path path[], char *last_element_name, int total_distance)
{
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(path[0].name);
    mx_printstr(" -> ");
    mx_printstr(last_element_name);
    mx_printchar('\n');

    mx_printstr("Route: ");
    for (int i = 0; path[i].name != NULL; i++)
    {
        mx_printstr(path[i].name);

        if (path[i + 1].name != NULL)
            mx_printstr(" -> ");
    }

    mx_printchar('\n');
    mx_printstr("Distance: ");
    if (path[2].name != NULL)
    {
        for (int i = 1; path[i].name != NULL; i++)
        {
            mx_printint(path[i].length);

            if (path[i + 1].name != NULL)
                mx_printstr(" + ");
        }

        mx_printstr(" = ");
    }
    mx_printint(total_distance);
    mx_printchar('\n');

    mx_printstr("========================================\n");
}

