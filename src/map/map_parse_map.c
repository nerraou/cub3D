#include "map.h"

static char *skip_empty_lines(int fd)
{
    char *line;

    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            return (NULL);
        if (*line != '\0')
            return (line);
        free(line);
    }
    return (NULL);
}

static int max_width(int *widths, int len)
{
    int i;
    int max_value;

    max_value = widths[0];
    i = 1;
    while (i < len)
    {
        if (widths[i] > max_value)
            max_value = widths[i];
        i++;
    }
    return max_value;
}

static void list_del_node(void *content)
{
    (void)content;
}

int map_parse_map(int fd, t_map *map)
{
    char *line;
    t_list *list;
    int has_error;

    has_error = 0;
    line = skip_empty_lines(fd);
    if (!line)
        return (1);
    list = list_new();
    if (!list)
    {
        free(line);
        return (1);
    }
    while (line)
    {
        add_back(list, (void *)line);
        if (line[0] == '\0')
        {
            has_error = 1;
            break;
        }
        line = get_next_line(fd);
    }
    map->map_array = list_to_array(list);
    set_line_length(&map->length, map->map_array, list->size);
    map->height = list->size;
    map->width = max_width(map->length, list->size);
    list_del(&list, list_del_node);
    return (has_error || map->height <= 2);
}
