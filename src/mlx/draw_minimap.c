/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:36:43 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/21 19:20:43 by nerraou          ###   ########.fr       */
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

static void init_minimap_player(t_player *dest, const t_map *map, int mmap_scale, const t_vector2 *start)
{
	ft_memcpy(dest, &map->player, sizeof(t_player));
	dest->x = dest->x / map->scale * mmap_scale + start->x;
	dest->y = dest->y / map->scale * mmap_scale + start->y;
}

static void cast_minimap_ray(t_data *data, t_map *map, float angle)
{
	t_vector2 horizontalwallhit;
	t_vector2 verticalwallhit;
	t_vector2 find_wall_hit;
	t_vector2 dist;
	int in;

	t_player	player;
	int			mmap_scale;
	t_vector2	start;

	mmap_scale = map->scale * 0.25f;
	start.x = data->width - map->width * mmap_scale;
	start.y = data->height - map->height * mmap_scale;
	init_minimap_player(&player, map, mmap_scale, &start);

	dist.x = INT_MAX;
	dist.y = INT_MAX;
	find_wall_hit.x = horizontal_wall_intercept(map, &horizontalwallhit, angle, &in);
	find_wall_hit.y = vertical_wall_intercept(map, &verticalwallhit, angle, &in);
	if (find_wall_hit.x == 1)
		dist.x = distance(map->player.x, map->player.y, horizontalwallhit.x, horizontalwallhit.y);
	if (find_wall_hit.y == 1)
		dist.y = distance(map->player.x, map->player.y, verticalwallhit.x, verticalwallhit.y);
	if (dist.x < dist.y)
	{
		// draw from horizontalwallhit
		draw_line(data, player.x, player.y, horizontalwallhit.x / map->scale * mmap_scale + start.x, horizontalwallhit.y / map->scale * mmap_scale + start.y);
	}
	else
	{
		// draw from verticalwallhit
		draw_line(data, player.x, player.y, verticalwallhit.x / map->scale * mmap_scale + start.x, verticalwallhit.y / map->scale * mmap_scale + start.y);
	}
}


static void draw_rays(t_data *data, t_ray *ray, t_map *map, int mmap_scale)
{
	float		move_angle;
	(void)mmap_scale;

	move_angle = map->player.rotation_angle - (ray->fov_angle / 2);

	int i = 0;
	while (i < ray->num_rays)
	{
		move_angle = normalize_angle(move_angle);
		cast_minimap_ray(data, map, move_angle);
		move_angle += ray->fov_angle / (map->width * map->scale);
		i++;
	}
}

void	draw_minimap(t_data *data, t_map *map)
{
	int			x;
	int			y;
	t_player	player;
	int			mmap_scale;
	t_vector2	start;

	mmap_scale = map->scale * 0.25f;
	start.x = data->width - map->width * mmap_scale;
	start.y = data->height - map->height * mmap_scale;
	init_minimap_player(&player, map, mmap_scale, &start);
	y = 0;
	while (map->map_array[y] != NULL)
	{
		x = 0;
		while (map->map_array[y][x])
		{
			fill(data, get_color(map->map_array[y][x]));
			if (map->map_array[y][x] != ' ')
				draw_rect(data, x * mmap_scale + start.x, y * mmap_scale + start.y, mmap_scale, mmap_scale);
			x++;
		}
		y++;
	}
	draw_player(data, &player);
	draw_rays(data, map->ray, map, mmap_scale);
}
