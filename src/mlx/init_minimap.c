/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:57:50 by ybahlaou          #+#    #+#             */
/*   Updated: 2022/11/24 14:39:38 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

static int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	init_minimap(t_data *data, t_map *map)
{
	t_minimap	*minimap;

	minimap = &map->minimap;
	minimap->scale = min(data->width / map->width, data->height / map->height);
	minimap->scale = min(minimap->scale, 10);
	minimap->x = data->width - map->width * minimap->scale;
	minimap->y = data->height - map->height * minimap->scale;
	ft_memcpy(&minimap->player, &map->player, sizeof(t_player));
}
