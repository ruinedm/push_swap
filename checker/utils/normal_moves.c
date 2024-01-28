#include "../checker.h"

void px(t_node **s_stack, t_node **r_stack, int flag)
{
    t_node *tmp;

    if(flag == STACK_A)
        printf("pa\n");
    else if (flag == STACK_B)
        printf("pb\n");
    tmp = *s_stack;
    if (*s_stack != NULL) 
    {
        *s_stack = (*s_stack)->next;
        if (*s_stack != NULL)
            (*s_stack)->prev = NULL;
        ft_lstaddfront_int(r_stack, tmp);
    }
}


void rx(t_node **stack, int flag)
{
    t_node *first;
    t_node *last;

    if(flag == STACK_A)
        printf("ra\n");
    else if (flag == STACK_B)
        printf("rb\n");
    if (!*stack || !(*stack)->next)
        return;

    first = *stack;
    last = ft_lstlast_int(*stack);
    *stack = first->next;
    (*stack)->prev = NULL;
    last->next = first;
    first->prev = last;
    first->next = NULL;
}


void rrx(t_node **stack, int flag)
{
    t_node *looping_node;
    t_node *last;

    if(flag == STACK_A)
        printf("rra\n");
    else if(flag == STACK_B)
        printf("rrb\n");
    if(!*stack || ft_lstsize_int(*stack) == 1) return;
    last = ft_lstlast_int(*stack);
    looping_node = *stack;
    while(looping_node->next != last)
        looping_node = looping_node->next;
    looping_node->next = NULL;
    last->prev = NULL;
    ft_lstaddfront_int(stack, last);
}

void sx(t_node **stack, int flag)
{
    t_node *first_node;
    t_node *second_node;

    if(!*stack || ft_lstsize_int(*stack) == 1)
        return;
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
