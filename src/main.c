#include <mlx.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "map.h"

static void print_color(const char *message, int color)
{
	printf("%s (%d,%d,%d)\n", message, color >> 16, (color >> 8) & 0x000000FF, color & 0x000000FF);
}

static void print_map(char **map_array, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		printf("%s\n", map_array[i]);
		i++;
	}
}

static int has_header(const t_map *map)
{
	return (map->ceiling_color != -1 &&
			map->floor_color != -1 &&
			map->no_wall_texture &&
			map->so_wall_texture &&
			map->we_wall_texture &&
			map->ea_wall_texture);
}

static void init_map(t_map *map)
{
	ft_memset(map, 0, sizeof(t_map));
	map->ceiling_color = -1;
	map->floor_color = -1;
}

static char **list_to_array(const t_list *list)
{
	t_element *cur;
	char **array;
	int i;

	array = (char **)malloc(sizeof(char *) * list->size);
	cur = list->head;
	i = 0;
	while (cur != NULL)
	{
		array[i] = (char *)cur->content;
		cur = cur->next;
		i++;
	}
	return (array);
}

int main(void)
{
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

	return 0;
}
