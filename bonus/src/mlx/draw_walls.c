/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:47:05 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/22 16:03:26 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void	draw_walls(t_data *data, t_ray *ray, t_map *map)
{
	float	move_angle;
	int		i;

	i = 0;
	move_angle = map->player.rotation_angle - (ray->fov_angle / 2);
	while (i < ray->num_rays)
	{
		move_angle = normalize_angle(move_angle);
		render_3d_projection_wall(data, move_angle, i * ray->wall_width);
		move_angle += ray->fov_angle / (data->width);
		i++;
	}
}
