# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmartins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/24 15:24:58 by vmartins          #+#    #+#              #
#    Updated: 2017/09/20 11:52:01 by vmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name
NAME = minishell

#Flag
FLAGS = -Wall -Wextra -Werror -g

#SRCS
SRCS = srcs/minishell.c \
	   srcs/get_next_line.c \
	   srcs/ft_exit.c \
	   srcs/check_builtins.c \
	   srcs/env.c \
	   srcs/unsetenv.c \
	   srcs/echo.c \
	   srcs/error.c \
	   srcs/setenv.c \
	   srcs/cd.c \

#INCLUDES
INCLUDES = includes/minishell.h


#COLORS
C_NO ="\033[00m"
C_OK ="\033[35m"
C_GOOD = "\033[32m"
C_ERROR = "\033[31m"
C_WARN = "\033[33m"

#DBG MESSAGE
SUCCESS= $(C_GOOD)SUCCESS$(C_NO)
OK = $(C_OK)OK$(C_NO)

#Objects
OBJ=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling" [$(NAME)] "..."
	@make -C libft/
	@gcc -I includes libft/libft.a -o $(NAME) $(SRCS) -g
	@clear
	@echo "Compiling" [$(NAME)] $(SUCCESS)
	#@cat ~/banner_minishell

%.o: %.c
	@gcc -I includes -o $@ -c $< $(FLAGS)

clean:
	@rm -rf $(OBJ) $(OBJ_MAIN)
	@make clean -C libft/
	@echo "Cleaning" [$(NAME)] "..." $(OK)

fclean: clean
	@rm -f $(NAME) $(LIB)
	@make fclean -C libft/
	@echo "Delete" [$(NAME)] $(OK)

re: fclean all

.PHONY: all clean fclean re
