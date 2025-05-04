# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliberal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/29 13:47:16 by asobrinh          #+#    #+#              #
#    Updated: 2025/05/04 04:10:13 by aliberal         ###   ########.fr        #
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

# FDF
NAME = cub3d
SRCS =  ./srcs/error/error.c \
        ./srcs/init/init.c \
        ./srcs/parser/parsing.c \
		./srcs/parser/parsing_color_resolution.c \
		./srcs/parser/parsing_map.c \
		./srcs/parser/parsing_texture.c \
		./srcs/utils/aux1.c \
		./srcs/utils/aux2.c \
		./srcs/utils/get_next_line.c \
		./srcs/utils/get_next_line_utils.c \
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

push:
	@$(CLEAR)
	@echo "$(GREEN)$(BOLD)Projecto enviado com sucesso!$(RESET)"
	git add .
	git commit -m "fdfFinished"
	git push
	git status

norm:
	@$(CLEAR)
	@echo "$(GREEN)$(BOLD)Norminette!$(RESET)"
	norminette ./includes/*
	norminette ./srcs/*

.PHONY: clean fclean all re

.SILENT: