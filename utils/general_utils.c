#include "../push_swap.h"

void print(int data, int rank, int is_lis, int *moves)
{
    if(is_lis)
        printf("VALUE: %d // RANK: %d // IS_LIS: TRUE // MOVES B: %i // MOVES A: %i\n", data, rank, moves[0], moves[1]);
    else
        printf("VALUE: %d // RANK: %d // IS_LIS: FALSE // MOVES B: %i // MOVES A: %i\n", data, rank, moves[0], moves[1]);
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
    else
    {
        analyze_stack(*stack_a, stack_size);
        if(stack_size == 3)
            sort3(stack_a);
        else if(stack_size == 4)
            sort4(stack_a);
        else if(stack_size == 5)
            sort5(stack_a);
        else
            sort_all(stack_a, stack_size);
    }

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

t_node *get_smallest_node(t_node *stack) 
{

    t_node *smallest_node = stack;
    t_node *current_node = stack->next;

    while (current_node != NULL) {
        if (current_node->rank < smallest_node->rank)
            smallest_node = current_node;
        current_node = current_node->next;
    }
    return smallest_node;
}

t_node *get_biggest_node(t_node *stack)
{
    t_node *biggest_node;
    t_node *looping_node;

    biggest_node = stack;
    looping_node = stack->next;
    while(looping_node)
    {
        if(looping_node->rank > biggest_node->rank)
            biggest_node = looping_node;
        looping_node = looping_node->next;
    }
    return (biggest_node);
}

int  get_smallest_node_position(t_node *stack) 
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

t_node *new_node(t_node *node)
{
    t_node *copy_node;

    copy_node = ft_lstnew_int(node->data);
    copy_node->rank = node->rank;
    copy_node->moves[0] = node->moves[0];
    copy_node->moves[1] = node->moves[1];
    copy_node->is_lis = node->is_lis;
    return (copy_node);
}

t_node *stack_dup(t_node *stack)
{
    t_node *looping_node;
    t_node *copy;
    t_node *node;

    copy = NULL;
    looping_node = stack;
    while(looping_node)
    {
        node = new_node(looping_node);
        ft_lstaddback_int(&copy, node);
        looping_node = looping_node->next;
    }
    return (copy);
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
int get_node_position(t_node *stack, t_node *target) 
{
    int i;
    i = 1;
    while(stack) 
    {
        if(stack == target)
            return i;
        stack = stack->next;
        i++;
    }
    return (-1);
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
    if(method == RX)
        pos = mid - 1;
    else if(method == RRX)
        pos = mid + 1;
    if(pos <= mid)
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
}
int get_node_to_top(t_node **stack, t_node *node_x, int flag)
{
    int med_pos;
    int x_pos;
    int count;

    count = 0;
    med_pos = ft_lstsize_int(*stack) / 2;
    x_pos = get_node_position(*stack, node_x);
    if(x_pos > med_pos)
    {
        while(*stack != node_x)
        {
            rrx(stack, flag);
            count++;
        }
    }
    else
    {
        while(*stack != node_x)
        {
            rx(stack, flag);
            count++;
        }
    }
    return (count);
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
