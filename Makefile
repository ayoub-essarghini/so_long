NAME = so_long
SRCS = so_long.c ft_read_map.c ft_check_valid_map.c \
ft_img_init.c draw_map.c ft_mapfunc.c move_func.c ft_move_utils.c \
check_valid_path.c func_helper.c ft_split.c
INCLUDES = -I/usr/include -Imlx
MLX_FLAGS = -L./minilibx-linux -lmlx -lX11 -lXext -lm -fsanitize=address
CFLAGS= -Wall -Werror -Wextra
OBJS = $(SRCS:.c=.o)
GREEN = \033[0;32m

all: $(NAME)

$(NAME): $(OBJS)
		cc  $(CFLAGS) -o $(NAME) $(OBJS) ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c ./ft_printf/libftprintf.a $(MLX_FLAGS)
		@echo "$(GREEN)Ready to play 🕹️ ✅"
 
.c.o:
		cc -Wall -Wextra -Werror -c -o $@ $< $(INCLUDES)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re