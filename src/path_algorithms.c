#include "../inc/pathfinder.h"

static int min_distance(int dist[], bool sptSet[], int n)
{
    int min = __INT_MAX__, min_index;

    for (int v = 0; v < n; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

static void find(t_part_path path[], int **graph, char *current_name, t_list *names_vertices, int current_distance, int n, int u, int total)
{
    for (int i = 0; i < n; i++)
    {
        if (graph[u][i] != 0 && (total + graph[u][i]) == current_distance && mx_strcmp(mx_get_value_from_index(names_vertices, i), current_name) == 0)
        {
            add_to_path(path, mx_get_value_from_index(names_vertices, i), graph[u][i]);
            print_path(path, current_name, current_distance);
            delete_from_path(path);
            continue;
        }
        if (graph[u][i] != 0 && (total + graph[u][i]) < current_distance)
        {
            add_to_path(path, mx_get_value_from_index(names_vertices, i), graph[u][i]);
            find(path, graph, current_name, names_vertices, current_distance, n, i, total + graph[u][i]);
        }
    }

    delete_from_path(path);
}

static void find_similar_pathway(int **graph, char *current_name, t_list *names_vertices, int current_distance, int n)
{
    t_part_path path[n * n];

    init_path(path, n);
    add_to_path(path, mx_get_value_from_index(names_vertices, 0), 0);
    find(path, graph, current_name, names_vertices, current_distance, n, 0, 0);
}

void find_pathway(t_list *names_vertices, int **graph, int n, int print_count)
{
    int dist[n];

    bool sptSet[n];

    for (int i = 0; i < n; i++)
        dist[i] = __INT_MAX__, sptSet[i] = false;

    dist[0] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int u = min_distance(dist, sptSet, n);

        sptSet[u] = true;

        for (int v = 0; v < n; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != __INT_MAX__ && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    for (int i = (n - print_count); i < n; i++)
    {
        find_similar_pathway(graph, mx_get_value_from_index(names_vertices, i), names_vertices, dist[i], n);
    }
}
