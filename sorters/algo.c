#include "../push_swap.h"


void sort_all(t_node **stack_a, int stack_size)
{
    t_node *stack_b;
    // t_node *first_out_of_order;
    // t_node *last_out_of_order;

    stack_b = NULL;
    analyze_stack(*stack_a, stack_size);
    push_with_pivot(stack_a, &stack_b, stack_size);
    // ft_lstiterback_int(*stack_a, print);
    // if(ft_lstlast_int(*stack_a)->rank < ft_lstlast_int(*stack_a)->prev->rank)
    //     rrx(stack_a, STACK_A);
    // first_out_of_order = *stack_a;
    // last_out_of_order = ft_lstlast_int(*stack_a);
    // while(first_out_of_order)
    // {
    //     if(first_out_of_order->prev)
    //     {
    //         if(first_out_of_order->rank != first_out_of_order->prev->rank + 1)
    //             break;
    //     }
    //     first_out_of_order = first_out_of_order->next;
    // }
    // while(last_out_of_order)
    // {
    //     if(last_out_of_order->rank != last_out_of_order->rank + 1)
    //         break;
    //     last_out_of_order = last_out_of_order->prev;
    // }
    // printf("FOO: %i\n", first_out_of_order->data);
    // printf("LOO: %i\n", last_out_of_order->data);
    printf("STACK A\n");
    ft_lstiter_int(*stack_a, print);
    printf("STACK B:\n");
    ft_lstiter_int(stack_b, print);
}

