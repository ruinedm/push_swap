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
    else
    {
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
// void print(int data, int rank, int *moves)
// {
//     printf("VALUE: %d // RANK: %d // MOVES B: %i // MOVES A: %i\n", data, rank, moves[0], moves[1]);
// }