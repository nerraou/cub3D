/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:47:05 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/22 14:49:17 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void draw_rays(t_data *data, t_ray *ray, t_player *player)
{
	int i;
	float move_angle;
	float start_angle;

	start_angle =
		move_angle = ray->fov_angle / data->width;
	i = 0;
	while (i < ray->num_rays)
	{
		draw_line(data, player->x, player->y, endX, endY);
		i++;
	}
}