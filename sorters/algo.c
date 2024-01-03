#include "../push_swap.h"

void printme(int data)
{
    printf("%d\n", data);
}

void push_lower(t_node **stack_a, t_node **stack_b)
{
    int k;
    int i;
    i = 0;

    k = ft_lstsize_int(*stack_a) / 2;
    while(i<k)
    {
        push_smallest(stack_a, stack_b, 0);
        i++;
    }
    printf("HIGHER PART:\n");
    ft_lstiter_int(*stack_a, printme);
    printf("LOWER PART:\n");
    ft_lstiter_int(*stack_b, printme);
}

void sort_all(t_node **stack_a, int stack_size)
{
    // int i;
    t_node *stack_b;

    stack_b = NULL;
    push_lower(stack_a, &stack_b);
    push_lower(stack_a, &stack_b);
    push_lower(stack_a, &stack_b);
    stack_size--;
    // i = 0;
    // while(i < stack_size)
    // {
    //     push_smallest(stack_a, &stack_b, 0);
    //     i++;
    // }
    // push_elements(&stack_b, stack_a, 0);
}

