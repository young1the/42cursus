#include "../include/minishell.h"

static int	atoll_fail(int *flag)
{
	*flag = FALSE;
	return (0);
}

static long long	exit_atoll(const char *str, int *flag)
{
	long long	ret;
	long long	sign;

	ret = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (ret > INT32_MAX && sign == 1)
			atoll_fail(flag);
		if (ret >= INT32_MAX && sign == -1)
			atoll_fail(flag);
		ret *= 10;
		ret += *str - '0';
		str++;
	}
	if (*str == '\0')
		return (ret * sign);
	return (atoll_fail(flag));
}

static int	ft_exit_argc_check(char **cmd)
{
	int		i;

	i = 0;
	while (cmd[i] != NULL)
		i++;
	if (i > 2)
	{
		printf("minishell : exit : too many argumets\n");
		return (FALSE);
	}
	return (TRUE);
}

int	ft_exit(char **cmd)
{
	long long	exit_num;
	int			flag;

	flag = TRUE;
	if (cmd[1] == NULL)
		exit (0);
	else
	{
		if (!ft_exit_argc_check(cmd))
			return (1);
		exit_num = exit_atoll(cmd[1], &flag);
		if (flag == FALSE)
		{
			printf("minishell : exit : ");
			printf("%s : numeric argument required\n", cmd[1]);
			exit (255);
		}
		exit_num %= 256;
		exit ((int)exit_num);
	}
	return (1);
}
