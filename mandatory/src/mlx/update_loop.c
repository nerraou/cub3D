/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:37:40 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/25 13:35:58 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int	update_loop(t_event_data *e)
{
	t_player	*p;
	t_vector2	end;
	t_vector2	max_end;
	int			move_by;

	p = &e->map->player;
	p->rotation_angle += p->turn_direction * p->rotation_speed;
	move_by = p->walk_direction * p->move_speed;
	end.x = p->x + cos(p->rotation_angle) * move_by;
	end.y = p->y + sin(p->rotation_angle) * move_by;
	move_by = p->walk_direction * 21;
	max_end.x = p->x + cos(p->rotation_angle) * move_by;
	max_end.y = p->y + sin(p->rotation_angle) * move_by;
	if (!is_wall(end.x, max_end.y, e->data->scale, e->map) && \
		!is_wall(max_end.x, end.y, e->data->scale, e->map) && \
		!is_wall(end.x, end.y, e->data->scale, e->map) && \
		!is_wall(max_end.x, max_end.y, e->data->scale, e->map))
	{
		p->x = end.x;
		p->y = end.y;
	}
	draw_walls(e->data, e->ray, e->map);
	mlx_put_image_to_window(e->data->mlx, e->data->mlx_win, e->data->img, 0, 0);
	return (0);
}
