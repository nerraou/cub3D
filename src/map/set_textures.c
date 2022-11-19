/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:24:35 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/19 15:38:13 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int set_textures(const char *line, t_map *map)
{
	char *path;

	path = ft_strctrim(line + 2, ' ');
	if (!path || *path == '\0')
	{
		free(path);
		return (1);
	}
	if (ft_strncmp(line, "NO ", 3) == 0)
		map->no_wall_texture = path;
	if (ft_strncmp(line, "SO ", 3) == 0)
		map->so_wall_texture = path;
	if (ft_strncmp(line, "WE ", 3) == 0)
		map->we_wall_texture = path;
	if (ft_strncmp(line, "EA ", 3) == 0)
		map->ea_wall_texture = path;
	return (0);
}
