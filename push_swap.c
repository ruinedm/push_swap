#include "push_swap.h"

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

t_node *parser(char *argv[], int stack_size)
{
    t_node *head;
    t_node *current_node;
    int value;
    int i;

    i = 0;
    head = NULL;
    while(i <= stack_size)
    {
        value = atoi(argv[i + 1]);
        current_node = ft_lstnew_int(value);
        ft_lstaddback_int(&head, current_node);
        i++;
    }
    return (head);
}

int main(int argc, char *argv[])
{
    int stack_size;
    t_node *stack_a;
    stack_size = argc - 1;
    if(argc == 1)
    {
        printf("Error");
        return (0);
    }
    stack_a = parser(argv, stack_size);
    if(!check_duplicates(stack_a))
    {
        printf("Error");
        return (0);
    }
}