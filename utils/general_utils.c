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

