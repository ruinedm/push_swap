#include "../push_swap.h"

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
    return (smallest_node);
}
