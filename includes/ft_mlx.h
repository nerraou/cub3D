/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:53:02 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/07 13:46:03 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
#define FT_MLX_H

#include <mlx.h>
#include <stdlib.h>
#include "map.h"
#include <math.h>

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
	int width;
	int height;
} t_data;

typedef struct s_mlx
{
	void *mlx;
	void *mlx_win;
} t_mlx;

void ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void ft_init(t_data *data, t_mlx *mlx);
int esc_hook(int keycode, t_mlx *mlx);
void draw(t_data *data, char **map, int *length);
void draw_line(t_data *data, int beginX, int beginY, int endX, int endY, int color);

#endif