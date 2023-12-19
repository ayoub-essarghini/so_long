NAME = so_long
SRCS = so_long.c
INCLUDES = -I/usr/include -Imlx
MLX_FLAGS = -L./minilibx-linux -lmlx -lX11 -lXext -lm
CFLAGS= -Wall -Werror -Wextra
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		cc  $(CFLAGS) -o $(NAME) $(OBJS) ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c libftprintf.a $(MLX_FLAGS)

.c.o:
		cc -Wall -Wextra -Werror -c -o $@ $< $(INCLUDES)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re