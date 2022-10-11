/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:43:03 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/11 18:05:09 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void player_init(t_player *player)
{

	player->turn_direction = 0;
	player->walk_direction = 0;
	player->move_speed = 3;
	player->rotation_angle = (PI / 2);
	player->rotation_speed = 3 * (PI / 180);
}