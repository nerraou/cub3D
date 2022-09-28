#include <mlx.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "map.h"

int main(void)
{

	char *line;
	t_map data;

	int fd = open("./test-maps/map1.cub", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		set_map_textures(line, &data);
		free(line);
		line = get_next_line(fd);
	}
	printf("%s\n", data.so_wall_texture);
	printf("%s\n", data.we_wall_texture);
	printf("%s\n", data.no_wall_texture);
	printf("%s\n", data.ea_wall_texture);

	return 0;
}