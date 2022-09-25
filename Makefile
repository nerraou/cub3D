NAME = cub3D
CPPFLAGS = -Wall -Wextra -Werror -Imlx
HEADERS = header.hpp 
	  
SRC = main.cpp


OBJ = $(SRC:.cpp=.o)

INCLUDES_PATH = -I ./

all:  $(NAME)

%.o: %.cpp $(HEADERS)
	gcc $(CPPFLAGS) $(INCLUDES_PATH)  -o $@ -c $<

$(NAME): $(OBJ)
	gcc  -lmlx -framework OpenGL -framework AppKit -o $(NAME) $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
