/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:32:40 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/25 21:05:25 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int	on_key_down(int keycode, t_event_data *e)
{
	if (keycode == ESC_KEY)
		(void)esc_hook(e->data);
	else if (keycode == W_KEY)
		e->map->player.walk_direction = 1;
	else if (keycode == S_KEY)
		e->map->player.walk_direction = -1;
	else if (keycode == D_KEY)
		e->map->player.side_direction = 1;
	else if (keycode == A_KEY)
		e->map->player.side_direction = -1;
	else if (keycode == RIGHT_ARROW_KEY)
		e->map->player.turn_direction = 1;
	else if (keycode == LEFT_ARROW_KEY)
		e->map->player.turn_direction = -1;
	return (0);
}
