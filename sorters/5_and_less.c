#include "../push_swap.h"

void sort3(t_node *stack_a)
{
    int a;
    int b;
    int c;
    
    a = stack_a->data;
    b = stack_a->next->data;
    c = stack_a->next->next->data;
    if(a > b && b > c)
        printf("ra\nsa");
    else if(a > b && a > c && c > b)
        printf("ra");
    else if(a > b && a < c && c > a)
        printf("sa");
    else if(a < b && a > c && b > c)
        printf("ra\nra");
    else if(a < b && a < c && b > c)
        printf("sa\nra");
}

void sort4(t_node **stack_a)
{
    t_node *stack_b;

    stack_b = NULL;
    
}