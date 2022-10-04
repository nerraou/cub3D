/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:36:43 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/04 17:46:04 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void draw(t_data *data, char **map)
{
	int x;
	int start;
	int y;
	int s;

	s = 20;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
			{
				start = x;
				while (map[y][x] == '1')
				{
					x++;
				}
				draw_line(data, start, y, x, y, parse_color("255,255,255,255"));
			}
			else
				ft_mlx_pixel_put(data, x * s, y * s, parse_color("0,0,0"));
			x++;
		}
		y++;
	}
}