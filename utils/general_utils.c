#include "../push_swap.h"
#include <stdio.h>

void print(int data, int rank, int is_lis)
{
    if(is_lis)
        printf("VALUE: %d RANK: %d IS_LIS: TRUE\n", data, rank);
    else
        printf("VALUE: %d RANK: %d IS_LIS: FALSE\n", data, rank);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}
t_node *find_node(t_node *stack, int data, int mode)
{
    t_node *looping_node;
    int find_by;

    looping_node = stack;
    while(looping_node)
    {
        if(mode == FIND_BY_DATA)
            find_by = looping_node->data;
        else
            find_by = looping_node->rank;
        if(find_by == data)
            return (looping_node);
        looping_node = looping_node->next;
    }
    return looping_node;
}

void sort_handler(t_node **stack_a, int stack_size)
{
    if(stack_size == 2)
        printf("ra\n");
    else if(stack_size == 3)
        sort3(stack_a);
    else if(stack_size == 4)
        sort4(stack_a);
    else if(stack_size == 5)
        sort5(stack_a);
    else
        sort_all(stack_a, stack_size);
}

int is_reversed(t_node *stack)
{
    t_node *current_node;

    current_node = stack;
    while (current_node != NULL && current_node->next != NULL)
    {
        if (current_node->data < current_node->next->data)
            return (0);
        current_node = current_node->next;
    }
    return (1);
}

t_node *get_smallest_node(t_node *stack) {

    t_node *smallest_node = stack;
    t_node *current_node = stack->next;

    while (current_node != NULL) {
        if (current_node->rank < smallest_node->rank)
            smallest_node = current_node;
        current_node = current_node->next;
    }
    return smallest_node;
}


int get_smallest_node_position(t_node *stack) 
{
    t_node *current_node = stack;
    int smallest_rank = current_node->rank;
    int smallest_position = 0;
    int current_position = 0;

    while(current_node) 
    {
        if(current_node->rank < smallest_rank) 
        {
            smallest_rank = current_node->rank;
            smallest_position = current_position;
        }
        current_node = current_node->next;
        current_position++;
    }
    return (smallest_position);
}

int *copy_stack_to_array(t_node *stack)
{
    int *copy_array;
    int stack_size;
    int i;

    i = 0;
    stack_size = ft_lstsize_int(stack);
    copy_array = malloc(stack_size * sizeof(int));
    while(i < stack_size)
    {
        copy_array[i] = stack->data;
        stack = stack->next;
        i++;
    }
    return copy_array;
}
void bubble_sort(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                // Swap arr[j] and arr[j + 1]
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}


void rank_nodes(t_node *stack_a, int stack_size)
{
    t_node *looping_node;
    int *copy_array;
    int i;

    i = 0;
    stack_size = ft_lstsize_int(stack_a);
    copy_array = copy_stack_to_array(stack_a);
    bubble_sort(copy_array, stack_size);
    looping_node = stack_a;
    while(i < stack_size)
    {
        while(looping_node->data != copy_array[i])
            looping_node = looping_node->next;
        looping_node->rank = i + 1;
        looping_node = stack_a;
        i++;
    }
    free(copy_array);
}
int get_node_position(t_node *stack, t_node *target) {
    int i = 1;
    while(stack) 
    {
        if(stack == target)
            return i;
        stack = stack->next;
        i++;
    }
    return -1;
}

t_node* get_first_and_last(t_node *stack, int start, int end, int mode) 
{
    t_node *looping_node;
    t_node *current_end;

    if(!stack) printf("STACK IS NULL!!!!");
    looping_node = stack;
    current_end = NULL;
    while(looping_node)
    {
        //if(current_end) printf("CURRENT END RANK:%i\n", current_end->rank);
        if(looping_node->rank >= start && looping_node->rank <= end) 
        {
            if(mode == FIRST)
                return looping_node;
            current_end = looping_node;
        }
        looping_node = looping_node->next;
    }
    return (current_end);
}

int get_cost_to_top(t_node *stack, t_node *target, int stack_size, int *r_direction, int method)
{
    t_node *looping_node;
    int mid;
    int pos;
    int mode;
    int cost;

    if(!r_direction)
        r_direction = &mode;
    cost = 0;
    mode = 1;
    mid = stack_size / 2;
    pos = get_node_position(stack, target);
    // printf("CURRENT POSITION OF RANK: %i IS %i\n", target->rank, pos);
    if(method == RX)
        pos = mid - 1;
    else if(method == RRX)
        pos = mid + 1;
    if(pos < mid)
    {
        *r_direction = RX;
        looping_node = stack;
    }
    else
    {
        *r_direction = RRX;
        looping_node = target;
    }
    while(looping_node)
    {
        if(looping_node == target && !(*r_direction))
            return (cost);
        looping_node = looping_node->next;
        cost++;
    }
    return (cost);
}
// t_node *find_optimal_move_node(t_node *stack, int chunk_start, int chunk_end, int stack_size)
// {
//     t_node *first;
//     t_node *last;
//     int cost_first;
//     int cost_last;

//     first = get_first_and_last(stack, chunk_start, chunk_end, FIRST);
//     last = get_first_and_last(stack, chunk_start, chunk_end, LAST);
//     cost_first = get_cost_to_top(stack, first, stack_size);
//     cost_last = get_cost_to_top(stack, last, stack_size);
//     if(cost_first > cost_last)
//         return (last);
//     return (first);
// }
void fix_lis(t_node **stack)
{
    t_node *looping_node;
    int i;

    i = 0;
    looping_node = *stack;
    while(looping_node)
    {
        if(looping_node->rank > looping_node->next->rank)
            break;
        looping_node = looping_node->next;
    }
    looping_node = looping_node->next;
    // printf("LOOPING NODE RANK %i\n", looping_node->rank);
    // printf("LOOPING NODE PREV RANK %i\n", looping_node->prev->rank);
    // printf("LOOPING NODE PREV PREV RANK %i\n", looping_node->prev->prev->rank);
    printf("CURRENT LOOPING NODE RANK: %i\n", looping_node->rank);
    // printf("LOOPING NODE PREV PREV PREV RANK %i\n", looping_node->prev->prev->prev->rank);
    while(looping_node && i<10)
    {
        looping_node = looping_node->prev;
        rx(stack, STACK_A);
        i++;
    }
}


void push_smallest(t_node **s_stack, t_node **r_stack, int flag)
{
    t_node *smallest_node;
    int median_pos;
    int small_pos;

    median_pos = ft_lstsize_int(*s_stack) / 2;
    small_pos = get_smallest_node_position(*s_stack);
    smallest_node = get_smallest_node(*s_stack);
    while(*s_stack != smallest_node)
    {
        if (small_pos > median_pos)
            rrx(s_stack, flag);
        else
            rx(s_stack, flag);
    }
    px(s_stack, r_stack, !flag);
}
int is_sorted(t_node *stack)
{
    t_node *current_node;

    current_node = stack;
    while (current_node != NULL && current_node->next != NULL)
    {
        if(current_node->next->rank != current_node->rank + 1)
            return (FALSE);
        current_node = current_node->next;
    }
    return (TRUE);
}
void push_with_pivot(t_node **s_stack,t_node **r_stack, int stack_size)
{
    t_node *looping_node;
    t_node *next_node;

    // printf("PIVOT RANK: %i\n", pivot_node->rank);
    looping_node = *s_stack;
    while(looping_node)
    {
        next_node = looping_node->next;
        if(looping_node->is_lis == FALSE)
        {
            if(looping_node->rank > stack_size / 2)
                push_node_x(s_stack, r_stack, looping_node, STACK_A, NORMAL_PUSH);
            else
                push_node_x(s_stack, r_stack, looping_node, STACK_A, PUSH_AND_RX);
        }
        looping_node = next_node;
    }
    // if(is_sorted(*s_stack)) printf("IT'S SORTED\n"); else printf("IT'S NOT\n");
    // fix_lis(s_stack);
    // rx(s_stack, STACK_A); // I NEED TO FIND OUT WHAT TRIGGERS THIS SHIT ASAP
}
int get_node_to_top(t_node **stack, t_node *node_x, int flag, int *mode)
{
    int med_pos;
    int x_pos;
    int count;

    count = 0;
    med_pos = ft_lstsize_int(*stack) / 2;
    x_pos = get_node_position(*stack, node_x);
    if(x_pos > med_pos)
    {
        if(mode)
            *mode = REVERSE_RRX;
        while(*stack != node_x)
        {
            rrx(stack, flag);
            count++;
        }
    }
    else
    {
        if(mode)
            *mode = REVERSE_RX;
        while(*stack != node_x)
        {
            rx(stack, flag);
            count++;
        }
    }
    return (count);
}
void reverse_get_node_to_top(t_node **stack, int rotation_count, int flag, int mode)
{
    if(mode == REVERSE_RRX)
        rotation_count++;
    for(int i = 0; i < rotation_count; i++) {
        if(mode == REVERSE_RRX) {
            rx(stack, flag);
        } else if(mode == REVERSE_RX) {
            rrx(stack, flag);
        }
    }
}


void push_node_x(t_node **s_stack, t_node **r_stack, t_node *node_x, int flag, int mode)
{
    int med_pos;
    int x_pos;

    med_pos = ft_lstsize_int(*s_stack) / 2;
    x_pos = get_node_position(*s_stack, node_x);
    while(*s_stack != node_x)
    {
        if(x_pos > med_pos)
            rrx(s_stack, flag);
        else
            rx(s_stack, flag);
    }
    px(s_stack, r_stack, !flag);
    if(mode == PUSH_AND_RX)
        rx(r_stack, !flag);
}
void push_elements(t_node **s_stack, t_node **r_stack, int flag)
{
    while (*s_stack != NULL)
    {
        px(s_stack, r_stack, flag);
    }
}
