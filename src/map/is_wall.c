/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:06:06 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/22 10:34:49 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	is_wall(int x, int y, int scale, char **map)
{
	int	map_x;
	int	map_y;

	map_x = (x / scale);
	map_y = (y / scale);
	if (map[map_y] != NULL)
	{
		if (map[map_y][map_x] == '1')
			return (1);
	}
	return (0);
}
