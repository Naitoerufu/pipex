# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 16:51:42 by mmaksymi          #+#    #+#              #
#    Updated: 2025/02/13 12:20:28 by mmaksymi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra #-Wno-unused-but-set-variable

SRCS = ft_isalpha.c \
       ft_isdigit.c \
       ft_isalnum.c \
       ft_isascii.c \
       ft_isprint.c \
       ft_strlen.c \
       ft_memset.c \
       ft_bzero.c \
       ft_memcpy.c \
       ft_memmove.c \
       ft_strlcpy.c \
	   ft_strcat.c \
       ft_strlcat.c \
       ft_toupper.c \
       ft_tolower.c \
       ft_strchr.c \
       ft_strrchr.c \
	   ft_strcmp.c \
       ft_strncmp.c \
       ft_memchr.c \
       ft_memcmp.c \
       ft_strnstr.c \
       ft_atoi.c \
       ft_calloc.c \
       ft_strdup.c \
       ft_substr.c \
       ft_strjoin.c \
       ft_strtrim.c \
       ft_split.c \
       ft_itoa.c \
       ft_strmapi.c \
       ft_striteri.c \
       ft_putchar_fd.c \
       ft_putstr_fd.c \
       ft_putendl_fd.c \
       ft_putnbr_fd.c \
	   ft_printf/ft_puthex.c \
	   ft_printf/ft_putlonghex.c \
	   ft_printf/ft_putptr.c \
	   ft_printf/ft_putu.c \
	   ft_printf/ft_strtolower.c \
	   ft_printf/main.c \
	   get_next_line/get_next_line.c

OFILES = $(SRCS:.c=.o)

BONUSSRCS = ft_lstnew_bonus.c \
	    ft_lstadd_front_bonus.c \
	    ft_lstsize_bonus.c \
	    ft_lstlast_bonus.c \
	    ft_lstadd_back_bonus.c \
	    ft_lstdelone_bonus.c \
	    ft_lstclear_bonus.c \
	    ft_lstiter_bonus.c \
	    ft_lstmap_bonus.c

BONUSOFILES = $(BONUSSRCS:.c=.o)

NAME = libft.a

CC = cc

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean:
	rm -rf $(OFILES) $(BONUSOFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

bonus: $(BONUSOFILES) $(OFILES)
	ar rcs $(NAME) $(OFILES) $(BONUSOFILES)
