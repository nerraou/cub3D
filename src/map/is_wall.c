/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:06:06 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/17 18:40:00 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int is_wall(int x, int y, int scale, char **map)
{
	int mapX;
	int mapY;

	mapX = (x / scale);
	mapY = (y / scale);
	if (map[mapY] != NULL)
	{
		if (map[mapY][mapX] == '1')
			return 1;
	}
	return 0;
}
