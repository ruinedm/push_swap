#include "../push_swap.h"




void sort_all(t_node **stack_a, int stack_size)
{
    t_node *stack_b;
    t_node *foo;
    t_node *loo;
    t_node *before_foo;
    t_node *before_loo;
    t_node *to_push;
    t_node *push_before;
    int mode;
    int count;
    int cost_foo;
    int cost_loo;
    int i;
    i = 0;

    stack_b = NULL;
    analyze_stack(*stack_a, stack_size);
    push_with_pivot(stack_a, &stack_b, stack_size);
    // if(ft_lstlast_int(*stack_a)->rank < ft_lstlast_int(*stack_a)->prev->rank)
    //     rrx(stack_a, STACK_A);
    while(i < 65)
    {

    foo = *stack_a;
    loo = ft_lstlast_int(*stack_a);
    while(foo)
    {
        if(foo->prev)
        {
            if(foo->rank != foo->prev->rank + 1)
                break;
        }
        foo = foo->next;
    }
    while(loo)
    {
        if(loo->rank != loo->prev->rank + 1)
            break;
        loo = loo->prev;
    }


    before_foo = find_node(stack_b, foo->rank - 1, FIND_BY_RANK);
    before_loo = find_node(stack_b, loo->rank - 1, FIND_BY_RANK);
    cost_foo = get_cost_to_top(*stack_a, foo, stack_size) + get_cost_to_top(stack_b, before_foo, stack_size);
    cost_loo = get_cost_to_top(*stack_a, loo, stack_size) + get_cost_to_top(stack_b, before_loo, stack_size);
    to_push = before_foo;
    push_before = foo;
    if(cost_foo > cost_loo)
    {
        push_before = loo;
        to_push = before_loo;
    }
    get_node_to_top(&stack_b, to_push, STACK_B, NULL);
    count = get_node_to_top(stack_a, push_before, STACK_A, &mode);
    px(&stack_b, stack_a, STACK_A);0
    i++;
    }

    // foo = *stack_a;
    // loo = ft_lstlast_int(*stack_a);
    // while(foo)
    // {
    //     if(foo->prev)
    //     {
    //         if(foo->rank != foo->prev->rank + 1)
    //             break;
    //     }
    //     foo = foo->next;
    // }
    // while(loo)
    // {
    //     if(loo->rank != loo->prev->rank + 1)
    //         break;
    //     loo = loo->prev;
    // }
    

    // before_foo = find_node(stack_b, foo->rank - 1, FIND_BY_RANK);
    // before_loo = find_node(stack_b, loo->rank - 1, FIND_BY_RANK);
    // cost_foo = get_cost_to_top(*stack_a, foo, stack_size) + get_cost_to_top(stack_b, before_foo, stack_size);
    // cost_loo = get_cost_to_top(*stack_a, loo, stack_size) + get_cost_to_top(stack_b, before_loo, stack_size);
    // to_push = before_foo;
    // push_before = foo;
    // if(cost_foo > cost_loo)
    // {
    //     push_before = loo;
    //     to_push = before_loo;
    // }
    // get_node_to_top(&stack_b, to_push, STACK_B, NULL);
    // count = get_node_to_top(stack_a, push_before, STACK_A, &mode);
    // px(&stack_b, stack_a, STACK_A);
    // reverse_get_node_to_top(stack_a, count, STACK_A , mode);
    
    
    // printf("STACK A\n");
    // ft_lstiter_int(*stack_a, print);
    // printf("STACK B:\n");
    // ft_lstiter_int(stack_b, print);
}

