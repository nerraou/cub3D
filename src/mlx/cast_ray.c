/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:22:01 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/21 15:33:31 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

float cast_ray(t_map *map, float angle, int *horizontal, float *point)
{
	t_vector2 horizontalwallhit;
	t_vector2 verticalwallhit;
	t_vector2 find_wall_hit;
	t_vector2 dist;
	int h_in;
	int v_in;

	dist.x = INT_MAX;
	dist.y = INT_MAX;
	find_wall_hit.x = horizontal_wall_intercept(map, &horizontalwallhit, angle, &h_in);
	find_wall_hit.y = vertical_wall_intercept(map, &verticalwallhit, angle, &v_in);
	if (find_wall_hit.x == 1)
		dist.x = distance(map->player.x, map->player.y, horizontalwallhit.x, horizontalwallhit.y);
	if (find_wall_hit.y == 1)
		dist.y = distance(map->player.x, map->player.y, verticalwallhit.x, verticalwallhit.y);
	if (dist.x < dist.y)
	{
		map->is_door = is_door(map, horizontalwallhit.x, horizontalwallhit.y - h_in);
		*horizontal = 1;
		*point = horizontalwallhit.x;
		return (dist.x);
	}
	else
	{
		map->is_door = is_door(map, verticalwallhit.x - v_in, verticalwallhit.y);
		*horizontal = 0;
		*point = verticalwallhit.y;
		return (dist.y);
	}
}