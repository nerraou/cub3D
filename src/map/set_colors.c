/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:24:04 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/23 23:13:36 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	set_colors(const char *line, t_map *map)
{
	if (ft_strncmp(line, "F ", 2) == 0 && is_string_rgb(line + 2))
	{
		if (map->floor_color != -1)
			return (1);
		map->floor_color = rgb_from_string(line + 1);
		return (0);
	}
	else if (ft_strncmp(line, "C ", 2) == 0 && is_string_rgb(line + 2))
	{
		if (map->ceiling_color != -1)
			return (1);
		map->ceiling_color = rgb_from_string(line + 1);
		return (0);
	}
	return (1);
}
