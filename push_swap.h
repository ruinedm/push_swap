#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define NORMAL_NUM 2
#define COMPLICATED_INPUT 1
#define INVALID_INPUT -1


typedef struct s_node
{
    int data;
    struct s_node *next;
} t_node;

// SORTERS
void sort_handler(t_node **stack_a, int stack_size);
void sort3(t_node **stack_a);
void sort4(t_node **stack_a);
void sort5(t_node **stack_a);

// MOVES
void px(t_node **s_stack, t_node **r_stack, int flag);
void rx(t_node **stack,int flag);
void rrx(t_node **stack, int flag);
void sx(t_node **stack, int flag);
void ss(t_node **stack_a, t_node **stack_b);
void rr(t_node **stack_a, t_node **stack_b);
void rrr(t_node **stack_a, t_node **stack_b);

// GENERAL UTILS
int ft_strlen(char *str);
t_node *get_smallest_node(t_node *stack);
int get_smallest_node_position(t_node *stack);
int is_reversed(t_node *stack);
void push_smallest(t_node **s_stack, t_node **r_stack, int flag);
void push_elements(t_node **s_stack, t_node **r_stack, int flag);
void sort_all(t_node **stack_a, int stack_size);
void sort_100(t_node **stack_a, t_node **stack_b);

// PARSING AND CONVERSION UTILS
int	ft_atoi(char *str, int *error_flag);
t_node *parser(char *argv[], int stack_size);

// LINKED LIST (FOR INT USE ONLY) UTILS
t_node *ft_lstnew_int(int data);
void ft_lstaddback_int(t_node **ptr_to_node, t_node *node_to_add);
void ft_lstaddfront_int(t_node **ptr_to_node, t_node *node_to_add);
t_node *ft_lstlast_int(t_node *node);
void ft_lstiter_int(t_node *head, void(*f)(int));
void ft_lstclear_int(t_node *head);
int ft_lstsize_int(t_node *lst);

#endif