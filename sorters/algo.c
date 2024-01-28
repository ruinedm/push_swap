#include "../push_swap.h"

void preform_action_alot(t_node **stack_a, t_node **stack_b, int sign, int times)
{
    int i;
    int action;

    i = 0;
    action = RX;
    if(sign < 0)
        action = RRX;    
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
    int i;

    i = 0;
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
    int cost;

    cost = 0;
    if(get_node_position(stack, target) <= stack_size / 2)
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

t_node *calculate_choice_array(t_node *stack_a,t_node *stack_b, int stack_size, int **choice_array_ptr)
{
    int *choice_array;
    int i;
    int *mv;

    i = 0;
    choice_array = malloc(stack_size * sizeof(int));
    if (!choice_array) 
        return (ft_lstclear_int(stack_a), ft_lstclear_int(stack_b), printf("Error\n"),exit(EXIT_FAILURE), NULL);
    while (stack_b)
    {
        mv = stack_b->moves;
        if (mv[0] == 0 && mv[1] == 0) 
            return(free(choice_array), *choice_array_ptr = NULL, stack_b);
        else if (mv[0] * mv[1] > 0)
            choice_array[i] = MAX(ABS(mv[0]), ABS(mv[1]));
        else 
            choice_array[i] = ABS(mv[0]) + ABS(mv[1]);
        i++;
        stack_b = stack_b->next;
    }
    *choice_array_ptr = choice_array;
    return NULL;
}

t_node *find_min_node(t_node *stack, int *choice_array, int stack_size)
{
    int i;
    int j;
    int min;

    i = 0;
    j = 0;
    min = min_in_arr(choice_array, stack_size);
    while (i < stack_size)
    {
        if (choice_array[i] == min) {
            break;
        }
        i++;
    }
    while (j < i)
    {
        stack = stack->next;
        j++;
    }
    return (stack);
}


t_node *get_best_node(t_node *stack_a,t_node *stack_b, int stack_size)
{
    int *choice_array;
    t_node  *best_node;
    t_node *result = calculate_choice_array(stack_a,stack_b, stack_size, &choice_array);

    if (result) 
        return result;
    best_node = find_min_node(stack_b, choice_array, stack_size);
    free(choice_array);
    return best_node;
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

void ez_push_to_place(t_node **stack_a, t_node **stack_b,t_node *to_push, t_node *closest_superior)
{
    go_to_top(stack_a, closest_superior, STACK_A);
    go_to_top(stack_b, to_push, STACK_B);
    px(stack_b, stack_a, STACK_A);
}

void sort_all(t_node **stack_a, int stack_size)
{
    t_node *stack_b;
    t_node *to_push;
    t_node *closest_superior;
    int *mv;

    stack_b = NULL;
    push_with_pivot(stack_a, &stack_b, stack_size);
    while (stack_b)
    {
        iterate_and_calculate(*stack_a, stack_b);
        to_push = get_best_node(*stack_a,stack_b, ft_lstsize_int(stack_b));
        closest_superior = get_closest_superior(*stack_a, to_push);
        if(!closest_superior)
            closest_superior = get_smallest_node(*stack_a);
        mv = to_push->moves;
        if(mv[0] == 0 && mv[1] == 0)
            px(&stack_b, stack_a, STACK_A);
        else
        {
            if(mv[0] * mv[1] > 0)
                preform_action_alot(stack_a, &stack_b, mv[0], MIN(ABS(mv[0]), ABS(mv[1])));
            ez_push_to_place(stack_a, &stack_b, to_push, closest_superior);
        }
    }
    go_to_top(stack_a, get_smallest_node(*stack_a), STACK_A);
}
