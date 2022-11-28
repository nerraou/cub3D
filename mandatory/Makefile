NAME = cub3D
FLAGS = -Wall -Wextra -Werror -Imlx
HEADERS = $(addprefix $(INCLUDES_PATH)/,list.h get_next_line.h player.h map.h ft_mlx.h ray.h vector2.h)
LIBFT = ./src/libft/libft.a

INCLUDES_PATH = ./includes

ifdef MLX_LINUX_PATH
	INCLUDES_FLAGS = -I $(INCLUDES_PATH) -I $(MLX_LINUX_PATH)
	COMPILE = $(CC) $^ $(INCLUDES_FLAGS) -L$(MLX_LINUX_PATH) -lmlx -lXext -lX11 -lm -lz -o $(NAME)
else
	INCLUDES_FLAGS = -I $(INCLUDES_PATH) -Imlx
	COMPILE = $(CC) $^ $(INCLUDES_FLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
endif

SRC = \
	src/gnl/get_next_line_utils.c\
	src/gnl/get_next_line.c\
\
	src/list/add_back.c\
	src/list/add_front.c\
	src/list/elem_new.c\
	src/list/list_del.c\
	src/list/list_new.c\
	src/list/list_to_array.c\
	src/list/list_del_noop.c\
\
	src/map/set_textures.c\
	src/map/set_map_widths.c\
	src/map/set_colors.c\
	src/map/rgb_from_string.c\
	src/map/set_replace_player_position.c\
	src/map/init_map.c\
	src/map/is_wall.c\
	src/map/map_has_header.c\
	src/map/map_parse_header.c\
	src/map/open_map.c\
	src/map/map_parse_map.c\
	src/map/is_good_map.c\
	src/map/parse.c\
\
	src/mlx/esc_hook.c\
	src/mlx/ft_mlx_init_window.c\
	src/mlx/ft_mlx_init.c\
	src/mlx/ft_mlx_pixel_put.c\
	src/mlx/draw_player.c\
	src/mlx/draw_line.c\
	src/mlx/draw_rect.c\
	src/mlx/draw_walls.c\
	src/mlx/mlx_key_down_hook.c\
	src/mlx/mlx_key_up_hook.c\
	src/mlx/on_key_up.c\
	src/mlx/on_key_down.c\
	src/mlx/update_loop.c\
	src/mlx/fill.c\
	src/mlx/set_horizontal_coords.c\
	src/mlx/set_vertical_coords.c\
	src/mlx/vertical_wall_intercept.c\
	src/mlx/horizontal_wall_intercept.c\
	src/mlx/cast_ray.c\
	src/mlx/apply_wall_texture.c\
    src/mlx/render_3d_projection_wall.c\
    src/mlx/apply_ceiling_floor_color.c\
\
	src/player/player_init.c\
\
	src/ray/init_ray.c\
\
	src/vector2/vector2_set.c\
	src/vector2/vector2_set_x.c\
	src/vector2/vector2_set_y.c\
	src/vector2/vector2_create.c\
\
	src/main.c

OBJ = $(SRC:.c=.o)

all: libft $(NAME)

libft:
	make -C ./src/libft

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) $(INCLUDES_FLAGS) -o $@ -c $<

$(NAME): $(OBJ) $(LIBFT)
	$(COMPILE)

clean:
	make -C ./src/libft clean
	rm -f $(OBJ)

fclean: clean
	make -C ./src/libft fclean
	rm -f $(NAME)

re: fclean all
