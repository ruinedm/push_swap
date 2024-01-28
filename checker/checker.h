#ifndef CHECKER_H
#define CHECKER_H

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 10

#define STACK_A 0
#define STACK_B 1
#define SILENT 3
#define TRUE 1
#define FALSE 0

#define NORMAL_NUM 2
#define COMPLICATED_INPUT 1
#define INVALID_INPUT -1

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


// CHECKER UTILS
void handle_checker(t_node **stack_a);
int ft_strlen(char *str);

// GET NEXT LINE
char	*get_next_line(int fd);
char	*read_and_append(int fd, char **ptr_to_save);
char	*extract_line(char **ptr_to_save);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);


// MOVES
void px(t_node **s_stack, t_node **r_stack, int flag);
void rx(t_node **stack,int flag);
void rrx(t_node **stack, int flag);
void sx(t_node **stack, int flag);
void ss(t_node **stack_a, t_node **stack_b);
void rr(t_node **stack_a, t_node **stack_b);
void rrr(t_node **stack_a, t_node **stack_b);


// LINKED LIST (FOR INT USE ONLY) UTILS
t_node *ft_lstnew_int(int data);
void ft_lstaddback_int(t_node **ptr_to_node, t_node *node_to_add);
void ft_lstaddfront_int(t_node **ptr_to_node, t_node *node_to_add);
t_node *ft_lstlast_int(t_node *node);
void ft_lstiter_int(t_node *head, void(*f)(int, int, int *));
int ft_lstsize_int(t_node *lst);
void ft_lstclear_int(t_node *_head);

// PARSING AND CONVERSION UTILS
int	ft_atoi(char *str, t_node *head);
t_node *parser(char *argv[], int stack_size);


void print(int data, int rank, int *moves);

#endif