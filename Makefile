NAME			= push_swap
LIBFT			= libft/libft.a
CFILES			= push_swap.c rotate_to_top.c sort_three.c set_cost.c final_sort.c presort.c operators.c operate_init.c error_handling.c validate_input.c
BONUS_CFILES	=
OFILES			= $(CFILES:.c=.o)
BONUS_OFILES	= $(BONUS_CFILES:.c=.o)
CFLAGS			= -Wall -Wextra -Werror
CC				= cc
TEST			= ./$(NAME) -4 -10 5 7 -2 3 1 -5 8 -3 -6 -1 2 -9 6 4 9 -7 0 -8 10

all: $(NAME)

$(NAME): $(OFILES)
	@$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT) -o $(NAME)

clean:
	@$(MAKE) -C libft clean
	rm -f $(OFILES) $(BONUS_OFILES)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

bonus: fclean $(BONUS_OFILES)
	ar -rcs $(NAME) $(BONUS_OFILES)

test: all
	@$(CC) $(CFLAGS) $(OFILES) $(LIBFT) -o $(NAME)
	@echo
	$(TEST)

.PHONY: all clean fclean re bonus test