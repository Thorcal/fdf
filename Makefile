# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spuisais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 14:50:04 by spuisais          #+#    #+#              #
#    Updated: 2019/02/19 15:53:49 by spuisais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fdf

CS =	src/main.c \
		src/bresenham.c

OS = $(CS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

IFLAGS = -I /usr/local/include -L /usr/local/lib/ -lmlx

LFLAGS = -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(OS)
	@make -C libft all
	@gcc $(CFLAGS) $(IFLAGS) $(LFLAGS) -o $(NAME) src/main.o src/bresenham.o libft/libft.a
	@echo "Compilation FDF OK."

clean:
	@make -C libft clean
	@rm -f $(OS)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all
