# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vboivin <marvin42.fr>                     +#+   +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/17 14:50:04 by vboivin           #+#    #+#              #
#    Updated: 2017/04/07 13:12:35 by vboivin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_ls
HPATH		= includes
MLXPATH		= minilibx
INC			= -I$(HPATH) -Ilibft
FLAGS		= -Wall -Werror -Wextra
COMP		= gcc
LIBFT		= -Llibft -lft

SRCS 		= main.c sort.c options.c listing.c
DIR_SRC		= $(addprefix $(SRCPATH)/, $(SRCS))
SRCPATH		= src

OBJ 		= $(SRCS:.c=.o)
DIR_OBJ		= $(addprefix $(OBJPATH)/, $(OBJ))
OBJPATH		= obj

all: $(NAME)

$(OBJPATH)/%.o: $(SRCPATH)/%.c
	@printf "Compiling $<\r"
	@$(COMP) $(FLAGS) -c $< -o $@ $(INC)

$(NAME): $(DIR_OBJ)
	@make -C libft
	@make -C $(MLXPATH)
	@$(COMP) $(DIR_OBJ) -o $(NAME) $(INCMAC) $(LIBFT) $(FLAGS)

clean:
	@make clean -C $(MLXPATH)
	@make clean -C libft
	@rm -rf $(OBJ)

fclean:
	@make clean -C $(MLXPATH)
	@make fclean -C libft
	@rm -rf $(DIR_OBJ)

re: fclean all
