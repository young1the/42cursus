#include "libft.h"

int	ft_atoi(const char *str)
{
	long	ret;
	long	sign;

	ret = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
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
