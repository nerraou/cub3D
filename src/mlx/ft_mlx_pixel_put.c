/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:09:46 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/10 22:04:21 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void ft_mlx_pixel_put(t_data *data, int x, int y)
{
	char *dst;

	if (x >= data->width || y >= data->height || x < 0 || y < 0)
		return;
	dst = data->addr + (y * data->line_length + x * 4);
	*(unsigned int *)dst = data->current_fill;
}