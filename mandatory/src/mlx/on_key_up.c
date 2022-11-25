/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:35:50 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/25 21:06:38 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int	on_key_up(int keycode, t_event_data *e)
{
	if (keycode == W_KEY || keycode == S_KEY)
		e->map->player.walk_direction = 0;
	else if (keycode == D_KEY || keycode == A_KEY)
		e->map->player.side_direction = 0;
	else if (keycode == RIGHT_ARROW_KEY || keycode == LEFT_ARROW_KEY)
		e->map->player.turn_direction = 0;
	return (0);
}
