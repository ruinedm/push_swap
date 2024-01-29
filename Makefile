SORTERS = sorters/5_and_less.c sorters/algo.c
UTILS = utils/analytic_utils_1.c utils/analytic_utils_2.c utils/math_utils.c utils/conversion_utils.c utils/parser.c utils/general_utils.c utils/linked_list_utils_1.c utils/linked_list_utils_2.c utils/normal_moves.c utils/mixed_moves.c utils/rank_utils.c utils/search_utils.c
SRC = push_swap.c $(SORTERS) $(UTILS)
OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = push_swap.h
NAME = push_swap
INCLUDE = push_swap.h

BONUS_NAME = checker
BONUS_SRC = bonus_checker/utils/bonus_execution_utils.c bonus_checker/utils/bonus_rank_utils.c bonus_checker/utils/bonus_parser.c bonus_checker/utils/bonus_normal_moves.c bonus_checker/utils/bonus_mixed_moves.c bonus_checker/utils/bonus_linked_list_utils_1.c bonus_checker/utils/bonus_linked_list_utils_2.c bonus_checker/utils/bonus_general_utils.c bonus_checker/utils/bonus_conversion_utils.c bonus_checker/utils/get_next_line/bonus_get_next_line.c bonus_checker/utils/get_next_line/bonus_get_next_line_utils.c bonus_checker/bonus_checker.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)
BONUS_INCLUDE = bonus_checker/bonus_checker.h
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.c $(INCLUDE)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(FLAGS) -g $^ -o bonus_checker/$@
	mv bonus_checker/$(BONUS_NAME) .

bonus_%.o: %.c $(BONUS_INCLUDE)
	$(CC) $(FLAGS) -c $< -o $@

bonus_clean:
	rm -f $(BONUS_OBJ)

bonus_fclean: bonus_clean
	rm -f $(BONUS_NAME)

bonus_re: bonus_fclean bonus

clean_all: clean bonus_clean

fclean_all: fclean bonus_fclean

.PHONY: all clean fclean re
