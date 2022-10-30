/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:36:43 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/27 17:09:52 by nerraou          ###   ########.fr       */
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

void draw_minimap(t_data *data, char **map)
{
	int x;
	int y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x])
		{
			fill(data, get_color(map[y][x]));
			if (map[y][x] == '1')
				draw_rect(data, x * data->scale, y * data->scale, data->scale, data->scale);
			x++;
		}
		y++;
	}
}
