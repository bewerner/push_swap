NAME					=	libft.a

CFILES					=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
							ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
							ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c \
							ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
							$(BONUS_CFILES) $(ADDED_CFILES) $(GET_NEXT_LINE_CFILES) $(FT_PRINTF_CFILES)

BONUS_CFILES			=	ft_lstnew.c ft_lstadd_front.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
							ft_lstclear.c ft_lstiter.c ft_lstmap.c

ADDED_CFILES			=	ft_isspace.c

GET_NEXT_LINE_CFILES	=	get_next_line/get_next_line.c

FT_PRINTF_CFILES		=	ft_printf/ft_printf_bonus.c ft_printf/ft_printf_bonus.c ft_printf/ft_printf_con_init_bonus.c \
							ft_printf/ft_printf_set_s_bonus.c ft_printf/ft_printf_set_len_con_bonus.c \
							ft_printf/ft_printf_putchar_bonus.c

OFILES					=	$(CFILES:.c=.o)

CFLAGS					=	

CC						=	cc

all: $(NAME)

$(NAME): $(OFILES)
	ar -rcs $(NAME) $(OFILES)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re