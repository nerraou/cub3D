/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:36:43 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/24 00:00:06 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

static int	get_color(char cell_value)
{
	if (cell_value == '1')
		return (0xFFFFFF);
	if (cell_value == 'D')
		return (0x123456);
	else if (cell_value == '0')
		return (0x555555);
	return (0xFFAA00);
}

float	rescale(float value, int original_scale, int new_scale)
{
	return (value / original_scale * new_scale);
}

static void	cast_minimap_ray(t_data *data, t_map *map,
	const t_minimap *mmap, float angle)
{
	t_vector2	hwallhit;
	t_vector2	vwallhit;
	t_tuple		find_wall_hit;
	t_vector2	dist;
	int			in;

	dist.x = INT_MAX;
	dist.y = INT_MAX;
	find_wall_hit.var1 = horizontal_wall_intercept(map, &hwallhit, angle, &in);
	find_wall_hit.var2 = vertical_wall_intercept(map, &vwallhit, angle, &in);
	if (find_wall_hit.var1 == 1)
		dist.x = distance(map->player.x, map->player.y, hwallhit.x, hwallhit.y);
	if (find_wall_hit.var2 == 1)
		dist.y = distance(map->player.x, map->player.y, vwallhit.x, vwallhit.y);
	hwallhit.x = rescale(hwallhit.x, map->scale, mmap->scale);
	hwallhit.y = rescale(hwallhit.y, map->scale, mmap->scale);
	vwallhit.x = rescale(vwallhit.x, map->scale, mmap->scale);
	vwallhit.y = rescale(vwallhit.y, map->scale, mmap->scale);
	if (dist.x < dist.y)
		return draw_line(data, vector2_create(mmap->player.x, mmap->player.y),
			vector2_create(hwallhit.x + mmap->x, hwallhit.y + mmap->y));
	draw_line(data, vector2_create(mmap->player.x, mmap->player.y),
		vector2_create(vwallhit.x + mmap->x, vwallhit.y + mmap->y));
}

static void draw_rays(t_data *data, t_ray *ray, t_map *map)
{
	float		move_angle;

	move_angle = map->player.rotation_angle - (ray->fov_angle / 2);

	int i = 0;
	while (i < ray->num_rays)
	{
		move_angle = normalize_angle(move_angle);
		cast_minimap_ray(data, map, &map->minimap, move_angle);
		move_angle += ray->fov_angle / (map->width * map->scale);
		i++;
	}
}

void	draw_minimap(t_data *data, t_map *map, t_minimap *mmap)
{
	int			x;
	int			y;
	t_vector2	start;

	mmap->player.x = rescale(map->player.x, map->scale, mmap->scale) + mmap->x;
	mmap->player.y = rescale(map->player.y, map->scale, mmap->scale) + mmap->y;

	y = 0;
	while (map->map_array[y] != NULL)
	{
		x = 0;
		while (map->map_array[y][x])
		{
			fill(data, get_color(map->map_array[y][x]));
			start.x = x * mmap->scale + mmap->x;
			start.y = y * mmap->scale + mmap->y;
			if (map->map_array[y][x] != ' ')
				draw_rect(data, start, mmap->scale, mmap->scale);
			x++;
		}
		y++;
	}
	draw_player(data, &mmap->player);
	fill(data, 0xff634F);
	draw_rays(data, map->ray, map);
}
