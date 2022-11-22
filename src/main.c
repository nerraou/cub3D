/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:03:03 by ybahlaou          #+#    #+#             */
/*   Updated: 2022/11/22 23:10:45 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "map.h"
#include "debug.h"
#include "player.h"
#include "ft_mlx.h"
#include "ray.h"

static void	init_event(t_event_data *e, t_data *data, t_map *map, t_ray *ray)
{
	e->data = data;
	e->map = map;
	e->ray = ray;
}

static int	mouse_move_hook(int x, int y, t_event_data *e)
{
	t_player	*p;
	int			turn_direction;
	(void)y;

	p = &e->map->player;
	if (x > e->mouse.x)
		turn_direction = 1;
	else if (x < e->mouse.x)
		turn_direction = -1;
	else
		turn_direction = 0;
	p->rotation_angle += turn_direction * p->rotation_speed;
	e->mouse.x = x;
	e->mouse.y = y;
	return (0);
}

int	main(int argc, char **argv)
{
	t_event_data	event_data;
	t_data			window_data;
	t_map			map;
	t_ray			ray;

	if (argc != 2)
		return 1;
	init_event(&event_data, &window_data, &map, &ray);
	ft_mlx_init(&window_data);
	if (parse(argv[1], window_data.mlx, &map) == 0)
	{
		map.ray = &ray;
		window_data.map = &map;
		ft_mlx_init_window(&window_data, &map);
		init_ray(&ray, window_data.width);
		init_minimap(&window_data, &map);
		mlx_hook(window_data.mlx_win, 6, 1L << 6, mouse_move_hook, &event_data);
		mlx_hook(window_data.mlx_win, 17, 0, esc_hook, &window_data);
		mlx_key_down_hook(window_data.mlx_win, on_key_down, &event_data);
		mlx_key_up_hook(window_data.mlx_win, on_key_up, &event_data);
		mlx_loop_hook(window_data.mlx, update_loop, &event_data);
		mlx_loop(window_data.mlx);
		return (0);
	}
	return (1);
}
