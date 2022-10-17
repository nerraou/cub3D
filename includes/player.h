/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:15:31 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/15 17:24:08 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
#define PLAYER_H

#include <math.h>

typedef struct s_player
{
	float x;
	float y;
	int turn_direction;
	int walk_direction;
	float rotation_angle;
	int move_speed;
	float rotation_speed;
} t_player;

void player_init(t_player *player, char oriontation);

#endif
