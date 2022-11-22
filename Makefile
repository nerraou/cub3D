NAME = cub3D
FLAGS = -Wall -Wextra -Werror -Imlx
HEADERS = $(addprefix $(INCLUDES_PATH)/,list.h libft.h get_next_line.h player.h debug.h map.h ft_mlx.h ray.h vector2.h)

SRC = \
	src/libft/ft_atoi.c\
	src/libft/ft_indexof.c\
	src/libft/ft_isspace.c\
	src/libft/ft_itoa.c\
	src/libft/ft_malloc.c\
	src/libft/ft_memset.c\
	src/libft/ft_strdup.c\
	src/libft/ft_strlen.c\
	src/libft/ft_strncmp.c\
	src/libft/ft_strcmp.c\
	src/libft/ft_strncpy.c\
	src/libft/ft_substr.c\
	src/libft/ft_strjoin.c\
	src/libft/ft_strlcpy.c\
	src/libft/ft_strcpy.c\
	src/libft/ft_memcpy.c\
	src/libft/is_long.c\
	src/libft/ft_atol.c\
	src/libft/ft_isalnum.c\
	src/libft/ft_isalpha.c\
	src/libft/ft_isdigit.c\
	src/libft/ft_putchar_fd.c\
	src/libft/ft_putstr_fd.c\
	src/libft/ft_putendl_fd.c\
	src/libft/ft_split.c\
	src/libft/ft_tolower.c\
	src/libft/distance.c\
	src/libft/normalize_angle.c\
	src/libft/ft_strctrim.c\
	src/libft/ft_strendswith.c\
	src/libft/ft_strctrimend.c\
	src/libft/is_rgb_string.c\
	src/libft/perror_and_return.c\
\
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
	src/map/is_door.c\
	src/map/map_has_header.c\
	src/map/map_parse_header.c\
	src/map/open_map.c\
	src/map/map_parse_map.c\
	src/map/is_good_map.c\
	src/map/parse.c\
	src/map/init_minimap.c\
\
	src/mlx/esc_hook.c\
	src/mlx/ft_mlx_init_window.c\
	src/mlx/ft_mlx_init.c\
	src/mlx/ft_mlx_pixel_put.c\
	src/mlx/draw_minimap.c\
	src/mlx/draw_player.c\
	src/mlx/draw_line.c\
	src/mlx/draw_rect.c\
	src/mlx/draw_walls.c\
	src/mlx/draw_circle.c\
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
    src/mlx/draw_door.c\
    src/mlx/apply_ceiling_floor_color.c\
\
	src/player/player_init.c\
\
	src/ray/init_ray.c\
\
	src/vector2/vector2_set.c\
	src/vector2/vector2_set_x.c\
	src/vector2/vector2_set_y.c\
\
	src/debug/debug.c\
\
	src/main.c

OBJ = $(SRC:.c=.o)

INCLUDES_PATH = ./includes

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -I $(INCLUDES_PATH) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
