#include "../checker.h"

static int	int_checker(const char *str, int i, int sign, t_node *head)
{
	unsigned long long	nb;

	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
    if(sign == 1 && nb > INT_MAX)
    {
        ft_lstclear_int(head);
        printf("Error\n");
        exit(EXIT_FAILURE);
    }
    else if(sign == -1 && nb > (unsigned long long)INT_MAX + 1)
    {
        ft_lstclear_int(head);
        printf("Error\n");
        exit(EXIT_FAILURE);
    }
	return ((int)nb * sign);
}

int	ft_atoi(char *str, t_node *head)
{
	int		sign;
	size_t	i;

	sign = 1;
	i = 0;
 
    while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] == '0')
        i++;
    return (int_checker(str, i, sign, head));
}
