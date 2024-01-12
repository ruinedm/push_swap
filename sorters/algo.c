#include "../push_swap.h"


void sort_all(t_node **stack_a, int stack_size)
{
    t_node *stack_b;

    stack_b = NULL;
    analyze_stack(*stack_a, stack_size);
    push_with_pivot(stack_a, &stack_b, stack_size);
    printf("STACK A\n");
    ft_lstiter_int(*stack_a, print);
    printf("STACK B:\n");
    ft_lstiter_int(stack_b, print);
}

