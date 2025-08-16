NAME            = 	pipex
NAME_BONUS		= 	pipex_bonus

SRC_DIR         = 	srcs

OBJ_DIR         = 	objs
INC_DIR         = 	includes
LIBFT_DIR 		= 	./libft
LIBFT_A 		=	$(LIBFT_DIR)/libft.a

SRCS 			=	./srcs/main.c ./srcs/parsing.c ./srcs/process.c ./srcs/parsing2.c

BONUS		=	./bonus/main_bonus.c ./bonus/parsing_bonus.c ./bonus/utils.c ./bonus/utils2.c ./bonus/process_bonus.c

OBJS        	= 	$(SRCS:%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS		=	$(BONUS:%.c=$(OBJ_DIR)/%.o)

CC          	= 	cc -g
CFLAGS      	= 	-Wall -Wextra -Werror
RM          	= 	rm -f

all: $(NAME)
bonus: $(NAME_BONUS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT_A) -o $(NAME_BONUS)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus