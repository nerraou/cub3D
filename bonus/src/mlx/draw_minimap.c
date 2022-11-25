/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:36:43 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/25 16:12:59 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

 int	get_color(char cell_value)
{
	if (cell_value == '1')
		return (0xFFFFFF);
	if (cell_value == 'D')
		return (0x123456);
	return (0x555555);
}

 void	draw_arc(t_data *data, t_ray *ray, t_map *map)
{
	float		move_angle;
	int			i;
	t_vector2	start;
	t_vector2	end;
	t_player	*player;

	player = &map->minimap.player;
	vector2_set(&start, player->x, player->y);
	move_angle = map->player.rotation_angle - (ray->fov_angle / 2);
	i = 0;
	while (i < ray->num_rays)
	{
		move_angle = normalize_angle(move_angle);
		end.x = player->x + cos(move_angle) * 15;
		end.y = player->y + sin(move_angle) * 15;
		draw_line(data, start, end);
		move_angle += ray->fov_angle / data->width;
		i++;
	}
}

void	draw_minimap(t_data *data, t_map *map, t_minimap *mmap)
{
	int			start_x;
	int			start_y;
	int			dx;
	int			dy;
	const int	size = 20;

	start_x = map->player.x / map->scale - 10;
	start_y = map->player.y / map->scale - 10;
	mmap->player.x = (map->player.x / map->scale - start_x) * mmap->scale;
	mmap->player.y = (map->player.y / map->scale - start_y) * mmap->scale;
	dy = 0;
	while (dy < size)
	{
		dx = 0;
		while (dx < size)
		{
			if (dx + start_x < 0 || dy + start_y < 0 || dy + start_y >= map->height || dx + start_x >= map->widths[dy + start_y])
			{
				fill(data, 0x0);
				draw_rect(data, vector2_create(dx * mmap->scale, dy * mmap->scale), mmap->scale, mmap->scale);
			}
			else
			{
				fill(data, get_color(map->map_array[dy + start_y][dx + start_x]));
				draw_rect(data, vector2_create(dx * mmap->scale, dy * mmap->scale), mmap->scale, mmap->scale);
			}
			dx++;
		}
		dy++;
	}
	fill(data, 0xff634F);
	draw_arc(data, map->ray, map);
	draw_player(data, &mmap->player);
}
