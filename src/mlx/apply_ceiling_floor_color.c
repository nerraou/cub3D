/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ceiling_floor_color.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:07:17 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/22 12:09:52 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void	apply_ceiling_floor_color(t_data *data, t_tuplef wall_ends, int ray_num)
{
	fill(data, data->map->ceiling_color);
	draw_rect(data, ray_num, 0, data->map->ray->wall_width, wall_ends.value1);
	fill(data, data->map->floor_color);
	draw_rect(data, ray_num, wall_ends.value2, data->map->ray->wall_width, \
	wall_ends.value1);
}
