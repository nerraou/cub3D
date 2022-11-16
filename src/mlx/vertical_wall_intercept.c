/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_wall_intercept.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:21:17 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/16 16:44:26 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int vertical_wall_intercept(t_data *data, t_map *map, t_vector2 *intercept, float angle)
{
	t_vector2 step;
	int in;
	in = set_vertical_coords(&step, intercept, map, angle);
	while (intercept->x >= 0 && intercept->x <= 34 * map->scale && intercept->y >= 0 && intercept->y <= 14 * map->scale)
	{
		if (is_wall(intercept->x - in, intercept->y, data->scale, map->map_array))
		{
			fill(data, 0xF3DE2C);
			return 1;
		}
		else
		{
			intercept->x += step.x;
			intercept->y += step.y;
		}
	}
	return 0;
}