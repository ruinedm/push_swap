#include "../push_swap.h"

void px(t_node **s_stack, t_node **r_stack)
{
    t_node *tmp;

    tmp = *s_stack;
    *s_stack = (*s_stack)->next;
    ft_lstaddfront_int(r_stack, tmp);
}

void rx(t_node **stack)
{
    t_node *tmp;
    t_node *last;

    tmp = *stack;
    last = ft_lstlast_int(*stack);
    last->next = *stack;
    *stack = (*stack)->next;
    tmp->next = (NULL);
}

void rrx(t_node **stack)
{
    t_node *looping_node;
    t_node *last;

    last = ft_lstlast_int(*stack);
    looping_node = *stack;
    while(looping_node->next != last)
        looping_node = looping_node->next;
    looping_node->next = NULL;
    ft_lstaddfront_int(stack, last);
}

void sx(t_node **stack)
{
    t_node *first_node;
    t_node *second_node;

    first_node = *stack;
    second_node = (*stack)->next;
    first_node->next = second_node->next;
    second_node->next = first_node;
    *stack = second_node;
}
