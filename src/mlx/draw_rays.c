/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:47:05 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/01 16:31:30 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void draw_rays(t_data *data, t_ray *ray, t_map *map)
{
	float move_angle;

	move_angle = map->player.rotation_angle - (ray->fov_angle / 2);

	int i = 0;
	while (i < ray->num_rays)
	{
		move_angle = normalize_angle(move_angle);
		cast_ray(data, map, move_angle);
		move_angle += ray->fov_angle / (34 * 20);
		i++;
	}
}
