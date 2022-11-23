/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_mouse_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:24:26 by ybahlaou          #+#    #+#             */
/*   Updated: 2022/11/23 09:24:27 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int	on_mouse_move(int x, int y, t_event_data *e)
{
	t_player	*p;
	int			turn_direction;
	(void)y;

	p = &e->map->player;
	if (x > e->mouse.x)
		turn_direction = 1;
	else if (x < e->mouse.x)
		turn_direction = -1;
	else
		turn_direction = 0;
	p->rotation_angle += turn_direction * p->rotation_speed;
	e->mouse.x = x;
	e->mouse.y = y;
	return (0);
}
