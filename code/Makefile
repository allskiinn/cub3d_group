# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliberal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/20 13:47:16 by aliberal          #+#    #+#              #
#    Updated: 2025/06/08 21:02:43 by aliberal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# BASIC
CC = cc -g
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
LIBFT = libft.a
MINILIBX = libmlx.a

LIBFTDIR = ./libft
MINILIBXDIR = ./minilibx-linux

WINDOWS_MATH = -lX11 -lXext -lXcursor -lm
CLEAR = clear

# colors
RESET            := \033[0m
GREEN            := \033[32m
CYAN             := \033[1;36m
YELLOW           := \033[33m
BLUE             := \033[34m
WHITE            := \033[00m
RED              := \033[1;31m
BOLD             := \033[1;1m

# CUB3D
NAME = cub3d
SRCS =  ./srcs/error/error.c \
			./srcs/error/error_info_map.c \
			./srcs/init/init.c \
			./srcs/init/init_check.c \
			./srcs/parser/parsing.c \
			./srcs/parser/parsing_color_resolution.c \
			./srcs/parser/parsing_map.c \
			./srcs/parser/parsing_texture.c \
			./srcs/raycasting/raycasting.c \
			./srcs/raycasting/raycasting_texture.c \
			./srcs/raycasting/raycasting_steps.c \
			./srcs/raycasting/raycasting_move.c \
			./srcs/raycasting/raycsting_textura_util.c \
			./srcs/key/key_press.c \
			./srcs/utils/aux1.c \
			./srcs/utils/aux2.c \
			./srcs/utils/aux3.c \
			./srcs/utils/aux4.c \
			./srcs/utils/aux5.c \
			./srcs/utils/aux6.c \
			./srcs/utils/aux7.c \
			./srcs/utils/aux8.c \
			./srcs/utils/get_next_line.c \
			./srcs/utils/get_next_line_utils.c \
			./srcs/utils/get_next_line_utils1.c \
			./srcs/main.c

OBJSDIR = objectos
OBJS = $(addprefix $(OBJSDIR)/,$(SRCS:.c=.o))

# MAKE
all: $(NAME)

$(MINILIBX):
	@make -C $(MINILIBXDIR)
	@cp $(MINILIBXDIR)/$(MINILIBX) .

$(NAME): $(MINILIBX) $(OBJS)
	@$(CLEAR)
	@echo "$(GREEN)$(BOLD)Criando executavel...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) -L. -L. -lmlx $(WINDOWS_MATH) -o $(NAME)
	@echo "$(GREEN)$(BOLD)Executavel criado!$(RESET)"

$(OBJSDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(CLEAR)
	@echo "$(YELLOW)$(BOLD)Removendo objectos...$(RESET)"
	$(RM) $(OBJSDIR)
	@make -C $(MINILIBXDIR) clean
	@echo "$(YELLOW)$(BOLD)Objectos removidos!$(RESET)"

fclean: clean
	@$(CLEAR)
	@echo "$(RED)$(BOLD)Removendo executavel...$(RESET)"
	$(RM) $(NAME)
	$(RM) $(MINILIBX)
	@echo "$(RED)$(BOLD)Executavel removido!$(RESET)"

re: fclean all
	@$(CLEAR)
	@echo "$(GREEN)$(BOLD)Recompilado com sucesso!$(RESET)"

norm:
	@$(CLEAR)
	@echo "$(GREEN)$(BOLD)Norminette!$(RESET)"
	norminette ./includes/*
	norminette ./srcs/*

.PHONY: clean fclean all re

.SILENT:
