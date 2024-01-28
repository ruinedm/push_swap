#include "../push_swap.h"

void print(int data, int rank, int *moves)
{
    printf("VALUE: %d // RANK: %d // MOVES B: %i // MOVES A: %i\n", data, rank, moves[0], moves[1]);
}

int check_duplicates(t_node *stack)
{
    t_node *current_node;
    t_node *looping_node;

    current_node = stack;
    while(current_node->next)
    {
        looping_node = current_node->next;
        while(looping_node)
        {
            if(current_node->data == looping_node->data)
                return (0);
            looping_node = looping_node->next;
        }
        current_node = current_node->next;
    }
    return (1);
}


int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
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

void sort_handler(t_node **stack_a, int stack_size)
{
    if(stack_size == 2)
        printf("ra\n");
    else
    {
        rank_nodes(*stack_a, stack_size);
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


void bubble_sort(int *arr, int n) {
    int i;
    int j;

    i = 0;
    while (i < n - 1) 
    {
        j = 0;
        while (j < n - i - 1) {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        i++;
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
    i = 0;
    while(stack) 
    {
        if(stack == target)
            return i;
        stack = stack->next;
        i++;
    }
    return (-1);
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

void push_with_pivot(t_node **s_stack,t_node **r_stack, int stack_size)
{
    t_node *looping_node;
    t_node *next_node;
    int i;

    i = 0;
    looping_node = *s_stack;
    while(i < stack_size)
    {
        next_node = looping_node->next;
        if(looping_node->rank < stack_size / 2)
            px(s_stack, r_stack, STACK_B);
        else
            rx(s_stack, STACK_A);
        looping_node = next_node;
        i++;
    }
    while(ft_lstsize_int(*s_stack) > 3)
        px(s_stack, r_stack, STACK_B);
    sort3(s_stack);
}
