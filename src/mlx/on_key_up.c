/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:35:50 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/17 10:36:19 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int on_key_up(int keycode, t_event_data *e)
{
	if (keycode == UP_ARROW_KEY || keycode == DOWN_ARROW_KEY)
		e->map->player.walk_direction = 0;
	else if (keycode == RIGHT_ARROW_KEY || keycode == LEFT_ARROW_KEY)
		e->map->player.turn_direction = 0;
	return (0);
}
