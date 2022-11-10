/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vertical_coords.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:18:14 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/10 18:11:51 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int set_vertical_coords(t_vector2 *step, t_vector2 *intercept, t_map *map, float angle)
{
	int is_ray_facing_down;
	int is_ray_facing_right;

	is_ray_facing_down = angle > 0.0f && angle < (float)M_PI;
	is_ray_facing_right = angle > 3.0f * (float)M_PI_2 || angle < (float)M_PI_2;
	intercept->x = floor(map->player.x / map->scale) * map->scale;
	if (is_ray_facing_right)
		intercept->x += map->scale;
	intercept->y = map->player.y + (intercept->x - map->player.x) * tan(angle);
	step->x = map->scale;
	if (!is_ray_facing_right)
		step->x *= -1;
	step->y = step->x * tan(angle);
	if (!is_ray_facing_down && step->y > 0)
		step->y *= -1;
	else if (is_ray_facing_down && step->y < 0)
		step->y *= -1;
	if (!is_ray_facing_right)
		return 1;
	return 0;
}