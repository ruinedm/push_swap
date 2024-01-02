#include "../push_swap.h"

static int	int_checker(const char *str, int i, int sign, int *error_flag)
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
        *error_flag = 0;
        return (-1);
    }
    else if(sign == -1 && nb > (unsigned long long)INT_MAX + 1)
    {
        *error_flag = 0;
        return(-1);
    }
	return ((int)nb * sign);
}

int	ft_atoi(char *str, int *error_flag)
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
    return (int_checker(str, i, sign, error_flag));
}
