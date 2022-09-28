/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:24:35 by nerraou           #+#    #+#             */
/*   Updated: 2022/09/28 17:14:08 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void set_map_textures(char *line, t_map *map)
{
	if (line[0] == 'N' && line[1] == 'O')
		set_north_texture(line, map);
	else if (line[0] == 'S' && line[1] == 'O')
		set_south_texture(line, map);
	else if (line[0] == 'W' && line[1] == 'E')
		set_west_texture(line, map);
	else if (line[0] == 'E' && line[1] == 'A')
		set_east_texture(line, map);
}
