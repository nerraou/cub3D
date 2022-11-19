#include "map.h"

int init_texture(void *mlx, t_map *map)
{

    map->textures.ea.img = mlx_xpm_file_to_image(mlx, "./assets/wall.xpm", &map->textures.ea.width, &map->textures.ea.height);
    if (!map->textures.ea.img)
        return -1;
    map->textures.ea.addr = mlx_get_data_addr(map->textures.ea.img, &map->textures.ea.bits_per_pixel, &map->textures.ea.line_length, &map->textures.ea.endian);
    if (!map->textures.ea.addr)
        return -1;
    map->textures.we.img = mlx_xpm_file_to_image(mlx, "./assets/wall2.xpm", &map->textures.we.width, &map->textures.we.height);
    if (!map->textures.we.img)
        return -1;
    map->textures.we.addr = mlx_get_data_addr(map->textures.we.img, &map->textures.we.bits_per_pixel, &map->textures.we.line_length, &map->textures.we.endian);
    if (!map->textures.we.addr)
        return -1;
    map->textures.so.img = mlx_xpm_file_to_image(mlx, "./assets/wall3.xpm", &map->textures.so.width, &map->textures.so.height);
    if (!map->textures.so.img)
        return -1;
    map->textures.so.addr = mlx_get_data_addr(map->textures.so.img, &map->textures.so.bits_per_pixel, &map->textures.so.line_length, &map->textures.so.endian);
    if (!map->textures.so.addr)
        return -1;
    map->textures.no.img = mlx_xpm_file_to_image(mlx, "./assets/wall4.xpm", &map->textures.no.width, &map->textures.no.height);
    if (!map->textures.no.img)
        return -1;
    map->textures.no.addr = mlx_get_data_addr(map->textures.no.img, &map->textures.no.bits_per_pixel, &map->textures.no.line_length, &map->textures.no.endian);
    if (!map->textures.no.addr)
        return -1;
    return 1;
}

int parse(const char *path, void *mlx, t_map *map)
{
    int fd;
    int has_error;

    if (!ft_strendswith(path, ".cub"))
        return (-2);
    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (1);
    init_map(map);
    init_texture(mlx, map);
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
