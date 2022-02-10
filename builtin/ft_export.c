#include "../include/minishell.h"

static void	print_env(char *env)
{
	int		i;
	int		flag;

	i = 0;
	flag = -1;
	while (env[i] != '\0')
	{
		if (env[i] == '=')
			flag++;
		write (1, &(env[i]), 1);
		if (flag == 0)
		{
			flag++;
			write (1, "\"", 1);
		}
		i++;
	}
	if (flag == 1)
		write (1, "\"", 1);
}

static void	print_export(char **envs)
{
	int		i;

	i = 0;
	while (envs[i] != NULL)
	{
		print_env(envs[i]);
		write (1, "\n", 1);
		i++;
	}
}

int	ft_export(char **cmd)
{
	char	**new;
	char	**valid_datas;
	char	**new_valid_datas;

	if (cmd[1] == NULL)
	{
		print_export(g_mini.envs);
		return (0);
	}
	valid_datas = make_valid_datas(cmd);
	if (valid_datas == NULL)
		return (1);
	new_valid_datas = get_new_valid_datas(valid_datas);
	new = ft_argsjoin(g_mini.envs, new_valid_datas);
	free_argv(valid_datas);
	free_argv(new_valid_datas);
	free_argv(g_mini.envs);
	g_mini.envs = new;
	return (0);
}
