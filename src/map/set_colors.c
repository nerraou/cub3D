/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:24:04 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/10 23:16:51 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int set_colors(const char *line, t_map *map)
{
	if (line[0] == 'F')
		return set_floor_color(line, map);
	else if (line[0] == 'C')
		return set_ceiling_color(line, map);
	return (0);
}
