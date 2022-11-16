/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:13:23 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/16 19:50:23 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include "libft.h"
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
	int scale;
	t_textures textures;
	t_player player;
} t_map;

void set_west_texture(char *line, t_map *map);
void set_north_texture(char *line, t_map *map);
void set_east_texture(char *line, t_map *map);
void set_south_texture(char *line, t_map *map);
void set_map_textures(char *line, t_map *map);
void set_replace_player_position(t_map *data, int scale);
void set_ceiling_color(const char *line, t_map *map);
void set_line_length(int **length, char **map, int size);
void set_floor_color(const char *line, t_map *map);
void set_colors(char *line, t_map *map);
void init_map(t_map *map);

int parse_color(const char *str);
int has_header(const t_map *map);
int is_wall(int x, int y, int scale, char **map);

#endif
