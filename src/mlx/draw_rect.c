/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:25:38 by ybahlaou          #+#    #+#             */
/*   Updated: 2022/11/13 17:32:13 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void draw_rect(t_data *data, int x, int y, int width, int height)
{
	int dx;

	x = x < 0 ? 0 : x;
	y = y < 0 ? 0 : y;

	height += y;
	width += x;
	while (y <= height)
	{
		dx = x;
		while (dx < width)
		{
			ft_mlx_pixel_put(data, dx, y);
			dx++;
		}
		y++;
	}
}
