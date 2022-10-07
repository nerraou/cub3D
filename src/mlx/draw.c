/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:36:43 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/07 13:58:11 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int horizontal_wall_length(char **map, int y_pos, int x_pos)
{
	int count;

	count = 0;

	while (map[y_pos][x_pos] == '1')
	{
		x_pos++;
		count++;
	}
	return count;
}

int vertical_wall_length(char **map, int *length, int y_pos, int x_pos)
{
	int count;

	count = 0;

	while (map[y_pos] && map[y_pos][x_pos] == '1')
	{
		if (x_pos >= length[y_pos])
			break;
		y_pos++;
		count++;
	}
	return count;
}

void draw_horizontal_line(t_data *data, int color, int length, int x, int y)
{
	int i;

	i = 0;
	while (i < length)
	{
		ft_mlx_pixel_put(data, x, y, color);
		x++;
		i++;
	}
}

void draw_vertical_line(t_data *data, int color, int length, int x, int y)
{
	int i;

	i = 0;
	while (i < length)
	{
		ft_mlx_pixel_put(data, x, y, color);
		y++;
		i++;
	}
}

void draw(t_data *data, char **map, int *length)
{
	int x;
	int y;
	int s;
	int len;

	s = 20;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x])
		{

			if (map[y][x] == '1')
			{

				len = horizontal_wall_length(map, y, x);
				draw_horizontal_line(data, parse_color("255,255,255"), s * (len - 1), s * x, s * y);
				len = vertical_wall_length(map, length, y, x);
				draw_vertical_line(data, parse_color("255,255,255"), s * (len - 1), s * x, s * y);
			}
			else
				printf("*");
			x++;
		}
		printf("\n");
		y++;
	}
}