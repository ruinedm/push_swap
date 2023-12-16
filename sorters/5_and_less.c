#include "../push_swap.h"

void sort3(t_node **stack_a)
{
    int a;
    int b;
    int c;
    
    a = (*stack_a)->data;
    b = (*stack_a)->next->data;
    c = (*stack_a)->next->next->data;
    if(a > b && b > c)
    {
        rx(stack_a, 0);
        sx(stack_a, 0);
    }
    else if(a > b && a > c && c > b)
        rx(stack_a, 0);
    else if(a > b && a < c && c > a)
        sx(stack_a, 0);
    else if(a < b && a > c && b > c)
    {
        rx(stack_a, 0);
        rx(stack_a, 0);
    }
    else if(a < b && a < c && b > c)
    {
        sx(stack_a, 0);
        rx(stack_a, 0);
    }
}

void sort4(t_node **stack_a)
{
    t_node *stack_b;

    stack_b = NULL;
    push_smallest(stack_a, &stack_b, 0);
    sort3(stack_a);
    px(&stack_b, stack_a, 0);
}


void sort5(t_node **stack_a)
{
    t_node *stack_b;

    stack_b = NULL;
    push_smallest(stack_a, &stack_b, 0);
    push_smallest(stack_a, &stack_b, 0);
    sort3(stack_a);
    px(&stack_b, stack_a, 0);
    px(&stack_b, stack_a, 0);
}
