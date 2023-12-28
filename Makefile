# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/28 18:22:41 by juaugry           #+#    #+#              #
#    Updated: 2023/12/28 18:22:42 by juaugry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
NAME_OS = $(shell uname)

ifeq ($(NAME_OS), Darwin)
        SRC = srcs/main.c \
				libft/ft_putchar_fd.c \
				libft/ft_putstr_fd.c \
				libft/*.c \
				srcs/main_utils.c \
				srcs/main_utils_2.c \
				srcs/builtins/cd.c \
				srcs/builtins/echo.c \
				srcs/builtins/env.c \
				srcs/builtins/exit.c \
				srcs/builtins/exit_utils.c \
				srcs/builtins/export.c \
				srcs/builtins/export_utils.c \
				srcs/builtins/pwd.c \
				srcs/signal.c \
				srcs/init_global.c \
				srcs/builtins/unset.c \
				srcs/add_link.c \
				srcs/new_link.c \
				srcs/change_fd.c \
				srcs/cmd_utils.c \
				srcs/exec_utils.c \
				srcs/exec.c \
				srcs/expand_utils.c \
				srcs/expand.c \
				srcs/free_data.c \
				srcs/init_cmd.c \
				srcs/init_data.c \
				srcs/init_data_utils.c \
				srcs/lexer.c \
				srcs/lexer_utils.c \
				srcs/make_token.c \
				srcs/no_expand_quote.c \
				srcs/no_expand_utils.c \
				srcs/parser.c \
				srcs/pipe.c \
				srcs/token_utils.c \
				srcs/builtins/echo_utils.c \


NAME_OS = MAC
endif
ifeq ($(NAME_OS), Linux)
        SRC = srcs/main.c \
				libft/ft_putchar_fd.c \
				libft/ft_putstr_fd.c \
				libft/*.c \
				srcs/main_utils.c \
				srcs/main_utils_2.c \
				srcs/builtins/cd.c \
				srcs/builtins/echo.c \
				srcs/builtins/env.c \
				srcs/builtins/exit.c \
				srcs/builtins/exit_utils.c \
				srcs/builtins/export.c \
				srcs/builtins/export_utils.c \
				srcs/builtins/pwd.c \
				srcs/signal.c \
				srcs/init_global.c \
				srcs/builtins/unset.c \
				srcs/add_link.c \
				srcs/new_link.c \
				srcs/change_fd.c \
				srcs/cmd_utils.c \
				srcs/exec_utils.c \
				srcs/exec.c \
				srcs/expand_utils.c \
				srcs/expand.c \
				srcs/free_data.c \
				srcs/init_cmd.c \
				srcs/init_data.c \
				srcs/init_data_utils.c \
				srcs/lexer.c \
				srcs/lexer_utils.c \
				srcs/make_token.c \
				srcs/no_expand_quote.c \
				srcs/no_expand_utils.c \
				srcs/parser.c \
				srcs/pipe.c \
				srcs/token_utils.c \
				srcs/builtins/echo_utils.c \

endif

OBJ = *.o

FLAGS = -Wall -Wextra -Werror

LIBFT_A = libft.a
LIBFT_DOSSIER = libft/
LIBFT  = $(addprefix $(LIBFT_DOSSIER), $(LIBFT_A))

WHITE ='\033[0m'
BLUE ='\033[36m'
CYAN ='\033[1;32m'


all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CYAN) "Compilation en cours de $(NAME) sur l'OS \"$(NAME_OS)\"" $(WHITE)
	@make -C $(LIBFT_DOSSIER)
	@gcc $(FLAGS) $(LIBFT) $(OBJ) -o $(NAME) -lreadline
	@echo ""
	@echo $(BLUE)"Tout a été compilé avec succès ! -"$(WHITE)

$(OBJ): $(SRC)
	@echo $(CYAN) "Creation des fichiers .o." $(WHITE)
	@gcc $(FALGS) -c $(SRC)

clean:
	@echo "Suppression en cours des fichiers .o de $(NAME) et de la libft"
	@echo $(CYAN) "Suppression des fichiers .o de $(NAME)." $(WHITE)
	@echo $(CYAN) "Suppression des fichiers .o de la libft." $(WHITE)
	@rm -f $(OBJ)
	@make -C $(LIBFT_DOSSIER) clean
	@echo "Nettoyage des fichiers .o effectué"

fclean: clean
	@echo $(CYAN) "Suppression du logiciel $(NAME)." $(WHITE)
	@rm -rf $(NAME)
	@make -C $(LIBFT_DOSSIER) fclean
	@echo "Tout a été supprimé !"

re: fclean all
