/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:57:50 by ybahlaou          #+#    #+#             */
/*   Updated: 2022/11/22 10:07:05 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void init_minimap(t_data *data, t_map *map)
{
	t_minimap *minimap;

	minimap = &map->minimap;
	minimap->scale = map->scale * 0.25f;
	minimap->x = data->width - map->width * minimap->scale;
	minimap->y = data->height - map->height * minimap->scale;
	ft_memcpy(&minimap->player, &map->player, sizeof(t_player));
}