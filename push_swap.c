#include "push_swap.h"
#include <i386/limits.h>


int is_sorted(t_node *stack)
{
    t_node *current_node;

    current_node = stack;
    while (current_node != NULL && current_node->next != NULL)
    {

        if (current_node->data > current_node->next->data)
            return (0);
        current_node = current_node->next;
    }
    return (1);
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

int free_and_end(t_node *stack_a)
{
    printf("Error\n");
    ft_lstclear_int(stack_a);
    return (0);
}


void print(int data)
{
    printf("%d\n", data);
}

int main(int argc, char *argv[])
{
    int stack_size;
    t_node *stack_a;

    stack_a = NULL;
    stack_size = argc - 1;
    if(argc == 1)
        return(0);
    stack_a = parser(argv, stack_size);
    ft_lstiter_int(stack_a, print);

    // if(!stack_a  || !check_duplicates(stack_a) || is_sorted(stack_a))
    //     return(free_and_end(stack_a));
    // sort_handler(&stack_a, stack_size);
    // ft_lstclear_int(stack_a);
}