/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:53:02 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/17 16:36:38 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
#define FT_MLX_H

#include <mlx.h>
#include <stdlib.h>
#include "map.h"
#include <math.h>

#define ESC_KEY 53
#define UP_ARROW_KEY 126
#define RIGHT_ARROW_KEY 124
#define DOWN_ARROW_KEY 125
#define LEFT_ARROW_KEY 123
#define W_KEY 13
#define D_KEY 2
#define S_KEY 1
#define A_KEY 0

typedef struct s_data
{
	void *mlx;
	void *mlx_win;
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

typedef struct s_event_data
{
	t_data *data;
	t_map *map;
} t_event_data;

void ft_mlx_pixel_put(t_data *data, int x, int y);
void ft_init(t_data *data);
void esc_hook(t_data *mlx);
void draw_minimap(t_data *data, char **map);
void draw_line(t_data *data, int beginX, int beginY, int endX, int endY);
void draw_rect(t_data *data, int x, int y, int width, int height);
void draw_circle(t_data *data, int x0, int y0, int radius);
void fill(t_data *data, int color);
void draw_player(t_data *data, const t_player *player);
int mlx_key_down_hook(void *win_ptr, int (*handler)(), void *param);
int mlx_key_up_hook(void *win_ptr, int (*handler)(), void *param);
int on_key_down(int keycode, t_event_data *e);
int on_key_up(int keycode, t_event_data *e);
int update_loop(t_event_data *e);

#endif
