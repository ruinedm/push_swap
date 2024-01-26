#include "push_swap.h"




int main(int argc, char *argv[])
{
    int stack_size;
    t_node *stack_a;

    stack_a = NULL;
    stack_size = argc - 1;
    if(argc == 1)
        return(0);
    stack_a = parser(argv, stack_size);
    if(!stack_a  || !check_duplicates(stack_a))
        return(printf("Error\n"), 0);    
    sort_handler(&stack_a, stack_size);
    ft_lstclear_int(stack_a);
}