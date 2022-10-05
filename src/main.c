#include <mlx.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "map.h"
#include "debug.h"
#include "ft_mlx.h"

int main(void)
{
	t_data window_data;
	t_mlx mlx;

	char *line;
	t_map data;
	t_list *list;

	init_map(&data);
	int fd = open("./test-maps/map1.cub", O_RDONLY);
	list = list_new();
	line = get_next_line(fd);
	while (line)
	{
		if (has_header(&data))
		{
			if (line[0] != '\0')
			{
				set_player_orientation(line, &data);
				add_back(list, (void *)line);
			}
			else
				free(line);
		}
		else
		{
			set_colors(line, &data);
			set_map_textures(line, &data);
			free(line);
		}
		line = get_next_line(fd);
	}
	data.map_array = list_to_array(list);
	printf("%s\n", data.so_wall_texture);
	printf("%s\n", data.we_wall_texture);
	printf("%s\n", data.no_wall_texture);
	printf("%s\n", data.ea_wall_texture);
	printf("player spawning orientation: %c\n", data.player_orientation);
	print_color("C", data.ceiling_color);
	print_color("F", data.floor_color);
	print_map(data.map_array, list->size);
	ft_init(&window_data, &mlx);
	draw(&window_data, data.map_array);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, window_data.img, 0, 0);
	mlx_key_hook(mlx.mlx_win, esc_hook, &mlx);
	mlx_loop(mlx.mlx);

	return 0;
}
