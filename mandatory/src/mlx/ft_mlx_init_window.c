/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:49:30 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/25 22:27:59 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void	ft_mlx_init_window(t_data *data, const t_map *map)
{
	data->scale = map->scale;
	data->width = 1080;
	data->height = 720;
	data->mlx_win = mlx_new_window(data->mlx, data->width, data->height, \
	"Cub3D");
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->img)
		exit(1);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	if (!data->addr)
		exit(1);
}
