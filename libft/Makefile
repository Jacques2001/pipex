# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 14:32:08 by jchiu             #+#    #+#              #
#    Updated: 2025/07/23 14:16:37 by jchiu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c handle_format.c print_address.c print_char.c print_hex.c print_hexa.c \
	print_nbr.c print_string.c print_unsigned.c ft_printf.c get_next_line.c get_next_line_utils.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	ft_lstclear.c ft_lstiter.c ft_lstmap.c
	
OBJS	= $(SRCS:.c=.o)
OBJSB = $(BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME)

$(NAME): $(OBJS) $(OBJSB)
	$(AR) -r $(NAME) $?

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJSB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
