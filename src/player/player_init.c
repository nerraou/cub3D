/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:43:03 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/17 09:08:30 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static float get_rotation_angle(char orientation)
{
	if (orientation == 'N')
		return (M_PI_2 * 3);
	else if (orientation == 'E')
		return (M_PI);
	else if (orientation == 'W')
		return (0);
	else
		return (M_PI_2);
}

void player_init(t_player *player, char orientation)
{
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->move_speed = 1;
	player->rotation_angle = get_rotation_angle(orientation);
	player->rotation_speed = 3 * (M_PI / 180);
}
