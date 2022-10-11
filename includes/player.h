/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:15:31 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/11 17:57:27 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
#define PLAYER_H

#define PI 3.141592653589793238
typedef struct s_player
{
	int x;
	int y;
	int turn_direction;
	int walk_direction;
	float rotation_angle;
	int move_speed;
	float rotation_speed;
} t_player;

#endif