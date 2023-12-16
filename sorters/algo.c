#include "../push_swap.h"

void sort_all(t_node **stack_a, int stack_size)
{
    int i;
    t_node *stack_b;

    stack_b = NULL;
    i = 0;
    while(i < stack_size)
    {
        push_smallest(stack_a, &stack_b, 0);
        i++;
    }
    push_elements(&stack_b, stack_a, 0);
}
