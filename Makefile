SORTERS = sorters/5_and_less.c sorters/algo.c
UTILS = utils/conversion_utils.c utils/parser.c utils/general_utils.c utils/linked_list_utils.c utils/moves.c
SRC = push_swap.c $(SORTERS) $(UTILS)
FLAGS = -Wall -Wextra -Werror
RM = rm -f
CC = gcc
HEADER = push_swap.h
NAME = push_swap
VAL = valgrind --leak-check=full -s
TEST = 2134 458 2345 -1000 4329 543

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) -g $^ -o $@

fclean: 
	$(RM) $(NAME)

re: fclean all

test: re
	$(VAL) ./$(NAME) $(TEST)

.PHONY: all fclean
