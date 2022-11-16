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

	map->textures.ea.img = mlx_xpm_file_to_image(data->mlx, "./assets/test2.xpm", &map->textures.ea.width, &map->textures.ea.height);
	if (!map->textures.ea.img)
		return -1;
	map->textures.ea.addr = mlx_get_data_addr(map->textures.ea.img, &map->textures.ea.bits_per_pixel, &map->textures.ea.line_length, &map->textures.ea.endian);
	if (!map->textures.ea.addr)
		return -1;
	return 1;
}

int main(void)
{
	t_event_data event_data;
	t_data window_data;

	char *line;
	t_map map;
	t_list *list;
	t_ray ray;

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

	int fd = open("./test-maps/map1.cub", O_RDONLY);
	list = list_new();
	line = get_next_line(fd);
	while (line)
	{
		if (has_header(&map))
		{
			if (line[0] != '\0')
			{
				add_back(list, (void *)line);
			}
			else
				free(line);
		}
		else
		{
			set_colors(line, &map);
			set_map_textures(line, &map);
			free(line);
		}
		line = get_next_line(fd);
	}
	map.map_array = list_to_array(list);
	set_line_length(&map.length, map.map_array, list->size);
	set_replace_player_position(&map, window_data.scale);
	player_init(&map.player, map.player_orientation);
	mlx_key_down_hook(window_data.mlx_win, on_key_down, &event_data);
	mlx_key_up_hook(window_data.mlx_win, on_key_up, &event_data);
	// mlx_put_image_to_window(window_data.mlx, window_data.mlx_win, map.textures.ea, 50, 50);
	mlx_loop_hook(window_data.mlx, update_loop, &event_data);
	mlx_loop(window_data.mlx);
	return 0;
}
