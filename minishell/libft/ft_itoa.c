#include "../include/minishell.h"

static char	*put_num(char *ret, long n, size_t size)
{
	ret[size - 1] = '\0';
	while (size >= 2)
	{
		ret[size - 2] = n % 10 + '0';
		n /= 10;
		size--;
	}
	return (ret);
}

static char	*put_num_minus(char *ret, long n, size_t size)
{
	ret[size - 1] = '\0';
	while (size >= 2)
	{
		ret[size - 2] = n % 10 + '0';
		n /= 10;
		size--;
	}
	ret[0] = '-';
	return (ret);
}

static size_t	count_num(long n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	size_t	minus;
	char	*ret;

	minus = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		minus += 1;
	}
	if (minus == 1)
	{
		ret = malloc(count_num(nbr) + minus + 1);
		if (ret == NULL)
			return (NULL);
		put_num_minus(ret, nbr, count_num(nbr) + minus + 1);
	}
	else
	{
		ret = malloc(count_num(nbr) + minus + 1);
		if (ret == NULL)
			return (NULL);
		put_num(ret, nbr, count_num(nbr) + minus + 1);
	}
	return (ret);
}
