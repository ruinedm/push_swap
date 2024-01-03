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

t_node *get_smallest_node(t_node *stack)
{
    t_node *smallest_node;
    t_node *current_node;
    t_node *looping_node;

    current_node = stack;
    smallest_node = current_node;
    while(current_node->next)
    {
        looping_node = current_node->next;
        while(looping_node)
        {
            if(looping_node->data < smallest_node->data)
                smallest_node = looping_node;
            looping_node = looping_node->next;
        }
        current_node = current_node->next;
    }
    return (smallest_node);
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

void push_smallest(t_node **s_stack, t_node **r_stack, int flag)
{
    t_node *smallest_node;
    int medium_pos;
    int small_pos;

    medium_pos = ft_lstsize_int(*s_stack) / 2;
    small_pos = get_smallest_node_position(*s_stack);
    smallest_node = get_smallest_node(*s_stack);
    while(*s_stack != smallest_node)
    {
        if (small_pos > medium_pos)
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
