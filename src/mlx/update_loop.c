/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:37:40 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/17 18:29:02 by nerraou          ###   ########.fr       */
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
	fill(e->data, 0x000000);
	draw_rect(e->data, 0, 0, e->data->width, e->data->height);
	draw_minimap(e->data, e->map->map_array);
	draw_player(e->data, &e->map->player);
	mlx_put_image_to_window(e->data->mlx, e->data->mlx_win, e->data->img, 0, 0);
	return (0);
}
