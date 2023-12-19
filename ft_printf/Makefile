# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aes-sarg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 02:48:38 by aes-sarg          #+#    #+#              #
#    Updated: 2023/11/24 02:48:38 by aes-sarg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_u.c
OBJES = ${SRCS:.c=.o}
NAME = libftprintf.a
GCC = cc
AR = ar rc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf

%.o : %.c
	   ${GCC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBJES}
		${AR} $@ ${OBJES} 
all: ${NAME}

clean:
		${RM} ${OBJES}

fclean: clean
		${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re