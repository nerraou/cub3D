/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:24:04 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/19 15:33:21 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	set_colors(const char *line, t_map *map)
{
	if (!is_string_rgb(line + 2))
		return (1);
	if (line[0] == 'F')
		map->floor_color = rgb_from_string(line + 1);
	else if (line[0] == 'C')
		map->ceiling_color = rgb_from_string(line + 1);
	return (0);
}
