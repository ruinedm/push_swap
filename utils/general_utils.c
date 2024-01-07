#include "../push_swap.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
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
        if (current_node->data < smallest_node->data)
            smallest_node = current_node;
        current_node = current_node->next;
    }
    return smallest_node;
}


int get_smallest_node_position(t_node *stack) 
{
    t_node *current_node = stack;
    int smallest_data = current_node->data;
    int smallest_position = 0;
    int current_position = 0;

    while(current_node) {
        if(current_node->data < smallest_data) {
            smallest_data = current_node->data;
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


void rank_nodes(t_node *stack_a)
{
    t_node *looping_node;
    int *copy_array;
    int stack_size;
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

void push_elements(t_node **s_stack, t_node **r_stack, int flag)
{
    while (*s_stack != NULL)
    {
        px(s_stack, r_stack, flag);
    }
}
