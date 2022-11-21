/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:12:47 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/21 11:49:39 by nerraou          ###   ########.fr       */
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
			return 1;
	}
	return 0;
}