#include "../include/minishell.h"

static int	find_cdenv(char *cmp)
{
	int		i;

	i = 0;
	while (g_mini.envs[i] != NULL)
	{
		if (!ft_envcmp(cmp, g_mini.envs[i]))
			break ;
		i++;
	}
	return (i);
}

void	change_cdenv(char *str, int flag)
{
	char	*cdenv;
	char	*temp;
	char	*join;
	char	*cmp;
	int		i;

	if (flag == 0)
	{
		join = "OLDPWD=";
		cmp = "OLDPWD";
	}
	else
	{
		join = "PWD=";
		cmp = "PWD";
	}
	cdenv = ft_strjoin(join, str);
	i = find_cdenv(cmp);
	temp = g_mini.envs[i];
	g_mini.envs[i] = cdenv;
	free (temp);
}

void	ft_cd_err(char **cmd)
{
	ft_error("minishell : cd : ");
	if (cmd[1] == NULL)
	{
		ft_error("HOME not set\n");
		return ;
	}
	ft_error(strerror(errno));
	ft_error(" : ");
	ft_error(cmd[1]);
	ft_error("\n");
}
