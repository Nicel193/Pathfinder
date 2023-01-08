#include "../inc/pathfinder.h"

static void print_error(int line, t_pathfinder_data data, char *str_line, t_list *nodes)
{
    mx_printstr("error: line ");
    mx_printint(line);
    mx_printstr(" is not valid\n");
    free(str_line);
    free(data.file_text);
    delete_list_nodes(nodes);
    exit(-1);
}

static void create_node(t_list **nodes, char *str_line, int line, long int *sum_of_bridges, t_pathfinder_data data)
{
    int first_element_len = mx_get_char_index(str_line, '-');
    char *first_element = mx_strndup(str_line, first_element_len);

    if (first_element == NULL || !mx_isword(first_element))
    {
        free(first_element);
        print_error(line, data, str_line, *nodes);
    }

    //-------------------------------------------------------------------------------------

    int second_element_len = mx_get_char_index(&str_line[first_element_len], ',');
    char *second_element = mx_strndup(&str_line[first_element_len + 1], second_element_len - 1);

    if (second_element == NULL || !mx_isword(second_element))
    {
        free(first_element);
        free(second_element);
        print_error(line, data, str_line, *nodes);
    }

    //-------------------------------------------------------------------------------------

    int third_element_len = mx_strlen(str_line) - (first_element_len + second_element_len);
    char *third_element = mx_strndup(&str_line[(first_element_len + second_element_len) + 1], third_element_len - 1);

    if (mx_strcmp(first_element, second_element) == 0 || !mx_isdigit_word(third_element))
    {
        free(first_element);
        free(second_element);
        free(third_element);
        print_error(line, data, str_line, *nodes);
    }

    //-------------------------------------------------------------------------------------

    t_node *new_node = malloc(sizeof(t_node));

    new_node->first_vertex = first_element;
    new_node->second_vertex = second_element;

    int distance = mx_atoi(third_element);

    new_node->edge_length = distance;

    free(third_element);
    mx_push_back(nodes, (t_node *)new_node);
    error_sum_of_bridges_lengths((*sum_of_bridges) += distance, data, str_line);
}

bool is_same_node(t_node *node_first, t_node *node_second)
{
    if (mx_strcmp(node_first->first_vertex, node_second->first_vertex) == 0 &&
        mx_strcmp(node_first->second_vertex, node_second->second_vertex) == 0)
        return true;

    if (mx_strcmp(node_first->first_vertex, node_second->second_vertex) == 0 &&
        mx_strcmp(node_first->second_vertex, node_second->first_vertex) == 0)
        return true;

    return false;
}

t_list *get_names_vertices(t_list *nodes, int *count)
{
    t_list *all_names_vertices = NULL;
    t_list *temp_nodes = nodes;

    while (temp_nodes != NULL)
    {
        t_node *node = (t_node *)(temp_nodes->data);

        mx_push_back(&all_names_vertices, node->first_vertex);
        mx_push_back(&all_names_vertices, node->second_vertex);

        temp_nodes = temp_nodes->next;
    }

    t_list *names_vertices = NULL;
    t_list *temp_names = all_names_vertices;

    while (temp_names != NULL)
    {
        t_list *name = names_vertices;
        while (name != NULL)
        {
            if (mx_strcmp(name->data, temp_names->data) == 0)
                break;

            name = name->next;
        }

        if (name == NULL)
        {
            (*count)++;
            mx_push_back(&names_vertices, (char *)temp_names->data);
        }

        temp_names = temp_names->next;
    }

    delete_list(all_names_vertices);

    return names_vertices;
}

t_list *get_nodes(t_pathfinder_data data)
{
    long int sum_of_bridges = 0;
    int line = 1;

    t_list *nodes = NULL;

    for (int i = 0; data.file_text[i] != '\0'; i++)
    {
        int line_len = mx_get_char_index(&(data.file_text)[i], '\n');

        char *incorrect_line = mx_strndup(&(data.file_text)[i], (mx_strlen(data.file_text) - i));
        char *correct_line = mx_strndup(&(data.file_text)[i], line_len);

        char *str_line;

        if (line_len != -1)
        {
            str_line = correct_line;
            free(incorrect_line);
        }
        else
        {
            str_line = incorrect_line;
            free(correct_line);
        }

        if (str_line == NULL)
        {
            print_error(line, data, str_line, nodes);
        }

        if (line > 1)
        {
            create_node(&nodes, str_line, line, &sum_of_bridges, data);
        }

        if (line_len != -1)
        {
            free(correct_line);
        }
        else
        {
            free(incorrect_line);
        }

        line++;
        i += line_len;

        if (line_len == -1)
        {
            break;
        }
    }

    if (line <= 2)
    {
        print_error(line, data, NULL, nodes);
    }

    return nodes;
}

