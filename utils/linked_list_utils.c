#include "../push_swap.h"

t_node *ft_lstnew_int(int data)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    if(!node)
        return (NULL);
    node->data = data;
    node->rank = -1;
    node->moves[0] = 0;
    node->moves[1] = 0;
    node->next = NULL;
    node->prev = NULL;
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
    t_node *last_node;

    if(!*ptr_to_node)
        *ptr_to_node = node_to_add;
    else
    {
        last_node = ft_lstlast_int(*ptr_to_node);
        last_node->next = node_to_add;
        node_to_add->prev = last_node;
    }
}


void ft_lstaddfront_int(t_node **ptr_to_node, t_node *node_to_add)
{
    if(node_to_add)
    {
        node_to_add->next = *ptr_to_node;
        node_to_add->prev = NULL;
        if (*ptr_to_node)
            (*ptr_to_node)->prev = node_to_add;
        *ptr_to_node = node_to_add;
    }
}


void ft_lstiter_int(t_node *head, void(*f)(int, int, int *))
{
    if(!head)
        return;
    t_node *copy = head;
    while(copy->next)
    {
        f(copy->data, copy->rank, copy->moves);
        copy = copy->next;
    }
    f(copy->data, copy->rank, copy->moves);
}

void ft_lstclear_int(t_node *head)
{
    t_node *tmp;

    while(head)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}

int ft_lstsize_int(t_node *lst)
{
    int i;

    i = 0;
    while(lst)
    {
        i++;
        lst = lst->next;
    }
    return (i);
}