/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:47:05 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/16 20:02:27 by nerraou          ###   ########.fr       */
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

void draw_rays(t_data *data, t_ray *ray, t_map *map)
{
	float move_angle;
	float ray_distance;
	float distance;
	float wall_strip_height;
	int horizontal;
	int topwallhit;
	int botomwallhit;

	int texX;
	int texY;
	float wallX;
	float step;
	float textpos;
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

		if (horizontal == 1)
			wallX = map->player.x + ray_distance * ray_hit_point;
		else
			wallX = map->player.y + ray_distance * ray_hit_point;

		wallX -= floor(wallX);

		texX = (int)(wallX * (float)map->textures.ea.width);

		if (horizontal && ray_hit_point > 0.0f)
			texX = map->textures.ea.width - texX - 1;
		if (!horizontal && ray_hit_point < 0.0f)
			texX = map->textures.ea.width - texX - 1;

		topwallhit = ((data->height) / 2) - (wall_strip_height / 2);
		botomwallhit = ((data->height) / 2) + (wall_strip_height / 2);

		step = 1.0f * map->textures.ea.height / wall_strip_height;
		textpos = (topwallhit - data->height / 2 + wall_strip_height / 2) * step;
		int *color;
		for (int y = topwallhit; y < botomwallhit; y++)
		{
			texY = (int)textpos & (map->textures.ea.height - 1);
			textpos += step;
			color = (int *)(map->textures.ea.addr + (texY * map->textures.ea.line_length + texX * 4));
			// if (horizontal == 0)
			// *color = (*color >> 1) & 8355711;
			fill(data, *color);
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
