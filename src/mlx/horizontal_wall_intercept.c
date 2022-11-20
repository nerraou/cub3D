/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_wall_intercept.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:16:30 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/20 19:09:40 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int horizontal_wall_intercept(t_map *map, t_vector2 *intercept, float angle)
{
	t_vector2 step;
	int in;
	int heigth;
	int width;

	in = set_horizontal_coords(&step, intercept, map, angle);
	heigth = map->height * map->scale;
	width = map->width * map->scale;
	while (intercept->x >= 0 && intercept->x <= width && intercept->y >= 0 && intercept->y <= heigth)
	{
		if (is_door(map, intercept->x, intercept->y))
			return 1;
		if (is_wall(intercept->x, intercept->y - in, map->scale, map->map_array))
			return 1;
		else
		{
			intercept->x += step.x;
			intercept->y += step.y;
		}
	}
	return 0;
}