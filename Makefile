SORTERS = sorters/5_and_less.c sorters/algo.c
UTILS = utils/conversion_utils.c utils/parser.c utils/general_utils.c utils/linked_list_utils.c utils/normal_moves.c utils/mixed_moves.c utils/rank_utils.c utils/search_utils.c
SRC = push_swap.c $(SORTERS) $(UTILS)
FLAGS = -Wall -Wextra -Werror
RM = rm -f
CC = gcc
HEADER = push_swap.h
NAME = push_swap

# BONUS_UTILS = checker/utils/*.c checker/utils/get_next_line/*.c
# BONUS_SRC = checker/checker.c $(BONUS_UTILS)
# CHECKER_NAME = checker

all: $(NAME)

$(NAME): $(SRC)
	@($(CC) -g $^ -o $@)

fclean: 
	@($(RM) $(NAME))

re: fclean all

.PHONY: all fclean re