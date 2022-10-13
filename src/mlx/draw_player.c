/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:49:26 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/12 19:23:55 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void draw_player(t_data *data, const t_player *player)
{
	int endX;
	int endY;

	fill(data, 0xFFAA00);
	draw_rect(data, player->x * data->scale, player->y * data->scale, 10, 10);
	endX = player->x * data->scale + cos(player->rotation_angle) * 30 + 5;
	endY = player->y * data->scale + sin(player->rotation_angle) * 30 + 5;
	draw_line(data, player->x * data->scale + 5, player->y * data->scale + 5, endX, endY);
}
