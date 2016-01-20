# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhasni <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/08 10:42:06 by zhasni            #+#    #+#              #
#    Updated: 2014/12/08 11:49:10 by zhasni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= 	ft_rgbtoi.c \
				fdf.c \
				get_next_line.c \
				hook.c \
				display.c \
				main.c

NAME		= 	fdf
CC			= 	gcc
CFLAGS		= 	-Werror -Wextra -Wall
MLX			=	-L/usr/X11/lib -lmlx -lXext -lX11
AR			= 	ar rc
OBJ			= 	$(SRC:.c=.o)
RM			= 	rm -rf 
INCLUDES	=	libft/includes
LIBFT		=	libft/
HEADERS		=	-I./. -Ilibft/includes
LIB			=	libft.a

all: $(LIB) $(NAME)
	@echo "Ship in sight Cap'tain !!!!! ALL ABOARD !!!!!";
$(LIB):
	@echo "Trying to compile libft.a...";
	@make -C $(LIBFT)

$(NAME): $(OBJ)
	@echo "Painting Ship...";
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) -L libft/ -lft
	@echo "Ship ready to sail.";

%.o: %.c
	@echo "Compiling $<";
	@$(CC) $(CFLAGS) -c $< $(HEADERS) -o $@ $(MLX) -L libft/ -lft

clean:
	@echo "Destroying Objects, Pirates we are !";
	@make clean -C $(LIBFT)
	@$(RM) $(OBJ)
	@echo "Opening rhum bottle.";
fclean: clean
	@echo "Cleaning Library from Gold Pieces...";
	@make fclean -C $(LIBFT)
	@$(RM) $(NAME)
	@echo "Swiming in gold...";
re: fclean all

.PHONY: all clean fclean re

