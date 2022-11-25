/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:15:31 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/25 21:02:56 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <math.h>

typedef struct s_player
{
	float	x;
	float	y;
	float	rotation_angle;
	float	rotation_speed;
	int		turn_direction;
	int		walk_direction;
	int		side_direction;
	int		move_speed;
}			t_player;

void	player_init(t_player *player, char oriontation);

#endif
