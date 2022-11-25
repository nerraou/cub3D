/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ceiling_floor_color.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:07:17 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/23 23:41:23 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void	apply_ceiling_floor_color(t_data *data, t_tuplef wall_ends, int ray_num)
{
	t_vector2	c_start;
	t_vector2	f_start;

	c_start.x = ray_num;
	c_start.y = 0;
	f_start.x = ray_num;
	f_start.y = wall_ends.value2;
	fill(data, data->map->ceiling_color);
	draw_rect(data, c_start, data->map->ray->wall_width, wall_ends.value1);
	fill(data, data->map->floor_color);
	draw_rect(data, f_start, data->map->ray->wall_width, \
	wall_ends.value1);
}
