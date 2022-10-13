/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_replace_player_position.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:53:32 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/12 18:11:47 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void set_replace_player_position(t_map *data)
{
	int x;
	int y;

	y = 0;
	while (data->map_array[y])
	{
		x = 0;
		while (data->map_array[y][x])
		{
			if (ft_indexof("NEWS", data->map_array[y][x]) != -1)
			{
				data->player_orientation = data->map_array[y][x];
				data->player.x = x;
				data->player.y = y;
				data->map_array[y][x] = '0';
				break;
			}
			x++;
		}
		y++;
	}
}
