#################### VARIABLES
NAME      = push_swap
CC        = cc 
CFLAGS    = -Wall -Wextra -Werror -g
HEADER    = -I. -Ilibft -Ift_printf
LIBFT     = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a

#################### FILES
SRC       = main.c \
			ps_push.c \
			ps_swap.c \
			ps_rotate.c \
			ps_rrotate.c

OBJ       = $(SRC:.c=.o)

#################### RULES
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(HEADER) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re