/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:10:41 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/24 16:58:59 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void	draw_door(t_data *data, t_texture *t, t_tuplef values, int ray_num)
{
	t_tuplef	wall_ends;
	t_vector2	text_coor;
	float		step;
	float		texture_pos;
	int			y;

	wall_ends.value1 = ((data->height) / 2) - (values.value1 / 2);
	wall_ends.value2 = ((data->height) / 2) + (values.value1 / 2);
	text_coor.x = values.value2 / data->scale;
	text_coor.x -= floor(text_coor.x);
	text_coor.x *= t->width;
	step = ((float)t->height / values.value1);
	texture_pos = step * \
	(wall_ends.value1 - data->height / 2.0f + values.value1 / 2.0f);
	y = (int)wall_ends.value1;
	while (y < (int)wall_ends.value2)
	{
		text_coor.y = (int)texture_pos % t->height;
		texture_pos += step;
		fill(data, t->addr[t->width * (int)text_coor.y + (int)text_coor.x]);
		ft_mlx_pixel_put(data, ray_num, y);
		y++;
	}
	apply_ceiling_floor_color(data, wall_ends, ray_num);
}
