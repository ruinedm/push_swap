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
        rx(stack_a, STACK_A);
        sx(stack_a, STACK_A);
    }
    else if(a > b && a > c && c > b)
        rx(stack_a, STACK_A);
    else if(a > b && a < c && c > a)
        sx(stack_a, STACK_A);
    else if(a < b && a > c && b > c)
    {
        rx(stack_a, STACK_A);
        rx(stack_a, STACK_A);
    }
    else if(a < b && a < c && b > c)
    {
        sx(stack_a, STACK_A);
        rx(stack_a, STACK_A);
    }
}

void sort4(t_node **stack_a)
{
    t_node *stack_b;

    stack_b = NULL;
    push_smallest(stack_a, &stack_b, STACK_A);
    sort3(stack_a);
    px(&stack_b, stack_a, STACK_A);
}


void sort5(t_node **stack_a)
{
    t_node *stack_b;

    stack_b = NULL;
    push_smallest(stack_a, &stack_b, STACK_A);
    push_smallest(stack_a, &stack_b, STACK_A);
    sort3(stack_a);
    px(&stack_b, stack_a, STACK_A);
    px(&stack_b, stack_a, STACK_A);
}
