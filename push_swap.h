#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
# include <fcntl.h>
# include <unistd.h>

#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))



#define NORMAL_NUM 2
#define COMPLICATED_INPUT 1
#define INVALID_INPUT -1

#define STACK_A 0
#define STACK_B 1
#define SILENT 3

#define TRUE 1
#define FALSE 0

#define RX 0
#define RRX 1

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

typedef struct s_node
{
    int data;
    int rank;
    int moves[2];
    struct s_node *next;
    struct s_node *prev;
} t_node;

// STACK CHCKERES
int check_duplicates(t_node *stack);
int is_sorted(t_node *stack);

// SORTERS
void sort3(t_node **stack_a);
void sort4(t_node **stack_a);
void sort5(t_node **stack_a);
void sort_all(t_node **stack_a, int stack_size);

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
void sort_handler(t_node **stack_a, int stack_size);
void push_smallest(t_node **s_stack, t_node **r_stack,int flag);
void push_with_pivot(t_node **s_stack,t_node **r_stack, int stack_size);

// PARSING AND CONVERSION UTILS
int	ft_atoi(char *str, t_node *head);
t_node *parser(char *argv[], int stack_size);

// RANKING UTILS
void rank_nodes(t_node *stack_a, int stack_size);

// SEARCHING UTILS
int get_node_position(t_node *stack, t_node *target);
t_node *get_smallest_node(t_node *stack);
int get_smallest_node_position(t_node *stack);

// LINKED LIST (FOR INT USE ONLY) UTILS
t_node *ft_lstnew_int(int data);
void ft_lstaddback_int(t_node **ptr_to_node, t_node *node_to_add);
void ft_lstaddfront_int(t_node **ptr_to_node, t_node *node_to_add);
t_node *ft_lstlast_int(t_node *node);
void ft_lstiter_int(t_node *head, void(*f)(int, int, int *));
int ft_lstsize_int(t_node *lst);
void ft_lstclear_int(t_node *_head);

// PRINT STACK
// void print(int data, int rank, int *moves);

#endif