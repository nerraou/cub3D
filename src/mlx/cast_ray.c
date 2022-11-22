/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:22:01 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/22 15:06:04 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

static t_vector2	get_distance(t_map *map, t_tuple const *wall_hit, \
t_vector2 const *horizontalhit, t_vector2 const *verticalhit)
{
	t_vector2	dist;

	dist.x = INT_MAX;
	dist.y = INT_MAX;
	if (wall_hit->var1 == 1)
		dist.x = distance(map->player.x, map->player.y, horizontalhit->x, \
		horizontalhit->y);
	if (wall_hit->var2 == 1)
		dist.y = distance(map->player.x, map->player.y, verticalhit->x, \
		verticalhit->y);
	return (dist);
}

float	cast_ray(t_map *map, float angle, int *horizontal, float *point)
{
	t_vector2	h_wallhit;
	t_vector2	v_wallhit;
	t_vector2	dist;
	t_tuple		find_wall_hit;
	t_tuple		in;

	find_wall_hit.var1 = horizontal_wall_intercept(map, &h_wallhit, angle, \
	&in.var1);
	find_wall_hit.var2 = vertical_wall_intercept(map, &v_wallhit, angle, \
	&in.var2);
	dist = get_distance(map, &find_wall_hit, &h_wallhit, &v_wallhit);
	if (dist.x < dist.y)
	{
		map->is_door = is_door(map, h_wallhit.x, h_wallhit.y - in.var1);
		*horizontal = 1;
		*point = h_wallhit.x;
		return (dist.x);
	}
	else
	{
		map->is_door = is_door(map, v_wallhit.x - in.var2, v_wallhit.y);
		*horizontal = 0;
		*point = v_wallhit.y;
		return (dist.y);
	}
}
