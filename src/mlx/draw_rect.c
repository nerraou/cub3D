/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:25:38 by ybahlaou          #+#    #+#             */
/*   Updated: 2022/11/23 23:37:48 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void draw_rect(t_data *data, t_vector2 start, int width, int height)
{
	int dx;

	if (start.x < 0)
		start.x = 0;
	if (start.y < 0)
	 	start.y = 0;

	height += start.y;
	width += start.x;
	while (start.y <= height)
	{
		dx = start.x;
		while (dx <= width)
		{
			ft_mlx_pixel_put(data, dx, start.y);
			dx++;
		}
		vector2_set_y(&start, start.y + 1);
	}
}
