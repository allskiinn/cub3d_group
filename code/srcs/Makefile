# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asobrinh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/29 13:47:16 by asobrinh          #+#    #+#              #
#    Updated: 2025/03/29 13:47:20 by asobrinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main_cub.c verif_janela.c
OBJS = $(SRCS:.c=.o)
MLX_DIR = minilibx-linux
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS) $(MLX_DIR)/libmlx.a
	@$(CC) $(OBJS) -o $(NAME) $(MLX)

$(MLX_DIR)/libmlx.a:
	@make -C $(MLX_DIR) --no-print-directory

%.o: %.c
	@$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -C $(MLX_DIR) clean --no-print-directory

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

