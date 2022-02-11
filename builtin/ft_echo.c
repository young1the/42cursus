#include "../include/minishell.h"

static int	check_nflag(char *str, int *flag)
{
	if (*(str++) != '-')
		return (FALSE);
	if (*str != 'n')
		return (FALSE);
	while (*str != '\0')
	{
		if (*str != 'n')
			return (FALSE);
		str++;
	}
	*flag = 1;
	return (TRUE);
}

static int	get_flag(char **cmd, int *flag)
{
	int		i;

	i = 1;
	if (cmd[i] == NULL)
		return (i);
	while (cmd[i] != NULL)
	{
		if (check_nflag(cmd[i], flag) == FALSE)
			return (i);
		i++;
	}
	return (i);
}

int	ft_echo(char **cmd)
{
	int		flag;
	int		i;

	flag = 0;
	i = get_flag(cmd, &flag);
	while (cmd[i] != NULL)
	{
		printf("%s", cmd[i]);
		if (cmd[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (flag == 0)
		printf("\n");
	return (0);
}
