/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:53:02 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/12 18:45:46 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
#define FT_MLX_H

#include <mlx.h>
#include <stdlib.h>
#include "map.h"
#include <math.h>

#define ESC_KEY 53

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
	int width;
	int height;
	int scale;
	int current_fill;
} t_data;

typedef struct s_mlx
{
	void *mlx;
	void *mlx_win;
} t_mlx;

void ft_mlx_pixel_put(t_data *data, int x, int y);
void ft_init(t_data *data, t_mlx *mlx);
int esc_hook(int keycode, t_mlx *mlx);
void draw_minimap(t_data *data, char **map);
void draw_line(t_data *data, int beginX, int beginY, int endX, int endY);
void draw_rect(t_data *data, int x, int y, int width, int height);
void fill(t_data *data, int color);
void draw_player(t_data *data, const t_player *player);

#endif
