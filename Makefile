SORTERS = sorters/5_and_less.c sorters/algo.c
UTILS = utils/conversion_utils.c utils/parser.c utils/general_utils.c utils/linked_list_utils.c utils/moves.c utils/lis_utils.c
SRC = push_swap.c $(SORTERS) $(UTILS)
FLAGS = -Wall -Wextra -Werror
RM = rm -f
CC = gcc
HEADER = push_swap.h
NAME = push_swap

all: $(NAME)

$(NAME): $(SRC)
	@($(CC) -g $^ -o $@)

fclean: 
	@($(RM) $(NAME))

re: fclean all

.PHONY: all fclean re

run: $(NAME)
	@(./$(NAME) $(ARGS))
