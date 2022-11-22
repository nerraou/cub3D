/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:37:40 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/22 16:33:36 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int	update_loop(t_event_data *e)
{
	t_player	*p;
	int			move_by;
	float		end_x;
	float		end_y;

	p = &e->map->player;
	p->rotation_angle += p->turn_direction * p->rotation_speed;
	move_by = p->walk_direction * p->move_speed;
	end_x = p->x + cos(p->rotation_angle) * move_by;
	end_y = p->y + sin(p->rotation_angle) * move_by;
	if (!is_wall(end_x, end_y, e->data->scale, e->map->map_array))
	{
		p->x = end_x;
		p->y = end_y;
	}
	draw_walls(e->data, e->ray, e->map);
	draw_minimap(e->data, e->map, &e->map->minimap);
	mlx_put_image_to_window(e->data->mlx, e->data->mlx_win, e->data->img, 0, 0);
	return (0);
}
