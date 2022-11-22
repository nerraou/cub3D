/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_wall_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:42:11 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/22 12:20:50 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void	apply_wall_texture(t_data *d, t_texture *t, t_tuplef values, int r_num)
{
	t_tuplef	wall_ends;
	t_vector2	text_coor;
	float		step;
	float		texture_pos;
	int			y;

	wall_ends.value1 = ((d->height) / 2) - (values.value1 / 2);
	wall_ends.value2 = ((d->height) / 2) + (values.value1 / 2);
	text_coor.x = values.value2 / d->scale;
	text_coor.x -= floor(text_coor.x);
	text_coor.x *= t->width;
	step = ((float)t->height / values.value1);
	texture_pos = step * \
	(wall_ends.value1 - d->height / 2.0f + values.value1 / 2.0f);
	y = (int)wall_ends.value1;
	while (y < (int)wall_ends.value2)
	{
		text_coor.y = (int)texture_pos & (t->height - 1);
		texture_pos += step;
		fill(d, t->addr[t->width * (int)text_coor.y + (int)text_coor.x]);
		ft_mlx_pixel_put(d, r_num, y);
		y++;
	}
	apply_ceiling_floor_color(d, wall_ends, r_num);
}
