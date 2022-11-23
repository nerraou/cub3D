/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_replace_player_position.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:53:32 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/23 23:57:45 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	set_replace_player_position(t_map *data, int scale)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (data->map_array[y])
	{
		x = 0;
		while (data->map_array[y][x])
		{
			if (ft_indexof("NEWS", data->map_array[y][x]) != -1)
			{
				data->player_orientation = data->map_array[y][x];
				data->player.x = x * scale + scale / 2;
				data->player.y = y * scale + scale / 2;
				data->map_array[y][x] = '0';
				count++;
			}
			x++;
		}
		y++;
	}
	return (count != 1);
}
