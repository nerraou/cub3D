/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_open_door.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:10:41 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/21 10:11:41 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void draw_open_door(t_data *data, t_texture *texture, t_tuplef values, int ray_num)
{
	t_tuplef wall_ends;
	t_vector2 text_coor;
	float step;
	float texture_pos;
	int y;

	wall_ends.value1 = ((data->height) / 2) - (values.value1 / 2);
	wall_ends.value2 = ((data->height) / 2) + (values.value1 / 2);
	text_coor.x = values.value2 / data->scale;
	text_coor.x -= floor(text_coor.x);
	text_coor.x *= texture->width;
	step = ((float)texture->height / values.value1);
	texture_pos = (wall_ends.value1 - data->height / 2.0f + values.value1 / 2.0f) * step;
	y = (int)wall_ends.value1;
	while (y < (int)wall_ends.value2)
	{
		text_coor.y = (int)texture_pos & (texture->height - 1);
		texture_pos += step;
		fill(data, texture->addr[texture->width * (int)text_coor.y + (int)text_coor.x]);
		ft_mlx_pixel_put(data, ray_num, y);
		y++;
	}
	apply_ceiling_floor_color(data, wall_ends, ray_num);
}