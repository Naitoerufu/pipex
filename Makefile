# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 16:51:42 by mmaksymi          #+#    #+#              #
#    Updated: 2025/02/11 12:27:06 by mmaksymi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra #-Wno-unused-but-set-variable

NAME = pipex

SRCS = srcs/main.c \
		srcs/utils.c \
		srcs/arg_pars.c \
		srcs/files.c \
		srcs/main_part.c
	
OFILES = $(SRCS:.c=.o)

LIBFT_NAME = libft.a
LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

CC = cc

all: $(NAME)

$(LIBFT): $(LIBFT_DIR)
	make -C $(LIBFT_DIR) $(LIBFT_NAME)

$(NAME): $(OFILES) $(LIBFT)
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(OFILES)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME) $(OFILES)

re: fclean $(NAME)

run: re
	./$(NAME)
