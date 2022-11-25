/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:36:43 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/25 16:33:04 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

static int	get_color(char cell_value)
{
	if (cell_value == '1')
		return (0xFFFFFF);
	if (cell_value == 'D')
		return (0x123456);
	return (0x555555);
}

static void	draw_arc(t_data *data, t_ray *ray, t_map *map)
{
	float		move_angle;
	int			i;
	t_vector2	start;
	t_vector2	end;
	t_player	*player;

	fill(data, 0xff634F);
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

static int	is_out_of_boundaries(int x, int y, t_map *map)
{
	if (x < 0 || y < 0 || y >= map->height || x >= map->widths[y])
		return (1);
	return (0);
}

static void	set_player_coords(t_player *player, t_map *map,
	int start_x, int start_y)
{
	t_minimap	*mmap;

	mmap = &map->minimap;
	player->x = (map->player.x / map->scale - start_x) * mmap->scale;
	player->y = (map->player.y / map->scale - start_y) * mmap->scale;
}

void	draw_minimap(t_data *data, t_map *map, t_minimap *mmap)
{
	const int	s_x = map->player.x / map->scale - 10;
	const int	s_y = map->player.y / map->scale - 10;
	int			dx;
	int			dy;
	const int	size = 20;

	set_player_coords(&mmap->player, map, s_x, s_y);
	dy = 0;
	while (dy < size)
	{
		dx = 0;
		while (dx < size)
		{
			fill(data, 0x0);
			if (!is_out_of_boundaries(dx + s_x, dy + s_y, map))
				fill(data, get_color(map->map_array[dy + s_y][dx + s_x]));
			draw_rect(data, vector2_create(dx * mmap->scale, dy * mmap->scale),
				mmap->scale, mmap->scale);
			dx++;
		}
		dy++;
	}
	draw_arc(data, map->ray, map);
	draw_player(data, &mmap->player);
}
