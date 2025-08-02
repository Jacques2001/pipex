NAME            = 	pipex

SRC_DIR         = 	srcs

OBJ_DIR         = 	objs
INC_DIR         = 	includes
LIBFT_DIR 		= 	./libft
LIBFT_A 		=	$(LIBFT_DIR)/libft.a

SRCS 			=	./srcs/main.c ./srcs/parsing.c ./srcs/process.c

OBJS        	= 	$(SRCS:%.c=$(OBJ_DIR)/%.o)

CC          	= 	cc -g
CFLAGS      	= 	-Wall -Wextra -Werror
RM          	= 	rm -f

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re