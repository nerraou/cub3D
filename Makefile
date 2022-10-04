NAME = cub3D
FLAGS = -Wall -Wextra -Werror -Imlx
HEADERS = $(addprefix $(INCLUDES_PATH)/,list.h libft.h get_next_line.h map.h player.h debug.h ft_mlx.h)

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
\
	src/map/set_map_textures.c\
	src/map/set_east_texture.c\
	src/map/set_north_texture.c\
	src/map/set_south_texture.c\
	src/map/set_west_texture.c\
	src/map/set_player_orientation.c\
	src/map/set_colors.c\
	src/map/set_ceiling_color.c\
	src/map/set_floor_color.c\
	src/map/parse_color.c\
	src/map/init_map.c\
	src/map/has_header.c\
\
	src/mlx/esc_hook.c\
	src/mlx/ft_init.c\
	src/mlx/ft_mlx_pixel_put.c\
	src/mlx/draw.c\
	src/mlx/draw_line.c\
\
	src/debug/debug.c\
\
	src/main.c

OBJ = $(SRC:.c=.o)

INCLUDES_PATH = ./includes

all:  $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -I $(INCLUDES_PATH) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
