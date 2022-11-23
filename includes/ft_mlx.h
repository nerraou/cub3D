/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:53:02 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/23 23:50:53 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>

# include "vector2.h"
# include "libft.h"
# include "ray.h"
# include "map.h"

# define ESC_KEY 53
# define UP_ARROW_KEY 126
# define RIGHT_ARROW_KEY 124
# define DOWN_ARROW_KEY 125
# define LEFT_ARROW_KEY 123
# define W_KEY 13
# define D_KEY 2
# define S_KEY 1
# define A_KEY 0

// #define UP_ARROW_KEY 65362
// #define RIGHT_ARROW_KEY 65363
// #define DOWN_ARROW_KEY 65364
// #define LEFT_ARROW_KEY 65361

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		scale;
	int		current_fill;
	t_map	*map;
}			t_data;

typedef struct s_event_data
{
	t_data		*data;
	t_map		*map;
	t_ray		*ray;
	t_vector2	mouse;
}				t_event_data;

void	ft_mlx_pixel_put(t_data *data, int x, int y);
void	ft_mlx_init(t_data *data);
void	ft_mlx_init_window(t_data *data, const t_map *map);
void	draw_minimap(t_data *data, t_map *map, t_minimap *mmap);
void	draw_line(t_data *data, t_vector2 begin, t_vector2 end);
void	draw_rect(t_data *data, t_vector2 start, int width, int height);
void	draw_circle(t_data *data, int x0, int y0, int radius);
void	fill(t_data *data, int color);
void	draw_player(t_data *data, const t_player *player);
void	draw_walls(t_data *data, t_ray *ray, t_map *map);
void	apply_wall_texture(t_data *d, t_texture *t, t_tuplef v, int ray_num);
void	render_3d_projection_wall(t_data *data, float angle_ray, int ray_num);
void	apply_ceiling_floor_color(t_data *d, t_tuplef wall_ends, int ray_num);
void	draw_door(t_data *data, t_texture *t, t_tuplef values, int ray_num);
void	init_minimap(t_data *data, t_map *map);

int		esc_hook(t_data *mlx);
int		mlx_key_down_hook(void *win_ptr, int (*handler)(), void *param);
int		mlx_key_up_hook(void *win_ptr, int (*handler)(), void *param);
int		mlx_mouse_move_hook(void *win_ptr, int (*handler)(), void *param);
int		on_key_down(int keycode, t_event_data *e);
int		on_key_up(int keycode, t_event_data *e);
int		on_mouse_move(int x, int y, t_event_data *e);
int		update_loop(t_event_data *e);
int		set_horizontal_coords(t_vector2 *step, t_vector2 *intercept, \
		t_map *map, float angle);
int		set_vertical_coords(t_vector2 *step, t_vector2 *intercept, \
		t_map *map, float angle);
int		horizontal_wall_intercept(t_map *map, t_vector2 *intercept, \
		float angle, int *in);
int		vertical_wall_intercept(t_map *map, t_vector2 *intercept, \
		float angle, int *in);

float	cast_ray(t_map *map, float angle, int *horizontal, float *point);

#endif
