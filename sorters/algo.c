#include "../push_swap.h"
#include <stdio.h>

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

t_node *get_smallest_bigger_than(t_node *stack, t_node *target)
{
    t_node *looping_node;
    t_node *current_bigger;

    looping_node = stack;
    current_bigger = NULL;
    if(!target)
        return (get_smallest_node(stack));
    else
    {
        while (looping_node)
        {
            if(looping_node->rank > target->rank)
            {
                if(!current_bigger)
                    current_bigger = looping_node;
                else
                {
                    if(looping_node->rank < current_bigger->rank)
                        current_bigger = looping_node;
                }
            }
            looping_node = looping_node->next;
        }
    }
    return (current_bigger);
}

void iterate_and_calculate(t_node *stack_a, t_node *stack_b)
{
    t_node *looping_node;
    t_node *closest_bigger;
    int r_direction_a;
    int r_direction_b;
    int count_a;
    int count_b;
    int stack_a_size;
    int stack_b_size;


    looping_node = stack_b;
    while(looping_node)
    {
        stack_a_size = ft_lstsize_int(stack_a);
        stack_b_size = ft_lstsize_int(stack_b);
        closest_bigger = get_smallest_bigger_than(stack_a, looping_node); // GOOD
        if(!closest_bigger || closest_bigger == stack_a) // THE BIGGER OR SMALLER, NO ROTATION NEEDED TO PUSH :)
            count_a = 0;
        else
            count_a = get_cost_to_top(stack_a,closest_bigger, stack_a_size, &r_direction_a, OPTIMAL);
        count_b = get_cost_to_top(stack_b, looping_node, stack_b_size, &r_direction_b, OPTIMAL);
        if(r_direction_a == RRX)
            count_a *= -1;
        if(r_direction_b == RRX)
            count_b *= -1;
        // printf("COUNT B FOR NODE WITH RANK: %i IS %i\n", looping_node->rank, count_b);
        looping_node->moves[0] = count_b;
        looping_node->moves[1] = count_a;
        looping_node = looping_node->next;
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

t_node *get_node_with_least_combo(t_node *stack_b)
{
    t_node *looping_node;
    int *moves_array;
    int *mv;
    int i;
    int j;
    int action;
    int size;
    int min;

    size = ft_lstsize_int(stack_b);
    moves_array = malloc(size * sizeof(int));
    i = 0;
    j = 0;
    if(!moves_array)
        return (NULL);
    looping_node = stack_b;
    action = RX;
    while(looping_node)
    {
        mv = looping_node->moves;
        if(mv[0] == 0 && mv[1] == 0) // THE WOMBO COMBO, ITS THE BEST
            return (free(moves_array), looping_node);
        else if(mv[0] * mv[1] > 0) // SAME SIGN FOR BOTH STACKS // RRR OR RR IS POSSIBLE
            moves_array[i] = maxv(abs(mv[0]), abs(mv[1]));
        else
            moves_array[i] = abs(mv[0]) + abs(mv[1]);
        i++;
        looping_node = looping_node->next;
    }
    looping_node = stack_b;
    min = min_in_arr(moves_array, size);
    i = 0;
    while(i < size)
    {
        if(moves_array[i] == min)
            break;
        i++;
    }
    while(j < i)
    {
        looping_node = looping_node->next;
        j++;
    }
    // print_int_arr(moves_array, size);
    free(moves_array);
    return (looping_node);
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
    int MAX_ITERATION;

    i = 0;
    MAX_ITERATION = 0;
    stack_b = NULL;
    analyze_stack(*stack_a, stack_size);
    push_with_pivot(stack_a, &stack_b, stack_size);
    while(MAX_ITERATION < 1)
    {
        iterate_and_calculate(*stack_a, stack_b);
        push_node_x(&stack_b, stack_a, get_node_with_least_combo(stack_b), STACK_A, NORMAL_PUSH);
        MAX_ITERATION++;
    }
    puts("STACK A");
    ft_lstiter_int(*stack_a, print);
    puts("STACK B");
    ft_lstiter_int(stack_b, print);
}