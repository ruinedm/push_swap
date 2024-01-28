#include "../checker.h"

void print(int data, int rank, int *moves)
{
    printf("VALUE: %d // RANK: %d // MOVES B: %i // MOVES A: %i\n", data, rank, moves[0], moves[1]);
}
int is_sorted(t_node *stack)
{
    t_node *current_node;

    current_node = stack;
    while (current_node != NULL && current_node->next != NULL)
    {
        if(current_node->next->rank != current_node->rank + 1)
            return (FALSE);
        current_node = current_node->next;
    }
    return (TRUE);
}
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ( (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void handle_checker(t_node **stack_a, int stack_size)
{
    t_node *stack_b;
    char *move;

    stack_b = NULL;
    while((move = get_next_line(0)) != NULL)
    {
        if(ft_strcmp(move, "pa\n") == 0)
            px(&stack_b,stack_a, SILENT);
        else if(ft_strcmp(move, "pb\n") == 0)
            px(stack_a,&stack_b, SILENT);
        else if(ft_strcmp(move, "sa\n") == 0)
            sx(stack_a, SILENT);
        else if(ft_strcmp(move, "sb\n") == 0)
            sx(&stack_b, SILENT);
        else if(ft_strcmp(move, "ra\n") == 0)
            rx(stack_a, SILENT);
        else if(ft_strcmp(move, "rb\n") == 0)
            rx(&stack_b, SILENT);
        else if(ft_strcmp(move, "rra\n") == 0)
            rrx(stack_a, SILENT);
        else if(ft_strcmp(move, "rrb\n") == 0)
            rx(&stack_b, SILENT);
        else if(ft_strcmp(move, "ss\n") == 0)
            ss(stack_a, &stack_b);
        else if(ft_strcmp(move, "rr\n") == 0)
            rr(stack_a, &stack_b);
        else if(ft_strcmp(move, "rrr\n") == 0)
            rr(stack_a, &stack_b);
        else if(ft_strcmp(move, "print\n") == 0)
        {
            puts("STACK A");
            ft_lstiter_int(*stack_a, print);
            puts("STACK B");
            ft_lstiter_int(stack_b, print);
        }
        else
        {
            printf("Error\n");
            exit(EXIT_FAILURE);
        }
    }
    if(ft_lstsize_int(*stack_a)==stack_size && is_sorted(*stack_a))
        printf("OK\n");
    else
        printf("KO\n");
}