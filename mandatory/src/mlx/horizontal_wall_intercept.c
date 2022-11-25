/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_wall_intercept.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:16:30 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/25 13:28:44 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int	horizontal_wall_intercept(t_map *map, t_vector2 *intercept, float angle)
{
	t_vector2	step;
	int			heigth;
	int			width;
	int			in;

	in = set_horizontal_coords(&step, intercept, map, angle);
	heigth = map->height * map->scale;
	width = map->width * map->scale;
	while (intercept->x >= 0 && intercept->x <= width && intercept->y >= 0
		&& intercept->y <= heigth)
	{
		if (is_wall(intercept->x, intercept->y - in, map->scale, map))
			return (1);
		else
		{
			intercept->x += step.x;
			intercept->y += step.y;
		}
	}
	return (0);
}
