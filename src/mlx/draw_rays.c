/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:47:05 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/13 17:47:23 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void draw_rays(t_data *data, t_ray *ray, t_map *map)
{
	float move_angle;
	float ray_distance;
	float distance;
	float wall_strip_height;
	int horizontal;
	int topwallhit;
	int botomwallhit;

	horizontal = 0;
	move_angle = map->player.rotation_angle - (ray->fov_angle / 2);
	distance = ((data->width) / 2) / tan(ray->fov_angle / 2);
	int i = 0;
	while (i < ray->num_rays)
	{
		move_angle = normalize_angle(move_angle);
		ray_distance = cast_ray(data, map, move_angle, &horizontal);
		ray_distance = ray_distance * cos(move_angle - map->player.rotation_angle);
		wall_strip_height = map->scale / ray_distance * distance;
		if (horizontal == 1)
			fill(data, 0xffffff);
		else
			fill(data, 0x808080);
		topwallhit = ((data->height) / 2) - (wall_strip_height / 2);
		botomwallhit = ((data->height) / 2) + (wall_strip_height / 2);

		draw_rect(data, i * ray->wall_width, topwallhit, ray->wall_width, wall_strip_height);
		fill(data, map->ceiling_color);
		draw_rect(data, i * ray->wall_width, 0, ray->wall_width, topwallhit);
		fill(data, map->floor_color);
		draw_rect(data, i * ray->wall_width, botomwallhit, ray->wall_width, topwallhit);
		move_angle += ray->fov_angle / (data->width);
		i++;
	}
}
