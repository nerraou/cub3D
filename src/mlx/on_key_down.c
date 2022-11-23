/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:32:40 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/23 09:41:01 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int	on_key_down(int keycode, t_event_data *e)
{
	if (keycode == ESC_KEY)
		(void)esc_hook(e->data);
	else if (keycode == UP_ARROW_KEY || keycode == W_KEY)
		e->map->player.walk_direction = 1;
	else if (keycode == DOWN_ARROW_KEY || keycode == S_KEY)
		e->map->player.walk_direction = -1;
	else if (keycode == RIGHT_ARROW_KEY || keycode == D_KEY)
		e->map->player.turn_direction = 1;
	else if (keycode == LEFT_ARROW_KEY || keycode == A_KEY)
		e->map->player.turn_direction = -1;
	return (0);
}
