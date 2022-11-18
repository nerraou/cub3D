/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 08:16:50 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/18 11:34:32 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void init_map(t_map *map)
{
	ft_memset(map, 0, sizeof(t_map));
	map->ceiling_color = -1;
	map->floor_color = -1;
	map->scale = 64;
}
