NAME = ft_select
CC = clang

LIBFT = ./lib/libft/libft.a
INCLUDES  = -I./includes/
INCLUDES += -I./lib/libft/

SRC_PATH = ./srcs/
SRC_FILES = arg.c colors.c do_action.c do_move.c init.c \
			input.c main.c printer.c select.c set_termcap.c \
			signal_handler.c fatal_error.c

SRC = 	$(addprefix $(SRC_PATH), $(SRC_FILES))


FLAG = -Wall -Werror -Wextra -g
OBJ = $(SRC:.c=.o)
OBJ = *.o

CG = \033[92m
all: start $(NAME)

$(NAME):
	@make -sC ./lib/libft/
	@$(CC)  -c $(FLAG) $(SRC) $(INCLUDES)
	@$(CC)  -ltermcap -o $(NAME) $(OBJ) -L. $(LIBFT) $(INCLUDES)

	@echo "\r$(CY)------------ GO -----------------"

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

clean:
	@make clean -sC lib/libft/
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -sC lib/libft/
	@rm -rf $(NAME)

re: fclean all clean
