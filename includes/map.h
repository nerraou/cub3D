/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:13:23 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/19 09:58:48 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include "unistd.h"
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#include "list.h"
#include "player.h"
#include "texture.h"

typedef struct s_map
{
	char player_orientation;
	char **map_array;
	char *no_wall_texture;
	char *so_wall_texture;
	char *we_wall_texture;
	char *ea_wall_texture;
	int floor_color;
	int ceiling_color;
	int *length;
	int width;
	int height;
	int scale;
	t_textures textures;
	t_player player;
} t_map;

int set_textures(const char *line, t_map *map);
int set_replace_player_position(t_map *data, int scale);
int set_ceiling_color(const char *line, t_map *map);
void set_line_length(int **length, char **map, int size);
int set_floor_color(const char *line, t_map *map);
int set_colors(const char *line, t_map *map);
void init_map(t_map *map);

int open_map(const char *path);
int rgb_from_string(const char *str);
int map_has_header(const t_map *map);
int map_parse_header(int fd, t_map *map);
int map_parse_map(int fd, t_map *map);
int is_good_map(const t_map *map);
int is_wall(int x, int y, int scale, char **map);
int parse(const char *path, t_map *map);

#endif
