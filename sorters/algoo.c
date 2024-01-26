#include "../push_swap.h"

int min(int a, int b)
{
    if(a > b)
        return b;
    return a;
}
int maxv(int a, int b)
{
    if(a > b)
        return a;
    return b;
}
int abs(int a)
{
    if(a < 0)
        return (-a);
    return (a);
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


int min_in_arr(int *arr, int arr_size)
{
    int min;
    int i = 0;

    min = arr[0];
    while(i < arr_size)
    {
        if(arr[i] < min)
            min = arr[i];
        i++;
    }
    return (min);
}

t_node *get_closest_superior(t_node *stack, t_node *target)
{
    t_node *looping_node;
    t_node *current_superior;

    looping_node = stack;
    current_superior = NULL;

    while(looping_node)
    {
        if(looping_node->rank > target->rank)
        {
            if(!current_superior)
                current_superior = looping_node;
            else
            {
                if(current_superior->rank > looping_node->rank)
                    current_superior = looping_node;
            }
        }
        looping_node = looping_node -> next;
    }
    return (current_superior);
}

int get_cost(t_node *stack, t_node *target, int stack_size)
{
    t_node *looping_node;
    int pos;
    int cost;

    pos = get_node_position(stack, target);
    cost = 0;
    if(pos <= stack_size / 2)
    {
        looping_node = stack;
        while(looping_node != target)
        {
            looping_node = looping_node->next;
            cost++;
        }
        return(cost);
    }
    else
    {
        looping_node = target;
        while(looping_node)
        {
            looping_node = looping_node->next;
            cost++;
        }
        return(-cost);
    }
}

void iterate_and_calculate(t_node *stack_a, t_node *stack_b)
{
    t_node *looping_node;
    t_node *closest_superior;
    int *mv;
    int stack_a_size;
    int stack_b_size;

    stack_a_size = ft_lstsize_int(stack_a);
    stack_b_size = ft_lstsize_int(stack_b);
    looping_node = stack_b;
    while(looping_node)
    {
        mv = looping_node->moves;
        closest_superior = get_closest_superior(stack_a ,looping_node);
        if(!closest_superior)
            closest_superior = get_smallest_node(stack_a);
        mv[0] = get_cost(stack_b, looping_node, stack_b_size);
        mv[1] = get_cost(stack_a, closest_superior, stack_a_size);
        looping_node = looping_node->next;
    }
}

t_node *get_best_node(t_node *stack, int stack_size)
{
    t_node *looping_node;
    int *mv;
    int i;
    int j;
    int min;
    int *choice_array;

    choice_array = malloc(stack_size * sizeof(int));
    looping_node = stack;
    i = 0;
    while(looping_node)
    {
        mv = looping_node ->moves;
        if(mv[0] == 0 && mv[1] == 0)
            return(free(choice_array), looping_node);
        else if(mv[0] * mv[1] > 0)
            choice_array[i] = maxv(abs(mv[0]), abs(mv[1]));
        else
            choice_array[i] = abs(mv[0]) + abs(mv[1]);
        i++;
        looping_node = looping_node->next;
    }
    i = 0;
    j = 0;
    looping_node = stack;
    min = min_in_arr(choice_array, stack_size);
    while(i < stack_size)
    {
        if(choice_array[i] == min)
            break;
        i++;
    }
    while(j < i)
    {
        looping_node = looping_node->next;
        j++;
    }
    return(free(choice_array), looping_node);
}

void go_to_top(t_node **stack, t_node *target, int flag)
{
    int pos;
    t_node *looping_node;
    int stack_size;

    stack_size = ft_lstsize_int(*stack);
    pos = get_node_position(*stack, target);
    if(pos <= stack_size / 2)
    {
        while((*stack) != target)
            rx(stack, flag);
    }
    else
    {
        while((*stack) != target)
            rrx(stack, flag);
    }
}

void sort_all(t_node **stack_a, int stack_size)
{
    t_node *stack_b;
    t_node *to_push;
    t_node *closest_superior;
    int *mv;
    int total_moves;
    int action;

    stack_b = NULL;
    push_with_pivot(stack_a, &stack_b, stack_size);
    iterate_and_calculate(*stack_a, stack_b);

    while (stack_b)
    {
    action = RX;
        iterate_and_calculate(*stack_a, stack_b);
        to_push = get_best_node(stack_b, ft_lstsize_int(stack_b));
        closest_superior = get_closest_superior(*stack_a, to_push);
        if(!closest_superior)
            closest_superior = get_smallest_node(*stack_a);
        mv = to_push->moves;
        if(mv[0] == 0 && mv[1] == 0)
            px(&stack_b, stack_a, STACK_A);
        else if(mv[0] * mv[1] > 0)
        {
            if(mv[0] < 0)
                action = RRX;
            preform_action_alot(stack_a, &stack_b, action, min(abs(mv[0]), abs(mv[1])));
            //if(abs(mv[0]) < abs(get_cost(stack_b, to_push, ft_lstsize_int(stack_b)))) printf("OLD COST 0: %i, NEW COST 0: %i,\n", mv[0], get_cost(stack_b, to_push, ft_lstsize_int(stack_b)));
            //if(abs(mv[1]) < abs(get_cost(*stack_a, closest_superior, ft_lstsize_int(*stack_a)))) printf("OLD COST 1: %i, NEW COST 1: %i\n", mv[1], get_cost(*stack_a, closest_superior, ft_lstsize_int(*stack_a)));
            go_to_top(stack_a, closest_superior, STACK_A);
            go_to_top(&stack_b, to_push, STACK_B);
            px(&stack_b, stack_a, STACK_A);
        }
        else
        {
            go_to_top(stack_a, closest_superior, STACK_A);
            go_to_top(&stack_b, to_push, STACK_B);
            px(&stack_b, stack_a, STACK_A);
        }
    }
    go_to_top(stack_a, get_smallest_node(*stack_a), STACK_A);
    // puts("STACK A");
    // ft_lstiter_int(*stack_a, print);
    // puts("STACK B");
    // ft_lstiter_int(stack_b, print);
}