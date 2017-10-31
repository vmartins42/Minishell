# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmartins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/23 14:41:11 by vmartins          #+#    #+#              #
#    Updated: 2017/10/10 13:54:48 by vmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_memmove.c ft_memchr.c ft_strsplit.c ft_itoa.c ft_lstnew.c ft_lstfree.c ft_lstadd.c ft_lstpushback.c ft_lstdel.c ft_del.c ft_tablen.c ft_words.c ft_puttab.c ft_tabpushback.c ft_tabcreate.c ft_freetab.c ft_tabdup.c ft_tabtospace.c ft_join_tab.c ft_escapequote.c ft_isenv.c ft_getcwd.c ft_removelastslash.c ft_theirisnothing.c ft_removendslash.c ft_triplejoin.c

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Werror -Wextra $(SRC)
	@ar rc libft.a $(SRC:.c=.o)
	@ranlib libft.a

clean:
	@rm -rf $(SRC:.c=.o)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
