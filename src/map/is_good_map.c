/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_good_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:08:01 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/24 17:59:10 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	is_bad_cell(const t_map *map, int x, int y)
{
	const char	*charset = "01DNEWS";

	if (y - 1 < 0 || y + 1 >= map->height || x - 1 < 0 \
		|| x + 1 >= map->widths[y] || \
		x >= map->widths[y - 1] || x >= map->widths[y + 1])
	{
		return (1);
	}
	if (ft_indexof(charset, map->map_array[y - 1][x]) == -1)
		return (1);
	if (ft_indexof(charset, map->map_array[y + 1][x]) == -1)
		return (1);
	if (ft_indexof(charset, map->map_array[y][x + 1]) == -1)
		return (1);
	if (ft_indexof(charset, map->map_array[y][x - 1]) == -1)
		return (1);
	return (0);
}


static int	is_bad_doors(const t_map *map, int x, int y)
{
	int		can_pass_y;
	int		can_pass_x;
	char	**array;

	array = map->map_array;
	if (x - 1 < 0 || y - 1 < 0
		|| y + 1 >= map->height || x + 1 >= map->widths[y])
		return (1);
	can_pass_y = (array[y - 1][x] == '0' && array[y + 1][x] == '0');
	can_pass_x = (array[y][x - 1] == '0' && array[y][x + 1] == '0');
	return (!(can_pass_x ^ can_pass_y));
}

int	is_good_map(const t_map *map)
{
	int		y;
	int		x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->map_array[y][x])
		{
			if (map->map_array[y][x] == 'D' && is_bad_doors(map, x, y))
				return (perror_and_return("bad map: bad door", 0));
			if (ft_indexof("D0NEWS", map->map_array[y][x]) != -1
				&& is_bad_cell(map, x, y))
				return (perror_and_return("bad map: D0NEWS mustn't be in"
					" the edges or surrounded by space(s)", 0));
			x++;
		}
		y++;
	}
	return (1);
}
