#include <mlx.h>
#include <X11/X.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "map.h"
#include "debug.h"
#include "player.h"
#include "ft_mlx.h"

#define UP_ARROW_KEY 65362
#define RIGHT_ARROW_KEY 65363
#define DOWN_ARROW_KEY 65364
#define LEFT_ARROW_KEY 65361

typedef struct s_event_data
{
	t_data *data;
	t_map *map;
} t_event_data;

int mlx_key_down_hook(void *win_ptr, int (*handler)(), void *param)
{
	return mlx_hook(win_ptr, KeyPress, KeyPressMask, handler, param);
}

int mlx_key_up_hook(void *win_ptr, int (*handler)(), void *param)
{
	return mlx_hook(win_ptr, KeyRelease, KeyReleaseMask, handler, param);
}

int on_key_down(int keycode, t_event_data *e)
{
	if (keycode == UP_ARROW_KEY)
		e->map->player.walk_direction = 1;
	else if (keycode == DOWN_ARROW_KEY)
		e->map->player.walk_direction = -1;
	else if (keycode == RIGHT_ARROW_KEY)
		e->map->player.turn_direction = 1;
	else if (keycode == LEFT_ARROW_KEY)
		e->map->player.turn_direction = -1;
	return (0);
}

int on_key_up(int keycode, t_event_data *e)
{
	if (keycode == UP_ARROW_KEY || keycode == DOWN_ARROW_KEY)
		e->map->player.walk_direction = 0;
	else if (keycode == RIGHT_ARROW_KEY || keycode == LEFT_ARROW_KEY)
		e->map->player.turn_direction = 0;
	return (0);
}

int update_loop(t_event_data *e)
{
	t_player *p;
	int move_by;

	p = &e->map->player;

	p->rotation_angle += p->turn_direction * p->rotation_speed;
	move_by = p->walk_direction * p->move_speed;
	p->x += cos(p->rotation_angle) * move_by;
	p->y += sin(p->rotation_angle) * move_by;

	fill(e->data, 0x000000);
	draw_rect(e->data, 0, 0, e->data->width, e->data->height);
	draw_minimap(e->data, e->map->map_array);
	draw_player(e->data, &e->map->player);
	mlx_put_image_to_window(e->data->mlx, e->data->mlx_win, e->data->img, 0, 0);
	return (0);
}

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
