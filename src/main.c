#include "../inc/pathfinder.h"
#include <time.h>
#include <stdio.h>
#include "main.h"

double measureExecutionTime(void (*func)())
{
    clock_t start, end;
    start = clock();

    end = clock();

    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

void start_app(int argc, const char *argv[])
{
    t_pathfinder_data data;
    int count_vertices = 0;

    data.file_text = get_file_text(argc, argv);
    data.nodes = get_nodes(data);
    data.names_vertices = get_names_vertices(data.nodes, &count_vertices);

    error_invalid_number(count_vertices, data.file_text, data);
    error_duplicate_bridges(data.nodes, data);

    pathfinder(data.nodes, data.names_vertices, count_vertices);

    delete_pathfinder_data(data);
}

int main(int argc, char const *argv[])
{
    clock_t start, end;
    start = clock();

    start_app(argc, argv);

    end = clock();

    double cpu_time_used = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("Execution time: %.2f ms\n", cpu_time_used);

    return 0;
}