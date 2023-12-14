#include "../push_swap.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

void sort_handler(t_node *stack_a, int stack_size)
{
    if(stack_size == 2)
        printf("ra");
    else if(stack_size == 3)
        sort3(stack_a);
}

t_node *stack_creator(int stack_size)
{
    int i;
    t_node *stack_b;
    t_node *empty_node;

    i = 0;
    stack_b = NULL;
    while(i < stack_size)
    {
        empty_node = ft_lstnew_int(0);
        if(!empty_node)
            {
                ft_lstclear_int(stack_b);
                return (NULL);
            }
        ft_lstaddback_int(&stack_b, empty_node);
        i++;
    }
    return(stack_b);
}