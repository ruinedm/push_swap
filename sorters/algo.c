#include "../push_swap.h"

int min(int a, int b)
{
    if(a > b)
        return b;
    return a;
}

void preform_action_alot(t_node **stack_a, t_node **stack_b, int action, int times)
{
    int i;

    i = 0;
    while(i < times)
    {
        if(action == RX)
            rr(stack_a, stack_b);
        else if(action == RRX)
            rrr(stack_a, stack_b);
        i++;
    }
}

void sort_all(t_node **stack_a, int stack_size)
{
    t_node *stack_b;
    t_node *foo;
    t_node *loo;
    t_node *before_foo;
    t_node *before_loo;
    t_node *to_push;
    t_node *push_before;
    // int mode;
    // int count;
    int cost_foo;
    int cost_loo;
    int cost_push_before;
    int cost_to_push;
    int r_direction_to_push;
    int r_direction_push_before;
    int i;
    int MAX_ITERATION; // Debugging var

    MAX_ITERATION = 0;
    i = 0;
    stack_b = NULL;
    analyze_stack(*stack_a, stack_size);
    push_with_pivot(stack_a, &stack_b, stack_size);
    while(i < 2)
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
    i++;

    stack_size = ft_lstsize_int(*stack_a);
    before_foo = find_node(stack_b, foo->rank - 1, FIND_BY_RANK);
    before_loo = find_node(stack_b, loo->rank - 1, FIND_BY_RANK);
    cost_foo = get_cost_to_top(*stack_a, foo, stack_size, NULL, OPTIMAL) + get_cost_to_top(stack_b, before_foo, stack_size, NULL, OPTIMAL);
    cost_loo = get_cost_to_top(*stack_a, loo, stack_size, NULL, OPTIMAL) + get_cost_to_top(stack_b, before_loo, stack_size, NULL, OPTIMAL);
    to_push = before_foo;
    push_before = foo;
    if(cost_foo > cost_loo)
    {
        push_before = loo;
        to_push = before_loo;
    }
    cost_push_before = get_cost_to_top(*stack_a, push_before, stack_size, &r_direction_push_before, OPTIMAL);
    cost_to_push = get_cost_to_top(stack_b, to_push, ft_lstsize_int(stack_b), &r_direction_to_push, OPTIMAL);
    if(r_direction_to_push != r_direction_push_before) // RX AND RRX CAN'T BE MERGED !!
    {
        get_node_to_top(&stack_b, to_push, STACK_B, NULL);
        get_node_to_top(stack_a, push_before, STACK_A, NULL);
        px(&stack_b, stack_a, STACK_A);
    }
    else
    {
        preform_action_alot(stack_a, &stack_b, r_direction_to_push, min(cost_to_push, cost_push_before));
        get_node_to_top(&stack_b, to_push, STACK_B, NULL);
        get_node_to_top(stack_a, push_before, STACK_A, NULL);
        px(&stack_b, stack_a, STACK_A);
    }
    }
    printf("STACK A\n");
    ft_lstiter_int(*stack_a, print);
    printf("STACK B:\n");
    ft_lstiter_int(stack_b, print);
    printf("END\n");
}