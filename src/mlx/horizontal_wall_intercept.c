/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_wall_intercept.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:16:30 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/01 16:17:40 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int horizontal_wall_intercept(t_data *data, t_map *map, t_vector2 *intercept, float angle)
{
	t_vector2 step;

	set_horizontal_coords(&step, intercept, map, angle);
	while (intercept->x >= 0 && intercept->x <= 34 * 20 && intercept->y >= 0 && intercept->y <= 14 * 20)
	{
		if (is_wall(intercept->x, intercept->y, map->scale, map->map_array))
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