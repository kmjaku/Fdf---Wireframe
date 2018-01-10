# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 18:26:16 by kmjaku            #+#    #+#              #
#    Updated: 2017/03/28 00:17:06 by kmjaku           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf

FLAGS= -Wall -Werror -Wextra

FLAGS_MLX = -lmlx -framework OpenGL -framework AppKit

LIBFT= ./libft/libft.a

SRCS= srcs/draw.c \
	  srcs/draw_map.c \
	  srcs/err_and_free.c \
	  srcs/hook.c \
	  srcs/hook_2.c \
	  srcs/init.c \
	  srcs/main.c \
	  srcs/matrix.c \
	  srcs/matrix_point.c \
	  srcs/read.c \
	  srcs/set_image.c

OBJ= $(SRCS:.c=.o)

$(NAME): $(OBJ)
	@echo "\nexecutable fdf is ready"
	@make -C LIBFT
	@gcc -o $(NAME) $(OBJ) $(LIBFT) $(FLAGS) $(FLAGS_MLX)

all: $(NAME)

clean:
	@echo "\nremoving all extensions '.o' in fdf"
	@rm -rf $(OBJ)
	@echo "clean done for fdf"

fclean: clean
	@echo "\nremoving fdf"
	@rm -rf $(NAME)
	@make -C libft/ fclean
	@echo "fclean is done"

re:
	@echo "removing executable fdf"
	$(clean)
	@make -C LIBFT
	@echo "re-executing all"
	$(all)
