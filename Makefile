# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 14:32:47 by lde-taey          #+#    #+#              #
#    Updated: 2024/01/30 13:17:18 by lde-taey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

CC = gcc

SRCS = ft_printf.c \
		ft_putchar.c \
		ft_puthexax.c \
		ft_puthexaxl.c \
		ft_putnbr.c \
		ft_putptr.c \
		ft_putstr.c \
		ft_putuni.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

.PHONY:
	all clean fclean re

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

run:
	make -C ./libft
	$(CC) $(CFLAGS) $(SRCS) libft/libft.a
	./a.out
	rm -f a.out

re: fclean all