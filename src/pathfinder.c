#include "../inc/pathfinder.h"

void cleanup_resources(t_list *names_verticesdup, int **graph, int count_vertices)
{
    delete_list(names_verticesdup);
    delete_matrix(graph, count_vertices);
}

void pathfinder(t_list *nodes, t_list *names_vertices, int count_vertices)
{
    int n = count_vertices;
    int **graph = create_matrix(nodes, names_vertices, count_vertices);
    t_list *names_verticesdup = mx_listdup(names_vertices);
    t_list *temp = names_verticesdup;

    while (n != 1)
    {
        find_pathway(names_vertices, graph, count_vertices, n - 1);
        mx_swap_list(names_vertices, temp->data, temp->next->data);

        graph = matrix_rebild(graph, nodes, names_vertices, count_vertices);

        temp = temp->next;
        n--;
    }

    cleanup_resources(names_verticesdup, graph, count_vertices);
}