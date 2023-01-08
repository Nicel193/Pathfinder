#ifndef PATHFINDER
#define PATHFINDER

#include "libmx.h"

typedef struct s_node
{
    char *first_vertex;
    char *second_vertex;
    int edge_length;
} t_node;

typedef struct s_vertex
{
    char *name_vertex;

    struct s_vertex **input_neighbors;
    struct s_vertex **output_neighbors;

    int **edges_length;

} t_vertex;

typedef struct s_part_path
{
    char *name;
    int length;
} t_part_path;

typedef struct s_pathfinder_data
{
    char *file_text;
    t_list *nodes;
    t_list *names_vertices;
} t_pathfinder_data;

// File
char *get_file_text(int argc, char const *argv[]);

// Nodes(Part path)
t_list *get_nodes(t_pathfinder_data data);
t_list *get_names_vertices(t_list *nodes, int *count);
bool is_same_node(t_node *node_first, t_node *node_second);

// Matrix
int **create_matrix(t_list *nodes, t_list *names_vertices, int n);
int **matrix_rebild(int **graph, t_list *nodes, t_list *names_vertices, int n);
void print_matrix(int **graph, int n);

// Path
void pathfinder(t_list *nodes, t_list *names_vertices, int count_vertices);
void find_pathway(t_list *names_vertices, int **graph, int n, int print_count);
int get_index_last_element(t_part_path path[]);
void init_path(t_part_path path[], int n);
void add_to_path(t_part_path path[], char *name_vertex, int distance);
void delete_from_path(t_part_path path[]);
void print_path(t_part_path path[], char *last_element_name, int total_distance);

// Errors
void error_invalid_number(int counted, char *file_text, t_pathfinder_data data);
void error_sum_of_bridges_lengths(long int sum, t_pathfinder_data data, char *str_line);
void error_duplicate_bridges(t_list *nodes, t_pathfinder_data data);

// Free memory
void delete_list(t_list *list);
void delete_list_nodes(t_list *list);
void delete_node(t_node *node);
void delete_matrix(int **graph, int n);
void delete_pathfinder_data(t_pathfinder_data data);

#endif
