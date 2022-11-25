/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:12:47 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/21 18:07:16 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int	is_door(t_map *map, int x, int y)
{
	int	map_x;
	int	map_y;

	map_x = (x / map->scale);
	map_y = (y / map->scale);
	if (map->map_array[map_y] != NULL)
	{
		if (map->map_array[map_y][map_x] == 'D')
			return (1);
	}
	return (0);
}
