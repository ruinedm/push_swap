/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:43:40 by mboukour          #+#    #+#             */
/*   Updated: 2024/01/30 02:49:42 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define NORMAL_NUM 2
# define COMPLICATED_INPUT 1
# define INVALID_INPUT -1

# define STACK_A 0
# define STACK_B 1
# define SILENT 3

# define TRUE 1
# define FALSE 0

# define SUCCESS 1
# define FAILURE 0

# define RX 0
# define RRX 1

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

typedef struct s_node
{
	int				data;
	int				rank;
	int				moves[2];
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

// STACK CHCKERES
int					check_duplicates(t_node *stack);
int					is_sorted(t_node *stack);

// SORTERS
void				sort3(t_node **stack_a);
void				sort4(t_node **stack_a);
void				sort5(t_node **stack_a);
void				sort_all(t_node **stack_a, int stack_size);

// MOVES
void				px(t_node **s_stack, t_node **r_stack, int flag);
void				rx(t_node **stack, int flag);
void				rrx(t_node **stack, int flag);
void				sx(t_node **stack, int flag);
void				ss(t_node **stack_a, t_node **stack_b);
void				rr(t_node **stack_a, t_node **stack_b);
void				rrr(t_node **stack_a, t_node **stack_b);

// GENERAL UTILS
int					ft_strlen(char *str);
void				sort_handler(t_node **stack_a, int stack_size);
void				push_smallest(t_node **s_stack, t_node **r_stack, int flag);
void				push_with_pivot(t_node **s_stack, t_node **r_stack,
						int stack_size);

// PARSING AND CONVERSION UTILS
int					ft_atoi(char *str, t_node *head);
t_node				*parser(char *argv[], int stack_size);

// RANKING UTILS
void				rank_nodes(t_node *stack_a, int stack_size);

// SEARCHING UTILS
int					get_node_position(t_node *stack, t_node *target);
t_node				*get_smallest_node(t_node *stack);
int					get_smallest_node_position(t_node *stack);

// ANALYTIC UTILS
t_node				*get_best_node(t_node *stack_a, t_node *stack_b,
						int stack_size);
t_node				*find_min_node(t_node *stack, int *choice_array,
						int stack_size);
int					get_cost(t_node *stack, t_node *target, int stack_size);
void				iterate_and_calculate(t_node *stack_a, t_node *stack_b);
t_node				*calculate_choice_array(t_node *stack_a, t_node *stack_b,
						int stack_size, int **choice_array_ptr);
t_node				*get_closest_superior(t_node *stack, t_node *target);

// LINKED LIST (FOR INT USE ONLY) UTILS
t_node				*ft_lstnew_int(int data);
void				ft_lstaddback_int(t_node **ptr_to_node,
						t_node *node_to_add);
void				ft_lstaddfront_int(t_node **ptr_to_node,
						t_node *node_to_add);
t_node				*ft_lstlast_int(t_node *node);
int					ft_lstsize_int(t_node *lst);
void				ft_lstclear_int(t_node *_head);
// void				ft_lstiter_int(t_node *head, void (*f)(int, int, int *));

// HELPER UTILS
int					min(int a, int b);
int					max(int a, int b);
int					abs(int a);
int					min_in_arr(int *arr, int arr_size);
int					is_valid_chars(char *str);
void				handle_parse_error(t_node *stack_a);
void				ft_putendl_fd(char *str, int fd);
// void				print(int data, int rank, int *moves);

#endif