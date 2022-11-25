/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_horizontal_coords.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:10:09 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/22 16:27:07 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int	set_horizontal_coords(t_vector2 *step, t_vector2 *intercept, \
	t_map *map, float angle)
{
	int	is_ray_facing_down;
	int	is_ray_facing_right;

	is_ray_facing_down = (angle > 0.0f && angle < M_PI);
	is_ray_facing_right = (angle > 3.0f * M_PI_2 || angle < M_PI_2);
	intercept->y = floor(map->player.y / map->scale) * map->scale;
	if (is_ray_facing_down)
		intercept->y += map->scale;
	intercept->x = map->player.x + (intercept->y - map->player.y) / tan(angle);
	step->y = map->scale;
	if (!is_ray_facing_down)
		step->y *= -1;
	step->x = step->y / tan(angle);
	if (!is_ray_facing_right && step->x > 0)
		step->x *= -1;
	else if (is_ray_facing_right && step->x < 0)
		step->x *= -1;
	if (!is_ray_facing_down)
		return (1);
	return (0);
}
