/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:49:26 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/21 13:17:10 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void draw_player(t_data *data, const t_player *player)
{
	int endX;
	int endY;

	fill(data, 0xFFAA00);
	draw_circle(data, player->x, player->y, 3);
	endX = player->x + cos(player->rotation_angle) * 15;
	endY = player->y + sin(player->rotation_angle) * 15;
	draw_line(data, player->x, player->y, endX, endY);
}
