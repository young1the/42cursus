#include "../include/minishell.h"

int	ft_exit(char **cmd)
{
	int		exit_num;

	if (cmd[1] == NULL)
		exit (0);
	else
	{
		exit_num = ft_atoi(cmd[1]);
		exit (exit_num);
	}
	return (1);
}
