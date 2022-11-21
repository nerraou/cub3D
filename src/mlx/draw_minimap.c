/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:36:43 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/21 15:05:26 by ybahlaou         ###   ########.fr       */
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


static void draw_rays(t_data *data, t_ray *ray, t_map *map, int mmap_scale)
{
	float		move_angle;
	int			horizontal;
	float		hit_point;
	t_vector2	horizontalwallhit;
	t_vector2	verticalowallhit;

	move_angle = map->player.rotation_angle - (ray->fov_angle / 2);

	int i = 0;
	while (i < ray->num_rays)
	{
		float v_dist = vertical_wall_intercept(map, &verticalowallhit, move_angle);
		float h_dist = horizontal_wall_intercept(map, &horizontalwallhit, move_angle);
		move_angle = normalize_angle(move_angle);
		cast_ray(map, move_angle, &horizontal, &hit_point);
		move_angle += ray->fov_angle / (map->width * mmap_scale);
		i++;
		if (h_dist < v_dist)
			draw_line(data, map->player.x, map->player.y, horizontalwallhit.x, horizontalwallhit.y);
		else
			draw_line(data, map->player.x, map->player.y, verticalowallhit.x, verticalowallhit.y);
	}
}


static void init_minimap_player(t_player *dest, const t_map *map, int mmap_scale, const t_vector2 *start)
{
	ft_memcpy(dest, &map->player, sizeof(t_player));
	dest->x = dest->x / map->scale * mmap_scale + start->x;
	dest->y = dest->y / map->scale * mmap_scale + start->y;
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
	draw_rays(data, map->ray, map, mmap_scale);
	draw_player(data, &player);
}
