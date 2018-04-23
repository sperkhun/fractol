#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/04 14:53:34 by sperkhun          #+#    #+#              #
#    Updated: 2018/02/04 14:53:35 by sperkhun         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

FLAGS = -Wall -Wextra -Werror

SRC = main.c ft_mlx.c draw.c fract.c thr.c setprmt.c mouse.c keyboard.c

OBJ = $(SRC:.c=.o)

LIBFT = -L ./libft/ -lft

LIBMLX = -L /usr/local/lib/ -lmlx

INCL = -I ./libft/includes/ -I /usr/local/include

all: $(NAME)

$(NAME):
	@make -C ./libft/
	@gcc $(FLAGS) -c $(SRC) $(INCL) -pthread
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX)\
					-framework OpenGL -framework AppKit

clean:
	@/bin/rm -f $(OBJ)
	@make -C ./libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C ./libft/ fclean
re: fclean all