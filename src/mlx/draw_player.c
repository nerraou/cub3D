/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:49:26 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/22 15:57:53 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void	draw_player(t_data *data, const t_player *player)
{
	fill(data, 0xFFAA00);
	draw_circle(data, player->x, player->y, 3);
}
