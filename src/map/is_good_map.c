/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_good_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:08:01 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/22 23:16:26 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static char	**copy_map_array(int *widths, int height)
{
	char	**copy;
	int		i;

	copy = (char **)malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = (char *)malloc(sizeof(char) * (widths[i] + 1));
		ft_memset(copy[i], '-', widths[i]);
		copy[i][widths[i]] = '\0';
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	walk(const t_map *map, char **visited, int x, int y)
{
	if (y - 1 < 0 || y + 1 >= map->height || x - 1 < 0 \
		|| x + 1 >= map->widths[y] || \
		x >= map->widths[y - 1] || x >= map->widths[y + 1])
	{
		visited[y][x] = 'b';
		return ;
	}
	if (map->map_array[y - 1][x] == ' ' || map->map_array[y][x + 1] == ' ' ||
		map->map_array[y + 1][x] == ' ' || map->map_array[y][x - 1] == ' ')
	{
		visited[y][x] = 'b';
		return ;
	}
	if (visited[y][x] == '1')
		return ;
	visited[y][x] = '1';
	if (map->map_array[y - 1][x] == '0')
		walk(map, visited, x, y - 1);
	if (map->map_array[y][x + 1] == '0')
		walk(map, visited, x + 1, y);
	if (map->map_array[y + 1][x] == '0')
		walk(map, visited, x, y + 1);
	if (map->map_array[y][x - 1] == '0')
		walk(map, visited, x - 1, y);
}

static int	is_bad_map(char **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (ft_indexof(visited[i], 'b') != -1)
			return (1);
		i++;
	}
	return (0);
}

int	is_good_map(const t_map *map)
{
	char	**visited;
	int		is_good;
	int		y;
	int		x;

	visited = copy_map_array(map->widths, map->height);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->map_array[y][x])
		{
			if (map->map_array[y][x] == '0' && visited[y][x] == '-')
				walk(map, visited, x, y);
			x++;
		}
		y++;
	}
	is_good = !is_bad_map(visited, map->height);
	ft_free_carray(&visited, map->height);
	return (is_good);
}
