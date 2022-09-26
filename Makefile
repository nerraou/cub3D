NAME = cub3D
FLAGS = -Wall -Wextra -Werror -Imlx
HEADERS =
	  
SRC = main.c

OBJ = $(SRC:.c=.o)

INCLUDES_PATH = -I ./

all:  $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) $(INCLUDES_PATH) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
