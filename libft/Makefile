# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/30 14:33:01 by kmjaku            #+#    #+#              #
#    Updated: 2017/03/24 23:10:09 by kmjaku           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_deg_to_rad.c \
	  ft_memset.c \
	  ft_count_word.c \
	  ft_power.c \
	  	ft_bzero.c \
	  	ft_memcpy.c \
	  	ft_strtrim.c \
	  	ft_strsub.c \
	  	ft_strsplit.c \
	  	ft_strnew.c \
	  	ft_strnequ.c \
		ft_strmapi.c \
		ft_strmap.c \
		ft_strlen.c \
		ft_strjoin.c \
		ft_striteri.c \
		ft_striter.c \
		ft_strequ.c \
		ft_strdup.c \
		ft_strdel.c \
		ft_strcpy.c \
		ft_strclr.c \
		ft_memdel.c \
		ft_memalloc.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_atoi.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memmove.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_memcpy.c \
		ft_strstr.c \
		ft_strcat.c \
		ft_strncpy.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_itoa.c \
		ft_putnbr_fd.c \
		ft_memcmp.c \
		ft_memchr.c \
		ft_memccpy.c \
		ft_putendl_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_strndup.c \
		get_next_line.c

OBJ = $(SRC:.c=.o)

RM = @rm -f

$(NAME):
	@echo "\nlibft compiling starts"
	@gcc $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "removing all extensions '.o'"
	$(RM) $(OBJ)
	@echo "libft.a is ready"

all: $(NAME)

clean:
	@echo "\nremoving objects"
	$(RM) $(OBJ)
	@echo "clean done"

fclean:
	@echo "\ncalling clean for removing all extensions '.o' in libft"
	$(clean)
	@echo "clean done in libft"
	@echo "now removing $(NAME)."
	$(RM) $(NAME)
	@echo "removing done in libft"

re:
	@echo "\ncalling fclean for removing $(OBJ) and $(NAME)"
	$(fclean)
	@echo "now re-executing all"
	$(all)

.PHONY: clean fclean
