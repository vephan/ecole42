##################################################################################################
##ARGUMENTS
NAME       = libft.a
CFLAGS     = -Wall -Wextra -Werror
CC         = cc

##################################################################################################
## SOURCES
HEADER_PATH     = .
HEADER          = -I $(HEADER_PATH)

SRC_FILES = ft_isalpha \
			ft_isdigit \
			ft_isalnum \
			ft_isprint \
			ft_isascii \
 			ft_strlen \
			ft_memset \
			ft_bzero \
			ft_memcpy \
			ft_memmove \
			ft_strlcpy \
			ft_strlcat \
 			ft_toupper \
			ft_tolower \
			ft_strchr \
			ft_strrchr \
			ft_strncmp \
			ft_memchr \
			ft_memcmp \
			ft_strnstr \
			ft_atoi \
			ft_calloc \
			ft_strdup \
			ft_substr \
			ft_strjoin \
			ft_strtrim \
			ft_split \
			ft_itoa \
			ft_strmapi \
			ft_striteri \
			ft_putchar_fd \
			ft_putstr_fd \
			ft_putendl_fd \
			ft_putnbr_fd \

OBJ_FILES = $(addsuffix .o, $(SRC_FILES))

BONUS_FILES = ft_lstnew_bonus \
			ft_lstadd_front_bonus \
			ft_lstsize_bonus \
			ft_lstlast_bonus \
			ft_lstadd_back_bonus \
			ft_lstdelone_bonus \
			ft_lstclear_bonus \
			ft_lstiter_bonus \
			ft_lstmap_bonus \

BONUS_OBJ_FILES = $(addsuffix .o, $(BONUS_FILES))

##################################################################################################
## RULES
all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

bonus: $(NAME) $(BONUS_OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES) $(BONUS_OBJ_FILES) 

%.o: %.c
	$(CC) $(CFLAGS) $(OPTION) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(BONUS_OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
