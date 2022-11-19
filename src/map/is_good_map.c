#include "map.h"

static char **copy_map_array(int *widths, int height)
{
    char **copy;
    int i;

    copy = (char **)malloc(sizeof(char *) * (height + 1));
    if (!copy)
        return (NULL);
    i = 0;
    while (i < height)
    {
        copy[i] = (char *)malloc(sizeof(char) * (widths[i] + 1));
        ft_memset(copy[i], '-', widths[i]);
        copy[i][widths[i]] = '\0';
        i++;
    }
    copy[i] = NULL;
    return (copy);
}

static void walk(const t_map *map, char **visited, int x, int y)
{
    char **map_array;

    map_array = map->map_array;
    if (y - 1 < 0 || y + 1 >= map->height || x - 1 < 0 || x + 1 >= map->widths[y])
    {
        visited[y][x] = 'b';
        return;
    }
    if (map_array[y - 1][x] == ' ' || map_array[y][x + 1] == ' ' ||
        map_array[y + 1][x] == ' ' || map_array[y][x - 1] == ' ')
    {
        visited[y][x] = 'b';
        return;
    }
    if (visited[y][x] == '1')
        return;
    visited[y][x] = '1';
    if (map_array[y - 1][x] == '0')
        walk(map, visited, x, y - 1);
    if (map_array[y][x + 1] == '0')
        walk(map, visited, x + 1, y);
    if (map_array[y + 1][x] == '0')
        walk(map, visited, x, y + 1);
    if (map_array[y][x - 1] == '0')
        walk(map, visited, x - 1, y);
}

static int is_bad_map(char **visited, int height)
{
    int i;

    i = 0;
    while (i < height)
    {
        if (ft_indexof(visited[i], 'b') != -1)
            return (1);
        i++;
    }
    return (0);
}

int is_good_map(const t_map *map)
{
    char **visited;
    int y;
    int x;

    visited = copy_map_array(map->widths, map->height);
    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (map->map_array[y][x])
        {
            if (map->map_array[y][x] == '0' && visited[y][x] == '-')
                walk(map, visited, x, y);
            x++;
        }
        y++;
    }
    return (!is_bad_map(visited, map->height));
}
