/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:47:05 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/18 00:38:05 by ybahlaou         ###   ########.fr       */
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

int *create_texture(int width, int height)
{
	int *texture;
	int x;
	int y;

	texture = (int *)malloc(sizeof(int) * width * height);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (x % 8 && y % 8)
				texture[y * height + x] = 0x0000FF;
			else
				texture[y * height + x] = 0x000000;
			x++;
		}
		y++;
	}
	return (texture);
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
	// int *texture = create_texture(map->textures.ea.height, map->textures.ea.height);

	float ray_hit_point;

	horizontal = 0;
	move_angle = map->player.rotation_angle - (ray->fov_angle / 2);
	distance = ((data->width) / 2) / tan(ray->fov_angle / 2);

	int i = 0;
	while (i < ray->num_rays)
	{
		move_angle = normalize_angle(move_angle);
		ray_distance = cast_ray(data, map, move_angle, &horizontal, &ray_hit_point);
		ray_distance = ray_distance * cos(move_angle - map->player.rotation_angle);
		wall_strip_height = map->scale / ray_distance * distance;

		topwallhit = ((data->height) / 2) - (wall_strip_height / 2);
		botomwallhit = ((data->height) / 2) + (wall_strip_height / 2);

		// int texture_offset_x = (int)ray_hit_point % map->textures.ea.width;
		float texture_offset_x = ray_hit_point / map->scale;
		texture_offset_x -= floor(texture_offset_x);
		texture_offset_x *= map->textures.ea.width;

		int texture_offset_y;
		// float tex_pos = (topwallhit - data->height / 2.0f + wall_strip_height / 2.0f);

		for (int y = topwallhit; y < botomwallhit; y++)
		{
			float distance_from_top = y + (wall_strip_height / 2.0f) - (data->height / 2.0f);
			texture_offset_y = distance_from_top * map->textures.ea.height / wall_strip_height;
			int *texture = (int *)map->textures.ea.addr;
			int width = map->textures.ea.width;

			fill(data, texture[texture_offset_y * width + (int)texture_offset_x]);
			ft_mlx_pixel_put(data, i * ray->wall_width, y);
		}

		// draw_rect(data, i * ray->wall_width, topwallhit, ray->wall_width, wall_strip_height);
		fill(data, map->ceiling_color);
		draw_rect(data, i * ray->wall_width, 0, ray->wall_width, topwallhit);
		fill(data, map->floor_color);
		draw_rect(data, i * ray->wall_width, botomwallhit, ray->wall_width, topwallhit);
		move_angle += ray->fov_angle / (data->width);
		i++;
	}
}
