/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_replace_player_position.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:53:32 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/22 10:53:25 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	set_replace_player_position(t_map *data, int scale)
{
	int	x;
	int	y;

	y = 0;
	while (data->map_array[y])
	{
		x = 0;
		while (data->map_array[y][x])
		{
			if (ft_indexof("NEWS", data->map_array[y][x]) != -1)
			{
				data->player_orientation = data->map_array[y][x];
				data->player.x = x * scale;
				data->player.y = y * scale;
				data->map_array[y][x] = '0';
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
