#include "../push_swap.h"

void ss(t_node **stack_a, t_node **stack_b)
{
    sx(stack_a, -1);
    sx(stack_b, -1);
    printf("ss\n");
}

void rr(t_node **stack_a, t_node **stack_b)
{
    rx(stack_a, 5);
    rx(stack_b, 5);
    printf("rr\n");
}

void rrr(t_node **stack_a, t_node **stack_b)
{
    rrx(stack_a, 5);
    rrx(stack_b, 5);
    printf("rrr\n");
}