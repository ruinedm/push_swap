#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct s_node
{
    int data;
    struct s_node *next;
} t_node;

// SORTERS
void sort_handler(t_node *stack_a, int stack_size);
void sort3(t_node *stack_a);

// GENERAL UTILS
int ft_strlen(char *str);
int	ft_atoi(char *str, int *error_flag);

// LINKED LIST (FOR INT USE ONLY) UTILS
t_node *ft_lstnew_int(int data);
void ft_lstaddback_int(t_node **ptr_to_node, t_node *node_to_add);
t_node *ft_lstlast_int(t_node *node);
void ft_lstiter_int(t_node *head, void(*f)(int));
void ft_lstclear_int(t_node *head);

#endif