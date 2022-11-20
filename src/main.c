#include <mlx.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "map.h"
#include "debug.h"
#include "player.h"
#include "ft_mlx.h"
#include "ray.h"

int main(int argc, char **argv)
{
	t_event_data event_data;
	t_data window_data;
	t_map map;
	t_ray ray;

	if (argc != 2)
		return 1;
	event_data.data = &window_data;
	event_data.map = &map;
	event_data.ray = &ray;
	ft_mlx_init(&window_data);
	if (parse(argv[1], window_data.mlx, &map) == 0)
	{
		ft_mlx_init_window(&window_data, &map);
		init_ray(&ray, window_data.width);
		mlx_key_down_hook(window_data.mlx_win, on_key_down, &event_data);
		mlx_key_up_hook(window_data.mlx_win, on_key_up, &event_data);
		mlx_loop_hook(window_data.mlx, update_loop, &event_data);
		mlx_loop(window_data.mlx);
		return (0);
	}
	return (1);
}
