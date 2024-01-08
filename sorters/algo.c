#include "../push_swap.h"

void print(int data, int rank)
{
    printf("VALUE: %d RANK: %d\n", data, rank);
}
// Helper function to find the correct position in stack B
int find_insert_position(t_node *stack_b, t_node *to_push) {
    int pos = 0;
    t_node *current = stack_b;
    while (current != NULL && current->rank < to_push->rank) {
        pos++;
        current = current->next;
    }
    return pos;
}

// Helper function to rotate stack B to the correct position
void rotate_to_position(t_node **stack_b, int pos, int stack_size) {
    if (pos <= stack_size / 2) {
        for (int i = 0; i < pos; i++) {
            rx(stack_b, STACK_B); // Rotate
        }
    } else {
        for (int i = 0; i < stack_size - pos; i++) {
            rrx(stack_b, STACK_B); // Reverse Rotate
        }
    }
}

// Function to insert node in correct position in stack B
void insert_in_correct_position(t_node **stack_b, t_node *to_push, int stack_size) {
    int insert_pos = find_insert_position(*stack_b, to_push);
    rotate_to_position(stack_b, insert_pos, stack_size);
    px(&to_push, stack_b, STACK_B); // Push the node to stack B
    // Rotate stack B back to its original order if necessary
    //rotate_to_position(stack_b, stack_size - insert_pos - 1, stack_size);
}



void sort_all(t_node **stack_a, int stack_size)
{
    t_node *stack_b;
    t_node *to_push;
    t_node *insert_before;
    int chunk_start;
    int chunk_end;
    int push_counter;

    push_counter = 0;
    stack_b = NULL;
    rank_nodes(*stack_a, stack_size);

    chunk_start = 1;
    while (chunk_start <= stack_size)
    {
        chunk_end = chunk_start + 19;
        if (chunk_end > stack_size) chunk_end = stack_size;


        while(push_counter < 4)
        {
            to_push = find_optimal_move_node(*stack_a, chunk_start, chunk_end, stack_size);
            if(stack_b)
            {
                insert_before = stack_b;
                while(insert_before && insert_before->rank < to_push->rank)
                    insert_before = insert_before->next;
            }
            if(insert_before == NULL)
            {
                push_node_x(stack_a, &stack_b,to_push, STACK_A);
                rx(&stack_b, STACK_B);
            }
            else 
            {
                get_node_to_top(&stack_b, insert_before, STACK_B);
                // push_node_x(stack_a, &stack_b,to_push, STACK_A);
                // get_node_to_bottom(&stack_b, to_push, STACK_B);
            }

            push_counter++;
        }
        chunk_start += 20; // Move to the next chunk

    }
    printf("STACK A:\n");
    ft_lstiter_int(*stack_a, print);
    printf("STACK B:\n");
    ft_lstiter_int(stack_b, print);

        // while (!is_chunk_sorted(*stack_a, chunk_start, chunk_end))
        // {
        //     to_push = find_optimal_move_node(*stack_a, chunk_start, chunk_end, stack_size);
        //     move_node_to_top(stack_a, to_push, stack_size);
        //     px(stack_a, &stack_b, STACK_B);
        // }


    // Reassemble the sorted list from stack B to stack A
    // while (stack_b != NULL)
    // {
    //     // Logic to handle sorting and pushing from stack B to A
    //     push_to_stack_a(&stack_b, stack_a);
    // }

    // Optional: Print stacks for debugging
    // printf("STACK A:\n");
    // ft_lstiter_int(*stack_a, print);
    // printf("STACK B:\n");
    // ft_lstiter_int(stack_b, print);
}

// You'll need to implement these helper functions:
// - rank_nodes: Assign a rank to each node based on its value
// - is_chunk_sorted: Check if a chunk is sorted in stack A
// - find_optimal_move_node: Find the node in the chunk that requires the least moves to be at the top
// - move_node_to_top: Execute moves (ra or rra) to bring a node to the top of stack A
// - push_to_stack_b: Push the top node from stack A to stack B
// - push_to_stack_a: Push the top node from stack B to stack A

