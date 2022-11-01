/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 08:16:50 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/31 18:06:00 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void init_map(t_map *map)
{
	ft_memset(map, 0, sizeof(t_map));
	map->ceiling_color = -1;
	map->floor_color = -1;
	map->scale = 20;
}
