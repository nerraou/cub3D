/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:56:41 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/23 23:50:37 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void	draw_line(t_data *data, t_vector2 begin, t_vector2 end)
{
	double delta_x;
	double delta_y;
	double pixel_x;
	double pixel_y;
	int pixels;

	delta_x = end.x - begin.x;
	delta_y = end.y - begin.y;
	pixel_x = begin.x;
	pixel_y = begin.y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = begin.x;
	pixel_y = begin.y;
	while (pixels)
	{
		ft_mlx_pixel_put(data, pixel_x, pixel_y);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}
