/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:37:40 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/22 09:57:21 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int update_loop(t_event_data *e)
{
	t_player *p;
	int move_by;
	float endX;
	float endY;
	p = &e->map->player;

	p->rotation_angle += p->turn_direction * p->rotation_speed;
	move_by = p->walk_direction * p->move_speed;
	endX = p->x + cos(p->rotation_angle) * move_by;
	endY = p->y + sin(p->rotation_angle) * move_by;

	if (!is_wall(endX, endY, e->data->scale, e->map->map_array))
	{
		p->x = endX;
		p->y = endY;
	}
	draw_walls(e->data, e->ray, e->map);
	draw_minimap(e->data, e->map, &e->map->minimap);
	mlx_put_image_to_window(e->data->mlx, e->data->mlx_win, e->data->img, 0, 0);
	return (0);
}
