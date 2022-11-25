/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:49:26 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/24 09:07:55 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void	draw_player(t_data *data, const t_player *player)
{
	t_vector2	player_pos;

	fill(data, 0xFFAA00);
	player_pos.x = player->x - 2;
	player_pos.y = player->y - 2;
	draw_rect(data, player_pos, 4, 4);
}
