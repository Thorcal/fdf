# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spuisais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 14:50:04 by spuisais          #+#    #+#              #
#    Updated: 2019/03/01 17:36:34 by spuisais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fdf

CS =	src/main.c			\
		src/bresenham.c		\
		src/iso_view.c		\
		src/persp_view.c	\
		src/utils.c			\
		src/inputs.c		\

OS = $(CS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

IFLAGS = -I /usr/local/include -L /usr/local/lib/ -lmlx

LFLAGS = -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(OS)
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
