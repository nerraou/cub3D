/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:47:05 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/20 15:46:17 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void draw_walls(t_data *data, t_ray *ray, t_map *map)
{
	float move_angle;
	int i;

	move_angle = map->player.rotation_angle - (ray->fov_angle / 2);
	i = 0;
	while (i < ray->num_rays)
	{
		move_angle = normalize_angle(move_angle);
		render_3d_projection_wall(data, move_angle, i * ray->wall_width);
		move_angle += ray->fov_angle / (data->width);
		i++;
	}
}