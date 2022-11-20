/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_projection_wall.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:52:36 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/20 18:53:56 by nerraou          ###   ########.fr       */
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

void draw_door(t_data *data, t_texture *texture, t_tuplef values, int ray_num)
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
	if (data->map->is_door == 0)
		apply_wall_texture(data, define_texture(data->map, angle_ray, horizontal), (t_tuplef){wall_strip_height, ray_hit_point}, ray_num);
	else
	{

		draw_door(data, &(data->map->textures.door), (t_tuplef){wall_strip_height, ray_hit_point}, ray_num);
	}
}
