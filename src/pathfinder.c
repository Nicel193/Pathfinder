#include "../inc/pathfinder.h"

void pathfinder(t_list *nodes, t_list *names_vertices, int count_vertices)
{
    int **graph = create_matrix(nodes, names_vertices, count_vertices);
    t_list *names_verticesdup = mx_listdup(names_vertices);

    t_list *temp = names_verticesdup;
    int n = count_vertices;
    
    while (n != 1)
    {
        // print_matrix(graph, count_vertices);
        find_pathway(names_vertices, graph, count_vertices, n - 1);

        mx_swap_list(names_vertices, temp->data, temp->next->data);
        temp = temp->next;

        graph = matrix_rebild(graph, nodes, names_vertices, count_vertices);
        n--;
    }

    delete_list(names_verticesdup);
    delete_matrix(graph, count_vertices);
}

