#include "../push_swap.h"

t_node *ft_lstnew_int(int data)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    if(!node)
        return (NULL);
    node->data = data;
    node->rank = -1;
    node->is_lis = FALSE;
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

void ft_lstaddfront_int(t_node **ptr_to_node, t_node *node_to_add)
{
    if(node_to_add)
    {
        node_to_add->next = *ptr_to_node;
        *ptr_to_node = node_to_add;
    }
}

void ft_lstiter_int(t_node *head, void(*f)(int, int, int))
{
    if(!head)
    {
        printf("HEAD IS NULL\n");
        return;
    }
    t_node *copy = head;
    while(copy->next)
    {
        f(copy->data, copy->rank, copy->is_lis);
        copy = copy->next;
    }
    f(copy->data, copy->rank, copy->is_lis);
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