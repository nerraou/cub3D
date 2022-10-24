/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:47:05 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/24 18:45:53 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void draw_rays(t_data *data, t_ray *ray, t_player *player)
{
	int i;
	float move_angle;
	float endX;
	float endY;

	fill(data, 0xF3DE2C);
	move_angle = player->rotation_angle - (ray->fov_angle / 2);
	i = 0;
	while (i < ray->num_rays)
	{
		endX = player->x + cos(move_angle) * 30;
		endY = player->y + sin(move_angle) * 30;
		draw_line(data, player->x, player->y, endX, endY);
		move_angle += ray->fov_angle / (32 * 20);
		i++;
	}
}
