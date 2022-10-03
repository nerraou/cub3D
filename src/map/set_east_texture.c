/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_east_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:45:04 by nerraou           #+#    #+#             */
/*   Updated: 2022/09/28 17:15:03 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void set_east_texture(char *line, t_map *map)
{
	size_t size;

	size = ft_strlen(line + ft_indexof(line, '.'));
	map->ea_wall_texture = (char *)malloc(sizeof(char) * size + 1);
	if (!map->no_wall_texture)
		return;
	ft_strncpy(map->ea_wall_texture, line + ft_indexof(line, '.'), size + 1);
}