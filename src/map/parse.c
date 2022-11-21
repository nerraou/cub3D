/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:46:35 by ybahlaou          #+#    #+#             */
/*   Updated: 2022/11/21 16:43:23 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void init_texture(void *mlx, const char *path, t_texture *texture)
{
	texture->img = mlx_xpm_file_to_image(mlx, (char *)path,
										 &texture->width, &texture->height);
	if (texture->img)
		texture->addr = (int *)mlx_get_data_addr(texture->img,
												 &texture->bits_per_pixel,
												 &texture->line_length, &texture->endian);
}

static void read_textures(void *mlx, t_map *map)
{
	init_texture(mlx, map->no_wall_texture, &map->textures.no);
	init_texture(mlx, map->ea_wall_texture, &map->textures.ea);
	init_texture(mlx, map->so_wall_texture, &map->textures.so);
	init_texture(mlx, map->we_wall_texture, &map->textures.we);
	init_texture(mlx, "./assets/opned-door.xpm", &map->textures.opened_door);
	init_texture(mlx, "./assets/door.xpm", &map->textures.closed_door);
}

static int init_textures(void *mlx, t_map *map)
{
	read_textures(mlx, map);
	if (!map->textures.no.img || !map->textures.no.addr)
		ft_putendl_fd("North " TEXTURE_ERROR, STDERR_FILENO);
	if (!map->textures.ea.img || !map->textures.ea.addr)
		ft_putendl_fd("East " TEXTURE_ERROR, STDERR_FILENO);
	if (!map->textures.we.img || !map->textures.we.addr)
		ft_putendl_fd("West" TEXTURE_ERROR, STDERR_FILENO);
	if (!map->textures.so.img || !map->textures.so.addr)
		ft_putendl_fd("South " TEXTURE_ERROR, STDERR_FILENO);
	if (!map->textures.opened_door.img || !map->textures.opened_door.addr)
		ft_putendl_fd("Door " TEXTURE_ERROR, STDERR_FILENO);
	if (!map->textures.closed_door.img || !map->textures.closed_door.addr)
		ft_putendl_fd("Door " TEXTURE_ERROR, STDERR_FILENO);
	return (!map->textures.no.img || !map->textures.no.addr || !map->textures.ea.img || !map->textures.ea.addr || !map->textures.we.img || !map->textures.we.addr || !map->textures.so.img || !map->textures.so.addr);
}

int parse(const char *path, void *mlx, t_map *map)
{
	int fd;
	int has_error;

	if (!ft_strendswith(path, ".cub"))
		return (perror_and_return("bad file extension, use .cub", 1));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	init_map(map);
	has_error = map_parse_header(fd, map);
	if (!has_error)
		has_error = init_textures(mlx, map);
	if (!has_error)
		has_error = map_parse_map(fd, map);
	if (!has_error && !is_good_map(map))
		has_error = perror_and_return("map is not closed", 1);
	if (!has_error && set_replace_player_position(map, map->scale))
		has_error = perror_and_return("missing player position", 1);
	if (!has_error)
		player_init(&map->player, map->player_orientation);
	close(fd);
	return (has_error);
}
