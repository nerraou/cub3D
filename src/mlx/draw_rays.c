/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:47:05 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/30 11:25:53 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"
#include "limits.h"

float distance(float start_x, float start_y, float end_x, float end_y)
{
	return sqrtf(powf(end_x - start_x, 2.0f) + powf(end_y - start_y, 2.0f));
}

void cast_ray(t_data *data, t_ray *ray, t_map *map, float angle)
{
	(void)ray;
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
	int find_horizontal;
	int find_vertical;

	find_horizontal = 0;
	find_vertical = 0;

	float horizont_dist;
	float vertical_dist;

	horizont_dist = INT_MAX;
	vertical_dist = INT_MAX;

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
			find_horizontal = 1;
			// draw_line(data, map->player.x, map->player.y, x_intercept, y_intercept);
			break;
		}
		else
		{
			x_intercept += x_step;
			y_intercept += y_step;
		}
	}
	x_intercept = floor(map->player.x / data->scale) * data->scale;
	if (is_ray_facing_right)
		x_intercept += data->scale;
	y_intercept = map->player.y + (x_intercept - map->player.x) * tan(angle);

	x_step = data->scale;
	if (!is_ray_facing_right)
		x_step *= -1;

	y_step = x_step * tan(angle);
	if (!is_ray_facing_down && y_step > 0)
		y_step *= -1;
	else if (is_ray_facing_down && y_step < 0)
		y_step *= -1;

	if (!is_ray_facing_right)
		x_intercept--;
	while (x_intercept >= 0 && x_intercept <= 34 * 20 && y_intercept >= 0 && y_intercept <= 14 * 20)

	{
		if (is_wall(x_intercept, y_intercept, data->scale, map->map_array))
		{
			fill(data, 0xF3DE2C);
			verticalowallhit_x = x_intercept;
			verticalwallhit_y = y_intercept;
			find_vertical = 1;
			break;
		}
		else
		{
			x_intercept += x_step;
			y_intercept += y_step;
		}
	}
	if (find_horizontal == 1)
	{
		horizont_dist = distance(map->player.x, map->player.y, horizontalwallhit_x, horizontalwallhit_y);
	}
	if (find_vertical == 1)
	{
		vertical_dist = distance(map->player.x, map->player.y, verticalowallhit_x, verticalwallhit_y);
	}
	if (horizont_dist < vertical_dist)
		draw_line(data, map->player.x, map->player.y, horizontalwallhit_x, horizontalwallhit_y);
	else
		draw_line(data, map->player.x, map->player.y, verticalowallhit_x, verticalwallhit_y);
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
		move_angle += ray->fov_angle / (34 * 20);
		i++;
	}
}
