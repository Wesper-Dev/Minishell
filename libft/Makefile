# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/28 18:25:18 by juaugry           #+#    #+#              #
#    Updated: 2023/12/28 18:25:19 by juaugry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_atoi.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_strncmp.c \
		ft_putendl_fd.c \

OBJ = $(SRCS:.c=.o)

OBJ_BON= $(BONUS:.c=.o)

all: $(NAME)

bonus: $(OBJ) $(OBJ_BON)
	ar rc $(NAME) $^
	ranlib $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ) $(OBJ_BON)


fclean: clean
	rm -f $(NAME)

re: fclean all
