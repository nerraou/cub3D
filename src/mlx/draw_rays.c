/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:47:05 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/18 19:18:31 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int is_ray_facing_down(float angle)
{
	if (angle > 0.0f && angle < (float)M_PI)
		return 1;
	return -1;
}

int is_ray_facing_right(float angle)
{
	if (angle > 3.0f * (float)M_PI_2 || angle < (float)M_PI_2)
		return 1;
	return -1;
}

t_texture *define_texture(t_map *map, float angle, int horizontal)
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

void draw_rays(t_data *data, t_ray *ray, t_map *map)
{
	float move_angle;
	float ray_distance;
	float distance;
	float wall_strip_height;
	int horizontal;
	int topwallhit;
	int botomwallhit;

	t_vector2 ray_hit_point;
	float step;
	float texture_x;

	horizontal = 0;
	move_angle = map->player.rotation_angle - (ray->fov_angle / 2);
	distance = ((data->width) / 2) / tan(ray->fov_angle / 2);
	t_texture *texture;
	int i = 0;
	while (i < ray->num_rays)
	{
		move_angle = normalize_angle(move_angle);
		ray_distance = cast_ray(data, map, move_angle, &horizontal, &ray_hit_point);
		ray_distance = ray_distance * cos(move_angle - map->player.rotation_angle);
		wall_strip_height = map->scale / ray_distance * distance;

		topwallhit = ((data->height) / 2) - (wall_strip_height / 2);
		botomwallhit = ((data->height) / 2) + (wall_strip_height / 2);

		texture = define_texture(map, move_angle, horizontal);
		if (horizontal)
			texture_x = ray_hit_point.x / map->scale;
		else
			texture_x = ray_hit_point.y / map->scale;

		if (horizontal && ray_hit_point.y < 0)
			texture_x = texture->width - texture_x - 1;
		if (!horizontal && ray_hit_point.x > 0)
			texture_x = texture->width - texture_x - 1;

		texture_x -= floor(texture_x);
		texture_x *= texture->width;

		step = ((float)texture->height / wall_strip_height);
		float texture_pos = (topwallhit - data->height / 2.0f + wall_strip_height / 2.0f) * step;
		int texture_y;

		for (int y = topwallhit; y < botomwallhit; y++)
		{
			texture_y = (int)texture_pos % texture->height;
			texture_pos += step;
			int *texture_array = (int *)texture->addr;
			int width = texture->width;

			fill(data, texture_array[texture_y * width + (int)texture_x]);
			ft_mlx_pixel_put(data, i * ray->wall_width, y);
		}

		fill(data, map->ceiling_color);
		draw_rect(data, i * ray->wall_width, 0, ray->wall_width, topwallhit);
		fill(data, map->floor_color);
		draw_rect(data, i * ray->wall_width, botomwallhit, ray->wall_width, topwallhit);
		move_angle += ray->fov_angle / (data->width);
		i++;
	}
}
