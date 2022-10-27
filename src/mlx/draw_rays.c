/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:47:05 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/27 17:53:24 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void draw_rays(t_data *data, t_ray *ray, t_map *map)
{

	float move_angle;
	float endX;
	float endY;
	float xStep;
	float yStep;
	float yIntercept;
	float xIntercept;
	endX = 0.0f;
	endY = 0.0f;
	fill(data, 0xF3DE2C);
	move_angle = map->player.rotation_angle - (ray->fov_angle / 2);

	yIntercept = floor(map->player.y / data->scale) * data->scale;
	xIntercept = map->player.x + (yIntercept - map->player.y) / tan(move_angle);
	if (is_wall(xIntercept, yIntercept, data->scale, map->map_array))
	{
		draw_line(data, map->player.x, map->player.y, xIntercept, yIntercept);
		return;
	}
	// while (i < ray->num_rays)
	yStep = data->scale;
	xStep = yStep / tan(move_angle);

	while (1)
	{
		endX += xIntercept;
		endY += yIntercept;
		if (is_wall(endX, endY, data->scale, map->map_array))
		{
			draw_line(data, map->player.x, map->player.y, endX, endY);
			break;
		}

		// move_angle += ray->fov_angle / (32 * 20);
	}
}
