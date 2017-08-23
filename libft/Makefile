# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vboivin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/02 19:24:22 by vboivin           #+#    #+#              #
#    Updated: 2017/07/26 16:48:24 by vboivin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a 

LIB = 
SRCC =	ft_atoi.c ft_bzero.c ft_foreach.c ft_intlen.c ft_isalnum.c ft_isalpha.c\
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lenchar.c \
		ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
		ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
		ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
		ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_sqrt.c ft_strcat.c \
		ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
		ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
		ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
		ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
		ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
		ft_swap.c ft_tolower.c ft_toupper.c strchr_int.c free_join.c \
		ft_realloc.c get_next_line.c ft_putstr_cat.c ft_putstrn.c ft_lintlen.c\
		ft_litoa.c

SRCO =	$(SRCC:.c=.o)


HEADERS = .

all: $(NAME)

%.o: %.c libft.h Makefile
	@printf "libft:compiling $<                 \r"
	@gcc -Wall -Werror -Wextra -c $< -o $@ -I .

$(NAME): $(SRCO)
	@ar rc $(NAME) $(SRCO)
	@ranlib $(NAME)
	@printf "                                      \r"
	@printf "libft compilation:\tdone\n"

clean:
	@rm -f $(SRCO)

fclean: clean
	@rm -f $(NAME)

re: fclean
	@make
