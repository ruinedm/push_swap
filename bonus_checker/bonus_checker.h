/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukour <mboukour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:15:21 by mboukour          #+#    #+#             */
/*   Updated: 2024/01/30 01:42:34 by mboukour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_CHECKER_H
# define BONUS_CHECKER_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 10

# define STACK_A 0
# define STACK_B 1

# define TRUE 1
# define FALSE 0

# define NORMAL_NUM 2
# define COMPLICATED_INPUT 1
# define INVALID_INPUT -1

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

// CHECKER GENERAL UTILS
void				handle_checker(t_node **stack_a, int stack_size);
int					ft_strlen(char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					is_sorted(t_node *stack);
int					is_valid_chars(char *str);

// GET NEXT LINE
char				*get_next_line(int fd);
char				*read_and_append(int fd, char **ptr_to_save);
char				*extract_line(char **ptr_to_save);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strdup(char *s1);
char				*ft_strchr(char *s, int c);
char				*ft_substr(const char *s, unsigned int start, size_t len);

// MOVES
void				px(t_node **s_stack, t_node **r_stack);
void				rx(t_node **stack);
void				rrx(t_node **stack);
void				sx(t_node **stack);
void				ss(t_node **stack_a, t_node **stack_b);
void				rr(t_node **stack_a, t_node **stack_b);
void				rrr(t_node **stack_a, t_node **stack_b);

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

// PARSING AND CONVERSION UTILS
int					ft_atoi(char *str, t_node *head);
t_node				*parser(char *argv[], int stack_size);

// RANKING UTILS
void				rank_nodes(t_node *stack_a, int stack_size);

// PRINTING UTLS
void				ft_putendl_fd(char *str, int fd);
// void print(int data, int rank, int *moves);
#endif