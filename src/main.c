#include <mlx.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "map.h"
#include "debug.h"
#include "player.h"
#include "ft_mlx.h"

int main(void)
{
	t_event_data event_data;
	t_data window_data;

	char *line;
	t_map map;
	t_list *list;

	event_data.data = &window_data;
	event_data.map = &map;

	ft_init(&window_data);
	init_map(&map);
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
	set_replace_player_position(&map);
	player_init(&map.player, map.player_orientation);
	mlx_key_hook(window_data.mlx_win, esc_hook, &window_data);
	mlx_key_down_hook(window_data.mlx_win, on_key_down, &event_data);
	mlx_key_up_hook(window_data.mlx_win, on_key_up, &event_data);
	mlx_loop_hook(window_data.mlx, update_loop, &event_data);
	mlx_loop(window_data.mlx);
	return 0;
}
