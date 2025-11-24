# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vephan <vephan@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/17 12:59:10 by vephan            #+#    #+#              #
#    Updated: 2025/10/18 08:53:44 by vephan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############################################################################
##### CONFIGURATION

NAME        = libftprintf.a
CC          = cc
OPTIONS     = -Wall -Werror -Wextra
HEADER      = -I .

ROOT_DIR    = .
LIBFT_DIR   = libft

#############################################################################
##### SOURCES

SRC_FILES = ft_print \
				ft_write_s \
				ft_write_hex \
				ft_write_i \
				ft_write_u \
				ft_write_p \
				ft_convert \
				ft_write_c

LIBFT_SRC = ft_isalpha \
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
				ft_putnbr_fd

LIBFT_BONUS_SRC = ft_lstnew_bonus \
				ft_lstadd_front_bonus \
				ft_lstsize_bonus \
				ft_lstlast_bonus \
				ft_lstadd_back_bonus \
				ft_lstdelone_bonus \
				ft_lstclear_bonus \
				ft_lstiter_bonus \
				ft_lstmap_bonus

#############################################################################
##### OBJECTS

OBJ_FILES           = $(addsuffix .o, $(SRC_FILES))
LIBFT_OBJ           = $(addprefix $(LIBFT_DIR)/, $(addsuffix .o, $(LIBFT_SRC)))
LIBFT_BONUS_OBJ     = $(addprefix $(LIBFT_DIR)/, $(addsuffix .o, $(LIBFT_BONUS_SRC)))

#############################################################################
##### RULES

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT_OBJ) $(LIBFT_BONUS_OBJ)
	ar rcs $(NAME) $(OBJ_FILES) $(LIBFT_OBJ) $(LIBFT_BONUS_OBJ)

%.o: %.c
	$(CC) $(OPTIONS) $(HEADER) -c $< -o $@

$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c
	$(CC) $(OPTIONS) $(HEADER) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(LIBFT_OBJ) $(LIBFT_BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft