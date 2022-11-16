/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:20:22 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/14 18:00:48 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int init_texture(t_data *data, t_map *map)
{
	map->textures.ea = mlx_xpm_file_to_image(data->mlx, "../../assets/test1.xpm", &map->textures.size, &map->textures.size);
	if (map->textures.ea == NULL)
		return -1;
	return 1;
}