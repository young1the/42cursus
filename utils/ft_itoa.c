#include "../minitalk.h"

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

char	*ft_itoa(int n)
{
	size_t	minus;
	long	nbr;
	char	*ret;

	minus = 0;
	nbr = (long)n;
	if (nbr < 0)
	{
		nbr *= -1;
		minus += 1;
	}
	ret = malloc(count_num(nbr) + minus + 1);
	if (!ret)
		return (NULL);
	if (minus == 1)
		put_num_minus(ret, nbr, count_num(nbr) + minus + 1);
	else
		put_num(ret, nbr, count_num(nbr) + minus + 1);
	return (ret);
}
