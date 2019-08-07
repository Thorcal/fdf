# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 14:50:04 by spuisais          #+#    #+#              #
#    Updated: 2019/03/26 16:00:59 by spuisais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fdf

CC = gcc

CS =	src/main.c			\
		src/bresenham.c		\
		src/iso_view.c		\
		src/persp_view.c	\
		src/utils.c			\
		src/inputs.c		\
		src/error_clean.c	\
		src/screen_setup.c	\

OS = $(CS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

IFLAGS = -I /usr/local/include -L /usr/local/lib/ -lmlx

LFLAGS = -framework OpenGL -framework Appkit

all: $(NAME)
	@make -C libft all

$(NAME): $(OS) include/fdf.h
	@make -C libft all
	@gcc $(CFLAGS) $(IFLAGS) $(LFLAGS) -o $(NAME) $(OS) libft/libft.a
	@echo "Compilation FDF OK."

clean:
	@make -C libft clean
	@rm -f $(OS)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all
