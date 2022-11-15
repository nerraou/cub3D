#include "map.h"

int parse(const char *path, t_map *map)
{
    int fd;
    int has_error;

    if (!ft_strendswith(path, ".cub"))
        return (-2);
    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (1);
    init_map(map);
    has_error = map_parse_header(fd, map);
    if (!has_error)
        has_error = map_parse_map(fd, map);
    if (!has_error)
        has_error = !is_good_map(map);
    if (!has_error)
        has_error = set_replace_player_position(map, map->scale);
    if (!has_error)
        player_init(&map->player, map->player_orientation);
    close(fd);
    return (has_error);
}
