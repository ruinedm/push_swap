#include "../push_swap.h"

void px(t_node **s_stack, t_node **r_stack, int flag)
{
    t_node *tmp;

    if(flag == STACK_A)
        printf("pa\n");
    else if (flag == STACK_B)
        printf("pb\n");
    tmp = *s_stack;
    *s_stack = (*s_stack)->next;
    ft_lstaddfront_int(r_stack, tmp);
}

void rx(t_node **stack, int flag)
{
    t_node *tmp;
    t_node *last;

    if(flag == STACK_A)
        printf("ra\n");
    else if (flag == STACK_B)
        printf("rb\n");
    tmp = *stack;
    last = ft_lstlast_int(*stack);
    last->next = *stack;
    *stack = (*stack)->next;
    tmp->next = (NULL);
}

void rrx(t_node **stack, int flag)
{
    t_node *looping_node;
    t_node *last;

    if(flag == STACK_A)
        printf("rra\n");
    else if(flag == STACK_B)
        printf("rrb\n");
    last = ft_lstlast_int(*stack);
    looping_node = *stack;
    while(looping_node->next != last)
        looping_node = looping_node->next;
    looping_node->next = NULL;
    ft_lstaddfront_int(stack, last);
}

void sx(t_node **stack, int flag)
{
    t_node *first_node;
    t_node *second_node;

    if(flag == STACK_A)
        printf("sa\n");
    else if(flag == STACK_B)
        printf("sb\n");
    first_node = *stack;
    second_node = (*stack)->next;
    first_node->next = second_node->next;
    second_node->next = first_node;
    *stack = second_node;
}

void ss(t_node **stack_a, t_node **stack_b)
{
    sx(stack_a, -1);
    sx(stack_b, -1);
    printf("ss\n");
}

void rr(t_node **stack_a, t_node **stack_b)
{
    rx(stack_a, -1);
    rx(stack_b, -1);
    printf("rr\n");
}

void rrr(t_node **stack_a, t_node **stack_b)
{
    rx(stack_a, -1);
    rx(stack_b, -1);
    printf("rr\n");
}