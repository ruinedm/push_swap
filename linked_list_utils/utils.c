#include "../push_swap.h"

t_node *ft_lstnew_int(int data)
{
    t_node *node;
    node = malloc(sizeof(t_node));
    if(!node)
        return (NULL);
    node->data = data;
    node->next = NULL;
    return (node);
}

t_node *ft_lstlast_int(t_node *node)
{
    t_node *last_node;

    last_node = node;
    while(last_node->next != NULL)
        last_node = last_node->next;
    return (last_node);
}

void ft_lstaddback_int(t_node **ptr_to_node, t_node *node_to_add)
{
    if(!*ptr_to_node)
    {
        *ptr_to_node = node_to_add;
        return;
    }
    ft_lstlast_int(*ptr_to_node)->next = node_to_add;
}

void ft_lstiter_int(t_node *head, void(*f)(int))
{
    t_node *copy = head;
    while(copy->next != NULL)
    {
        f(copy->data);
        copy = copy->next;
    }
}