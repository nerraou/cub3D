/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_has_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 08:18:40 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/22 10:39:36 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	map_has_header(const t_map *map)
{
	return (map->ceiling_color != -1 \
	&& map->floor_color != -1 \
	&& map->no_wall_texture \
	&& map->so_wall_texture \
	&& map->we_wall_texture \
	&& map->ea_wall_texture);
}
