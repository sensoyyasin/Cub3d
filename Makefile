# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 12:28:00 by yasinsensoy       #+#    #+#              #
#    Updated: 2023/02/23 17:29:19 by ysensoy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d
SRC = $(wildcard *.c)
CC = gcc -Wall -Wextra -Werror
CFLAGS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ./libft/libft.a -lmlx -framework OpenGL -framework AppKit -L ./minilibx

all : $(NAME)

$(NAME):
	$(CC) *.c $(CFLAGS) -o Cub3d
	@echo "\033[1;92mCompiled succesfully..\033[0m"

clean:
	rm -rf Cub3d

fclean: clean

re: clean fclean all

#NAME = Cub3d
# CC = gcc
# CLAFGS = -Wall -Wextra -Werror
# SRCS = $(wildcard *.c)
# OBJ = $(SRCS:.c = .o)

# $(NAME): $(OBJ)
# 	@$(CC) $(CLAFGS) $(SRCS) -o $(NAME)
# 	@echo "\033[1;92mCompiled succesfully..\033[0m"

# all: $(NAME)

# clean:
# 	rm -rf  $(NAME)

# fclean: clean


# re: fclean all

# .PHONY: all clean fclean re