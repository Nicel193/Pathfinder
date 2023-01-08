#include "../inc/pathfinder.h"

int main(int argc, char const *argv[])
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

    return 0;
}

