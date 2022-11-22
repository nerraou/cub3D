/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_wall_intercept.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:21:17 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/22 16:36:10 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int	vertical_wall_intercept(t_map *map, t_vector2 *intercept, \
	float angle, int *in)
{
	t_vector2	step;
	int			width;
	int			heigth;

	*in = set_vertical_coords(&step, intercept, map, angle);
	heigth = map->height * map->scale;
	width = map->width * map->scale;
	while (intercept->x >= 0 && intercept->x <= width \
	&& intercept->y >= 0 && intercept->y <= heigth)
	{
		if (is_door(map, intercept->x - *in, intercept->y))
			return (1);
		if (is_wall(intercept->x - *in, intercept->y, \
			map->scale, map->map_array))
			return (1);
		else
		{
			intercept->x += step.x;
			intercept->y += step.y;
		}
	}
	return (0);
}
