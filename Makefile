NAME		= push_swap
BONUS_NAME	= checker
LIBFT		= libft/libft.a
SRC			= src/init_stacks.c src/rotate_to_top.c src/sort_three.c src/set_cost.c src/final_sort.c src/presort.c src/operators.c src/operate_init.c src/error_handling.c src/validate_input.c
MAIN_SRC	= src/push_swap.c
BONUS_SRC	= src/bonus/checker_bonus.c
OBJ			= $(SRC:.c=.o)
MAIN_OBJ	= $(MAIN_SRC:.c=.o)
BONUS_OBJ	= $(BONUS_SRC:.c=.o)
CFLAGS			= -Wall -Wextra -Werror
CC				= cc

all: $(NAME)

$(NAME): $(MAIN_OBJ) $(OBJ)
	@$(MAKE) -C libft
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	@$(MAKE) -C libft clean
	rm -f $(MAIN_OBJ) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

bonus: $(BONUS_OBJ) $(OBJ)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(OBJ) $(LIBFT) -o $(BONUS_NAME)

.PHONY: all clean fclean re bonus