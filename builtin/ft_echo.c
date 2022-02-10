#include "../include/minishell.h"

int	ft_echo(char **cmd)
{
	int		flag;
	int		i;

	flag = -1;
	if (cmd[1] != NULL)
	{
		flag = ft_strcmp(cmd[1], "-n");
		i = 1;
		if (flag == 0)
			i = 2;
		while (cmd[i] != NULL)
		{
			printf("%s", cmd[i]);
			printf(" ");
			i++;
		}
	}
	if (flag != 0)
		printf("\n");
	return (0);
}
