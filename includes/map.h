/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:13:23 by nerraou           #+#    #+#             */
/*   Updated: 2022/09/28 17:13:32 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include "libft.h"

typedef struct s_map
{
	char **map_array;
	char *no_wall_texture;
	char *so_wall_texture;
	char *we_wall_texture;
	char *ea_wall_texture;
	int floor_color;
	int ceiling_color;
} t_map;

void set_west_texture(char *line, t_map *map);
void set_north_texture(char *line, t_map *map);
void set_east_texture(char *line, t_map *map);
void set_south_texture(char *line, t_map *map);
void set_map_textures(char *line, t_map *map);

#endif
