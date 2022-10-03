/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_orientation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:58:36 by ybahlaou          #+#    #+#             */
/*   Updated: 2022/09/30 22:03:08 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void set_player_orientation(const char *str, t_map *map)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_indexof("NSEW", str[i]) != -1)
		{
			map->player_orientation = str[i];
			break;
		}
		i++;
	}
}
