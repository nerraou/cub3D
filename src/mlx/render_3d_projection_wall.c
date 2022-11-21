/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_projection_wall.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:52:36 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/21 16:46:00 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

static int is_ray_facing_down(float angle)
{
	if (angle > 0.0f && angle < (float)M_PI)
		return 1;
	return -1;
}

static int is_ray_facing_right(float angle)
{
	if (angle > 3.0f * (float)M_PI_2 || angle < (float)M_PI_2)
		return 1;
	return -1;
}

static t_texture *define_texture(t_map *map, float angle, int horizontal)
{
	if (is_ray_facing_down(angle) == 1 && horizontal)
		return &(map->textures.so);
	if (is_ray_facing_down(angle) == -1 && horizontal)
		return &(map->textures.no);
	if (is_ray_facing_right(angle) == -1 && !horizontal)
		return &(map->textures.ea);
	else
		return &(map->textures.we);
}

/*
 ** tuple is created to hold the wall_strip_heigt and ray_hit_point
 */
void render_3d_projection_wall(t_data *data, float angle_ray, int ray_num)
{
	float ray_distance;
	float distance_to_projection;
	float wall_strip_height;
	float ray_hit_point;
	int horizontal;

	distance_to_projection = ((data->width / 2) / tan(data->map->ray->fov_angle / 2));

	ray_distance = cast_ray(data->map, angle_ray, &horizontal, &ray_hit_point);
	ray_distance = ray_distance * cos(angle_ray - data->map->player.rotation_angle);
	wall_strip_height = data->map->scale / ray_distance * distance_to_projection;

	if (data->map->is_door == 1)
	{
		if (ray_distance < 60)
			draw_door(data, &(data->map->textures.opened_door), (t_tuplef){wall_strip_height, ray_hit_point}, ray_num);
		else
			draw_door(data, &(data->map->textures.closed_door), (t_tuplef){wall_strip_height, ray_hit_point}, ray_num);
	}
	else
		apply_wall_texture(data, define_texture(data->map, angle_ray, horizontal), (t_tuplef){wall_strip_height, ray_hit_point}, ray_num);
}
