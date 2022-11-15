#include "map.h"

static int should_parse_colors(const char *line)
{
    return line[0] == 'F' || line[0] == 'C';
}

static int should_parse_textures(const char *line)
{
    if (ft_strncmp(line, "NO ", 3) == 0)
        return (1);
    if (ft_strncmp(line, "SO ", 3) == 0)
        return (1);
    if (ft_strncmp(line, "WE ", 3) == 0)
        return (1);
    if (ft_strncmp(line, "EA ", 3) == 0)
        return (1);
    return (0);
}

int map_parse_header(int fd, t_map *map)
{
    char *line;
    int has_error;

    line = NULL;
    has_error = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        if (should_parse_colors(line))
            has_error = set_colors(line, map);
        else if (!has_error && should_parse_textures(line))
            has_error = set_textures(line, map);
        else if (line[0] != '\0')
        {
            free(line);
            return (1);
        }
        free(line);
        if (has_error)
            break;
        if (map_has_header(map))
            break;
    }
    return has_error || !map_has_header(map);
}
