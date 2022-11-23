/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:13:23 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/23 19:25:48 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define TEXTURE_ERROR "texture doesn't exists, not valid or \
cannot be initialized"

# include "unistd.h"
# include <fcntl.h>
# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"
# include "list.h"
# include "player.h"
# include "texture.h"
# include "ray.h"

typedef struct s_minimap
{
	int			scale;
	t_player	player;
	int			x;
	int			y;
}				t_minimap;

typedef struct s_map
{
	char		**map_array;
	char		*no_wall_texture;
	char		*so_wall_texture;
	char		*we_wall_texture;
	char		*ea_wall_texture;
	char		player_orientation;
	int			*widths;
	int			floor_color;
	int			ceiling_color;
	int			width;
	int			height;
	int			scale;
	int			is_door;
	t_textures	textures;
	t_player	player;
	t_ray		*ray;
	t_minimap	minimap;
}				t_map;

int		set_textures(const char *line, t_map *map);
int		set_replace_player_position(t_map *data, int scale);
int		set_ceiling_color(const char *line, t_map *map);
int		set_floor_color(const char *line, t_map *map);
int		set_colors(const char *line, t_map *map);
int		open_map(const char *path);
int		rgb_from_string(const char *str);
int		map_has_header(const t_map *map);
int		map_parse_header(int fd, t_map *map);
int		map_parse_map(int fd, t_map *map);
int		is_good_map(const t_map *map);
int		is_wall(int x, int y, int scale, t_map *map);
int		parse(const char *path, void *mlx, t_map *map);
int		is_door(t_map *map, int x, int y);

void	set_map_widths(int **widths, char **map, int size);
void	init_map(t_map *map);

#endif
