// #include "../push_swap.h"

// //HELPER FUNCTIONS


// t_node* get_first_and_last(t_node *stack, int start, int end, int mode) 
// {
//     t_node *looping_node;
//     t_node *current_end;

//     if(!stack) printf("STACK IS NULL!!!!");
//     looping_node = stack;
//     current_end = NULL;
//     while(looping_node)
//     {
//         //if(current_end) printf("CURRENT END RANK:%i\n", current_end->rank);
//         if(looping_node->rank >= start && looping_node->rank <= end) 
//         {
//             if(mode == FIRST)
//                 return looping_node;
//             current_end = looping_node;
//         }
//         looping_node = looping_node->next;
//     }
//     return (current_end);
// }

// int get_cost_to_top(t_node *stack, t_node *target, int stack_size)
// {
//     t_node *looping_node;
//     int mid;
//     int pos;
//     int mode;
//     int cost;

//     cost = 0;
//     mode = 1;
//     mid = stack_size / 2;
//     pos = get_node_position(stack, target);
//     if(pos < mid)
//         looping_node = stack;
//     else
//     {
//         looping_node = target;
//         mode = 0;
//     }
//     while(looping_node)
//     {
//         if(looping_node == target && mode)
//             return (cost);
//         looping_node = looping_node->next;
//         cost++;
//     }
//     return (cost);
// }


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
//     if(cost_first >  cost_last)
//         return (last);
//     return (first);
// }

// int get_node_type(t_node *stack, int rank, t_node **insert_before)
// {
//     t_node *looping_node;

//     looping_node = stack;
//     while(looping_node)
//     {
//         if(looping_node->rank > rank)
//             break;
//         looping_node = looping_node->next;
//     }
//     if(looping_node == stack) // loop broke from first iteration => rank is smaller than all
//     {
//         *insert_before = NULL;
//         return (SMALLER_THAN_ALL);
//     }
//     else if(looping_node == NULL) // loop never broke (or loop never worked :D first iteration) => rank is less than all or is the first => SAME ACTION
//     {
//         *insert_before = NULL;
//         return (BIGGER_THAN_ALL);
//     }
//     else // loop broke on the node with the rank just bigger than our node
//     {
//         *insert_before = looping_node;
//         return (BETWEEN_X_AND_Y);
//     }
// }


// void sort_all_old(t_node **stack_a, int stack_size)
// {
//     t_node *stack_b;
//     t_node *to_push;
//     t_node *insert_before;
//     int chunk_start;
//     int chunk_end;
//     int push_counter;
//     int type;
//     int count;
//     int mode;

//     push_counter = 0;
//     stack_b = NULL;
//     rank_nodes(*stack_a, stack_size);
//     mode = 0;
//     chunk_start = 1;
//     while (chunk_start <= stack_size)
//     {
//         chunk_end = chunk_start + 4;
//         if (chunk_end > stack_size) chunk_end = stack_size;

//         push_counter = 19;
//         while(push_counter < (chunk_end - chunk_start + 1))
//         {
//             to_push = find_optimal_move_node(*stack_a, chunk_start, chunk_end, stack_size);
//             type = get_node_type(stack_b, to_push->rank, &insert_before);
//             if(type == SMALLER_THAN_ALL)
//                 push_node_x(stack_a, &stack_b,to_push, STACK_A);
//             else if (type == BIGGER_THAN_ALL)
//             {
//                 push_node_x(stack_a, &stack_b,to_push, STACK_A);
//                 rx(&stack_b, STACK_B);
//             }
//             else // BETWEEN X AND Y
//             {
//                 count = get_node_to_top(&stack_b, insert_before, STACK_B, &mode);
//                 push_node_x(stack_a, &stack_b,to_push, STACK_A);
//                 reverse_get_node_to_top(&stack_b, count, STACK_B, mode);
//             }
//             push_counter++;
//         }
//         chunk_start += 20;

//     }
//     printf("STACK A:\n");
//     // ft_lstiter_int(*stack_a, print);
//     // printf("STACK B:\n");
//     // ft_lstiter_int(stack_b, print);
// }
