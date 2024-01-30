SORTERS = sorters/5_and_less.c sorters/algo.c
UTILS = utils/helper_utils_2.c utils/analytic_utils_1.c utils/analytic_utils_2.c utils/helper_utils_1.c utils/conversion_utils.c utils/parser.c utils/general_utils.c utils/linked_list_utils_1.c utils/linked_list_utils_2.c utils/normal_moves.c utils/mixed_moves.c utils/rank_utils.c utils/search_utils.c
SRC = push_swap.c $(SORTERS) $(UTILS)
OBJ = $(SRC:.c=.o)
CC = cc
FLAGS = -Wall -Wextra -Werror
HEADER = push_swap.h
NAME = push_swap
INCLUDE = push_swap.h

BONUS_NAME = checker
BONUS_DIR = bonus_checker
BONUS_SRC = $(BONUS_DIR)/utils/bonus_printing_utils.c $(BONUS_DIR)/utils/bonus_execution_utils.c $(BONUS_DIR)/utils/bonus_rank_utils.c $(BONUS_DIR)/utils/bonus_parser.c $(BONUS_DIR)/utils/bonus_normal_moves.c $(BONUS_DIR)/utils/bonus_mixed_moves.c $(BONUS_DIR)/utils/bonus_linked_list_utils_1.c $(BONUS_DIR)/utils/bonus_linked_list_utils_2.c $(BONUS_DIR)/utils/bonus_general_utils.c $(BONUS_DIR)/utils/bonus_conversion_utils.c $(BONUS_DIR)/utils/get_next_line/bonus_get_next_line.c $(BONUS_DIR)/utils/get_next_line/bonus_get_next_line_utils.c $(BONUS_DIR)/$(BONUS_DIR).c
BONUS_OBJ = $(BONUS_SRC:.c=.o)
BONUS_INCLUDE = $(BONUS_DIR)/bonus_checker.h

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
	$(CC) $(FLAGS) -g $^ -o $(BONUS_DIR)/$@

bonus_%.o: %.c $(BONUS_INCLUDE)
	$(CC) $(FLAGS) -c $< -o $@

bonus_clean:
	rm -f $(BONUS_OBJ)

bonus_fclean: bonus_clean
	rm -f $(BONUS_DIR)/$(BONUS_NAME)

bonus_re: bonus_fclean bonus

clean_all: clean bonus_clean

fclean_all: fclean bonus_fclean

both_clean: all bonus clean_all

.PHONY: all clean fclean re bonus_clean bonus_fclean bonus_re clean_all fclean_all both_clean 
