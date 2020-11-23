# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/24 15:42:48 by anorjen           #+#    #+#              #
#    Updated: 2020/11/23 10:58:06 by anorjen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

CC = clang
FLAGS = -Wall -Werror -Wextra -g
LIBRARIES = -lft -ltermcap -L$(LIBFT_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)/includes

HEADERS_LIST = 	ft_select.h \
				newtypes.h

HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./srcs/
SOURCES_LIST = 	arg.c \
				colors.c \
				do_action.c \
				do_move.c \
				fatal_error.c \
				init.c \
				input.c \
				main.c \
				printer.c \
				select.c \
				set_termcap.c \
				signal_handler.c \
				tty.c \
				printer1.c

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: start $(NAME)

start:
	@echo "\r$(CG)compile..."
	@echo "	----------------------------------------------------------------	"
	@echo "	|   00  00         000  000000 00     000000   0000  00000000  |	"
	@echo "	|  00   00        00    00     00     00      00  00 0  00  0  |	"
	@echo "	|  000 0000        000  00     00     00     00         00     |	"
	@echo "	|  00   00           00 000000 00     000000 00         00     |	"
	@echo "	|  00   00 0      0  00 00     00   0 00      00  00    00     |	"
	@echo "	|  00   000  0000  000  000000 000000 000000   0000     00     |	"
	@echo "	----------------------------------------------------------------	"

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS) $(HEADERS)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) $(LIBRARIES) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)$(NAME) object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
