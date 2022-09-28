#include "../include/minishell.h"

static int	check_enviroment(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	ft_env(void)
{
	int		i;

	i = 0;
	while (g_mini.envs[i] != NULL)
	{
		if (check_enviroment(g_mini.envs[i]))
			printf("%s\n", g_mini.envs[i]);
		i++;
	}
	return (0);
}
