/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:49:26 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/15 17:34:35 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void draw_player(t_data *data, const t_player *player)
{
	int endX;
	int endY;

	fill(data, 0xFFAA00);
	draw_circle(data, player->x, player->y, 5);
	endX = player->x + cos(player->rotation_angle) * 30;
	endY = player->y + sin(player->rotation_angle) * 30;
	draw_line(data, player->x, player->y, endX, endY);
}
