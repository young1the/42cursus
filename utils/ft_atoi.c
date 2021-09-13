#include "../philosopher.h"

int	ft_atoi(char *str)
{
	long long	ret;
	long long	sign;

	ret = 0;
	sign = 1;
	while (*str >= '0' && *str <= '9')
	{
		if (ret > 2147483647 && sign == 1)
			return (-1);
		if (ret > 2147483648 && sign == -1)
			return (0);
		ret *= 10;
		ret += *str - '0';
		str++;
	}
	return (ret * sign);
}
