/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:47:05 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/29 18:30:58 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void cast_ray(t_data *data, t_ray *ray, t_map *map, float angle)
{
	int is_ray_facing_down;
	int is_ray_facing_right;
	float y_intercept;
	float x_intercept;
	float x_step;
	float y_step;
	float horizontalwallhit_x;
	float horizontalwallhit_y;

	float verticalowallhit_x;
	float verticalwallhit_y;

	is_ray_facing_down = angle > 0.0f && angle < (float)M_PI;
	is_ray_facing_right = angle > 3.0f * (float)M_PI_2 || angle < (float)M_PI_2;

	y_intercept = floor(map->player.y / data->scale) * data->scale;
	if (is_ray_facing_down)
		y_intercept += data->scale;
	x_intercept = map->player.x + (y_intercept - map->player.y) / tan(angle);
	y_step = data->scale;
	if (!is_ray_facing_down)
		y_step *= -1;

	x_step = y_step / tan(angle);
	if (!is_ray_facing_right && x_step > 0)
		x_step *= -1;
	else if (is_ray_facing_right && x_step < 0)
		x_step *= -1;

	if (!is_ray_facing_down)
		y_intercept--;
	while (x_intercept >= 0 && x_intercept <= 34 * 20 && y_intercept >= 0 && y_intercept <= 14 * 20)

	{
		if (is_wall(x_intercept, y_intercept, data->scale, map->map_array))
		{
			fill(data, 0xF3DE2C);
			horizontalwallhit_x = x_intercept;
			horizontalwallhit_y = y_intercept;
			// draw_line(data, map->player.x, map->player.y, x_intercept, y_intercept);
			break;
		}
		else
		{
			x_intercept += x_step;
			y_intercept += y_step;
		}
	}
	y_intercept = floor(map->player.y / data->scale) * data->scale;
	if (is_ray_facing_down)
		y_intercept += data->scale;
	x_intercept = map->player.x + (y_intercept - map->player.y) / tan(angle);
	y_step = data->scale;
	if (!is_ray_facing_down)
		y_step *= -1;

	x_step = y_step / tan(angle);
	if (!is_ray_facing_right && x_step > 0)
		x_step *= -1;
	else if (is_ray_facing_right && x_step < 0)
		x_step *= -1;

	if (!is_ray_facing_down)
		y_intercept--;
	while (x_intercept >= 0 && x_intercept <= 34 * 20 && y_intercept >= 0 && y_intercept <= 14 * 20)

	{
		if (is_wall(x_intercept, y_intercept, data->scale, map->map_array))
		{
			fill(data, 0xF3DE2C);
			verticalowallhit_x = x_intercept;
			verticalwallhit_y = y_intercept;
			// draw_line(data, map->player.x, map->player.y, x_intercept, y_intercept);
			break;
		}
		else
		{
			x_intercept += x_step;
			y_intercept += y_step;
		}
	}
}

float normalize_angle(float angle)
{
	angle = fmodf(angle, (2.0f * (float)M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return angle;
}

void draw_rays(t_data *data, t_ray *ray, t_map *map)
{
	float move_angle;

	move_angle = map->player.rotation_angle - (ray->fov_angle / 2);

	int i = 0;
	while (i < ray->num_rays)
	{
		move_angle = normalize_angle(move_angle);
		cast_ray(data, ray, map, move_angle);
		// move_angle += ray->fov_angle / (34 * 20);
		i++;
	}
}
