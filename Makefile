# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaleman <jraleman@student.42.us.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 18:18:00 by jaleman           #+#    #+#              #
#    Updated: 2019/02/15 18:18:01 by jaleman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_tar
SRC			= $(wildcard src/*.c)

INC			= includes/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I $(INC)
OBJ			= $(SRC:.c=.o)
DEBUG		= -g3 -fsanitize=address

all: $(NAME)
%.o: %.c
	@printf "[$(NAME)] Compiling [.:]\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[$(NAME)] Compiling [:.]\r"

$(NAME): $(OBJ)
	@printf "[$(NAME)] Compiled successfuly! [OK]\n"
	@gcc $(CFLAGS) $(OBJ) -o $(NAME)
debug: $(OBJ)
	@printf "[$(NAME)] Compiled debug successfuly! [OK]\n"
	@gcc $(CFLAGS) $(DEBUG) $(OBJ) -o $(NAME)
clean:
	@/bin/rm -f $(OBJ)
	@printf "[$(NAME)] Removed object files!\n"
fclean: clean
	@/bin/rm -f $(NAME)
	@printf "[$(NAME)] Removed $(NAME) binary!\n"
re: fclean all

.PHONY: all clean fclean re