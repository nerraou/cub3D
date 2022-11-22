/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:25:38 by ybahlaou          #+#    #+#             */
/*   Updated: 2022/11/22 15:59:07 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void draw_rect(t_data *data, int x, int y, int width, int height)
{
	int dx;

	if (x < 0)
		x = 0;
	if (y < 0)
	 	y = 0;

	height += y;
	width += x;
	while (y <= height)
	{
		dx = x;
		while (dx <= width)
		{
			ft_mlx_pixel_put(data, dx, y);
			dx++;
		}
		y++;
	}
}
