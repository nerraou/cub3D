/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:06:06 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/22 23:06:21 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	is_wall(int x, int y, int scale, t_map *map)
{
	int	map_x;
	int	map_y;

	map_x = (x / scale);
	map_y = (y / scale);
	if (map_y < 0 || map_y >= map->height || map_x < 0 || map_x >= map->widths[map_y])
		return (1);
	if (map->map_array[map_y] != NULL)
	{
		if (map->map_array[map_y][map_x] == '1')
			return (1);
	}
	return (0);
}
