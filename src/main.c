#include <mlx.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "map.h"
#include "debug.h"
#include "player.h"
#include "ft_mlx.h"
#include "ray.h"

int init_texture(t_data *data, t_map *map)
{

	map->textures.ea.img = mlx_xpm_file_to_image(data->mlx, "./assets/wall.xpm", &map->textures.ea.width, &map->textures.ea.height);
	if (!map->textures.ea.img)
		return -1;
	map->textures.ea.addr = mlx_get_data_addr(map->textures.ea.img, &map->textures.ea.bits_per_pixel, &map->textures.ea.line_length, &map->textures.ea.endian);
	if (!map->textures.ea.addr)
		return -1;
	map->textures.we.img = mlx_xpm_file_to_image(data->mlx, "./assets/wall2.xpm", &map->textures.we.width, &map->textures.we.height);
	if (!map->textures.we.img)
		return -1;
	map->textures.we.addr = mlx_get_data_addr(map->textures.we.img, &map->textures.we.bits_per_pixel, &map->textures.we.line_length, &map->textures.we.endian);
	if (!map->textures.we.addr)
		return -1;
	map->textures.so.img = mlx_xpm_file_to_image(data->mlx, "./assets/wall3.xpm", &map->textures.so.width, &map->textures.so.height);
	if (!map->textures.so.img)
		return -1;
	map->textures.so.addr = mlx_get_data_addr(map->textures.so.img, &map->textures.so.bits_per_pixel, &map->textures.so.line_length, &map->textures.so.endian);
	if (!map->textures.so.addr)
		return -1;
	map->textures.no.img = mlx_xpm_file_to_image(data->mlx, "./assets/wall4.xpm", &map->textures.no.width, &map->textures.no.height);
	if (!map->textures.no.img)
		return -1;
	map->textures.no.addr = mlx_get_data_addr(map->textures.no.img, &map->textures.no.bits_per_pixel, &map->textures.no.line_length, &map->textures.no.endian);
	if (!map->textures.no.addr)
		return -1;
	return 1;
}

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
	ft_init(&window_data);
	init_map(&map);
	if (init_texture(&window_data, &map) == -1)
	{
		printf("check the path agin \n");
		return 1;
	}
	init_ray(&ray);

	if (parse(argv[1], &map) == 0)
	{
		mlx_key_down_hook(window_data.mlx_win, on_key_down, &event_data);
		mlx_key_up_hook(window_data.mlx_win, on_key_up, &event_data);
		mlx_loop_hook(window_data.mlx, update_loop, &event_data);
		mlx_loop(window_data.mlx);
	}
	return 0;
}
