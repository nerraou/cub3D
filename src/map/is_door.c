/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:12:47 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/20 17:56:14 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int is_door(t_map *map, int x, int y)
{
	int mapX;
	int mapY;

	mapX = (x / map->scale);
	mapY = (y / map->scale);
	if (map->map_array[mapY] != NULL)
	{
		if (map->map_array[mapY][mapX] == 'D')
		{
			map->is_door = 1;
			return 1;
		}
	}
	map->is_door = 0;
	return 0;
}