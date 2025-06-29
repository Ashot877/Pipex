# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asmkrtch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 17:21:15 by asmkrtch          #+#    #+#              #
#    Updated: 2025/06/23 17:21:17 by asmkrtch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRC = main.c\
	check_validation.c\
	create_pipe.c\
	fill_s.c\
	find_path.c\
	free.c\
	pipex.c\
	error.c\
	error2.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

INCLUDES = -I. -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --silent

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR) --silent

$(NAME): $(OBJ)
	@echo "Compiling main project..."
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo "✅ Build complete: $(NAME)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(FT_PRINTF_DIR) --silent clean
	@$(MAKE) -C $(LIBFT_DIR) --silent clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(FT_PRINTF_DIR) --silent fclean
	@$(MAKE) -C $(LIBFT_DIR) --silent fclean

re: fclean all

.PHONY: all clean fclean re
