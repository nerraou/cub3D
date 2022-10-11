/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:36:43 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/11 10:23:00 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

static int get_color(char cell_value)
{
	if (cell_value == '1')
		return 0xFFFFFF;
	else if (cell_value == ' ' || cell_value == '0')
		return 0x000000;
	return 0xFFAA00;
}

void draw(t_data *data, char **map)
{
	int x;
	int y;
	int s;

	s = 20;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x])
		{
			fill(data, get_color(map[y][x]));
			if (map[y][x] == '1')
				draw_rect(data, x * s, y * s, s, s);
			else if (ft_indexof("NSEW", map[y][x]) != -1)
				draw_rect(data, x * s + 5, y * s + 5, 10, 10);
			x++;
		}
		y++;
	}
}
