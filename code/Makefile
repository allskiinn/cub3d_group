# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliberal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/29 13:47:16 by asobrinh          #+#    #+#              #
#    Updated: 2025/04/22 23:33:58 by aliberal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# BASIC
CC = gcc -g
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
NAME = fdf
SRCS =  ./src/connect_point.c \
        ./src/functions_utils.c \
        ./src/functions_utils2.c \
        ./src/ft_error.c \
        ./src/init_struct.c \
        ./src/check_key.c \
        ./src/printf_menu.c \
        ./src/read_file.c \
        ./src/fdf.c

OBJSDIR = objectos
OBJS = $(addprefix $(OBJSDIR)/,$(SRCS:.c=.o))

# MAKE
all: $(NAME)

$(LIBFT):
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFT) .

$(MINILIBX):
	@make -C $(MINILIBXDIR)
	@cp $(MINILIBXDIR)/$(MINILIBX) .

$(NAME): $(LIBFT) $(MINILIBX) $(OBJS)
	@$(CLEAR)
	@echo "$(GREEN)$(BOLD)Criando executavel...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) -L. -lft -L. -lmlx $(WINDOWS_MATH) -o $(NAME)
	@echo "$(GREEN)$(BOLD)Executavel criado!$(RESET)"

$(OBJSDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(CLEAR)
	@echo "$(YELLOW)$(BOLD)Removendo objectos...$(RESET)"
	$(RM) $(OBJSDIR)
	@make -C $(LIBFTDIR) clean
	@make -C $(MINILIBXDIR) clean
	@echo "$(YELLOW)$(BOLD)Objectos removidos!$(RESET)"

fclean: clean
	@$(CLEAR)
	@echo "$(RED)$(BOLD)Removendo executavel...$(RESET)"
	$(RM) $(NAME)
	$(RM) $(LIBFT) $(MINILIBX)
	@make -C $(LIBFTDIR) fclean
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
	norminette ./libft/*.c
	norminette ./libft/*.h

.PHONY: clean fclean all re

.SILENT: