#include "../push_swap.h"

void print(int data, int rank)
{
    printf("VALUE: %d RANK: %d\n", data, rank);
}

int get_node_type(t_node *stack, int rank, t_node **insert_before)
{
    t_node *looping_node;

    looping_node = stack;
    while(looping_node)
    {
        if(looping_node->rank > rank)
            break;
        looping_node = looping_node->next;
    }
    if(looping_node == stack) // loop broke from first iteration => rank is smaller than all
    {
        *insert_before = NULL;
        return (SMALLER_THAN_ALL);
    }
    else if(looping_node == NULL) // loop never broke (or loop never worked :D first iteration) => rank is less than all or is the first => SAME ACTION
    {
        *insert_before = NULL;
        return (BIGGER_THAN_ALL);
    }
    else // loop broke on the node with the rank just bigger than our node
    {
        *insert_before = looping_node;
        return (BETWEEN_X_AND_Y);
    }
}


void sort_all(t_node **stack_a, int stack_size)
{
    t_node *stack_b;
    t_node *to_push;
    t_node *insert_before;
    int chunk_start;
    int chunk_end;
    int push_counter;
    int type;
    int count;
    int mode;

    push_counter = 0;
    stack_b = NULL;
    rank_nodes(*stack_a, stack_size);
    mode = 0;
    chunk_start = 1;
    while (chunk_start <= stack_size)
    {
        chunk_end = chunk_start + 9;
        if (chunk_end > stack_size) chunk_end = stack_size;

        push_counter = 0;
        while(push_counter < (chunk_end - chunk_start + 1))
        {
            to_push = find_optimal_move_node(*stack_a, chunk_start, chunk_end, stack_size);
            type = get_node_type(stack_b, to_push->rank, &insert_before);
            if(type == SMALLER_THAN_ALL)
                push_node_x(stack_a, &stack_b,to_push, STACK_A);
            else if (type == BIGGER_THAN_ALL)
            {
                push_node_x(stack_a, &stack_b,to_push, STACK_A);
                rx(&stack_b, STACK_B);
            }
            else
            {
                count = get_node_to_top(&stack_b, insert_before, STACK_B, &mode);
                push_node_x(stack_a, &stack_b,to_push, STACK_A);
                reverse_get_node_to_top(&stack_b, count, STACK_B, mode);
            }
            push_counter++;
        }
        chunk_start += 10;

    }
    // printf("STACK A:\n");
    // ft_lstiter_int(*stack_a, print);
    printf("STACK B:\n");
    ft_lstiter_int(stack_b, print);
}

// You'll need to implement these helper functions:
// - rank_nodes: Assign a rank to each node based on its value
// - is_chunk_sorted: Check if a chunk is sorted in stack A
// - find_optimal_move_node: Find the node in the chunk that requires the least moves to be at the top
// - move_node_to_top: Execute moves (ra or rra) to bring a node to the top of stack A
// - push_to_stack_b: Push the top node from stack A to stack B
// - push_to_stack_a: Push the top node from stack B to stack A

