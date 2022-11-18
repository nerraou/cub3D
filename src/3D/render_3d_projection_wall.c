/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_projection_wall.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:52:36 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/14 11:17:45 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_3d.h"

void render_3d_projection_wall(t_data *data, t_map *map, t_ray *ray, float ray_distance)
{
	float distance;
	float wall_strip_height;
	distance = (data->width / 2) / tan(ray->fov_angle / 2);

	wall_strip_height = map->scale / ray_distance * distance;
}