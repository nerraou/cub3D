/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:36:43 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/21 22:35:39 by ybahlaou         ###   ########.fr       */
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

static void cast_minimap_ray(t_data *data, t_map *map, const t_minimap *mmap, float angle)
{
	t_vector2 horizontalwallhit;
	t_vector2 verticalwallhit;
	t_vector2 find_wall_hit;
	t_vector2 dist;
	int in;

	dist.x = INT_MAX;
	dist.y = INT_MAX;
	find_wall_hit.x = horizontal_wall_intercept(map, &horizontalwallhit, angle, &in);
	find_wall_hit.y = vertical_wall_intercept(map, &verticalwallhit, angle, &in);
	if (find_wall_hit.x == 1)
		dist.x = distance(map->player.x, map->player.y, horizontalwallhit.x, horizontalwallhit.y);
	if (find_wall_hit.y == 1)
		dist.y = distance(map->player.x, map->player.y, verticalwallhit.x, verticalwallhit.y);
	horizontalwallhit.x = rescale(horizontalwallhit.x, map->scale, mmap->scale);
	horizontalwallhit.y = rescale(horizontalwallhit.y, map->scale, mmap->scale);
	verticalwallhit.x = rescale(verticalwallhit.x, map->scale, mmap->scale);
	verticalwallhit.y = rescale(verticalwallhit.y, map->scale, mmap->scale);
	if (dist.x < dist.y)
		draw_line(data, mmap->player.x, mmap->player.y, horizontalwallhit.x + mmap->x, horizontalwallhit.y + mmap->y);
	else
		draw_line(data, mmap->player.x, mmap->player.y, verticalwallhit.x + mmap->x, verticalwallhit.y + mmap->y);
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

	mmap->player.x = rescale(map->player.x, map->scale, mmap->scale) + mmap->x;
	mmap->player.y = rescale(map->player.y, map->scale, mmap->scale) + mmap->y;

	y = 0;
	while (map->map_array[y] != NULL)
	{
		x = 0;
		while (map->map_array[y][x])
		{
			fill(data, get_color(map->map_array[y][x]));
			if (map->map_array[y][x] != ' ')
				draw_rect(data, x * mmap->scale + mmap->x, y * mmap->scale + mmap->y, mmap->scale, mmap->scale);
			x++;
		}
		y++;
	}
	draw_player(data, &mmap->player);
	fill(data, 0xff634F);
	draw_rays(data, map->ray, map);
}
