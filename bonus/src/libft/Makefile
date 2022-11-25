NAME = libft.a
FLAGS = -Wall -Wextra -Werror
INCLUDES_PATH = ../../includes
HEADERS = $(INCLUDES_PATH)/libft.h

SRC = ft_atoi.c\
	ft_indexof.c\
	ft_isspace.c\
	ft_itoa.c\
	ft_malloc.c\
	ft_memset.c\
	ft_strdup.c\
	ft_strlen.c\
	ft_strncmp.c\
	ft_strcmp.c\
	ft_strncpy.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strlcpy.c\
	ft_strcpy.c\
	ft_memcpy.c\
	is_long.c\
	ft_atol.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isdigit.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_split.c\
	ft_tolower.c\
	distance.c\
	normalize_angle.c\
	ft_strctrim.c\
	ft_strendswith.c\
	ft_strctrimend.c\
	is_rgb_string.c\
	perror_and_return.c\
	ft_free_carray.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -I $(INCLUDES_PATH) -o $@ -c $<

$(NAME): $(OBJ)
	ar cr $(NAME) $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
