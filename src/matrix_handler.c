#include "../inc/pathfinder.h"

void print_matrix(int **graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mx_printint(graph[i][j]);
            mx_printchar(' ');
        }
        mx_printchar('\n');
    }
    mx_printchar('\n');
}

void delete_matrix(int **graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(*&graph[i]);
    }

    free(graph);
}

int **matrix_rebild(int **graph, t_list *nodes, t_list *names_vertices, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    t_list *temp_nodes = nodes;
    while (temp_nodes != NULL)
    {
        t_node *node = (t_node *)(temp_nodes->data);

        int second_index = mx_get_index_from_value(names_vertices, node->first_vertex);
        int first_index = mx_get_index_from_value(names_vertices, node->second_vertex);

        graph[first_index][second_index] = node->edge_length;
        graph[second_index][first_index] = node->edge_length;

        temp_nodes = temp_nodes->next;
    }

    return graph;
}

int **create_matrix(t_list *nodes, t_list *names_vertices, int n)
{
    int **graph = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    t_list *temp_nodes = nodes;
    while (temp_nodes != NULL)
    {
        t_node *node = (t_node *)(temp_nodes->data);

        int first_index = mx_get_index_from_value(names_vertices, node->first_vertex);
        int second_index = mx_get_index_from_value(names_vertices, node->second_vertex);

        graph[first_index][second_index] = node->edge_length;
        graph[second_index][first_index] = node->edge_length;

        temp_nodes = temp_nodes->next;
    }

    return graph;
}

