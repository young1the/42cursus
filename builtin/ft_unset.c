#include "../include/minishell.h"

static void	fill_unset_numbers(char **valid_datas, char **envs,
							int *del_numbers)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (valid_datas[j] != NULL)
	{
		while (envs[i] != NULL)
		{
			if (ft_envcmp(valid_datas[j], envs[i]) == 0)
			{
				*del_numbers = i;
				del_numbers++;
			}
			i++;
		}
		j++;
	}
}

static int	unset_count(char **valid_datas, char **envs)
{
	int		i;
	int		j;
	int		count;

	j = 0;
	count = 0;
	while (valid_datas[j] != NULL)
	{
		i = 0;
		while (envs[i] != NULL)
		{
			if (ft_envcmp(valid_datas[j], envs[i]) == 0)
				count++;
			i++;
		}
		j++;
	}
	return (count);
}

static char	**make_unsetted_envp(char **valid_datas, char **envs, int *del_nums)
{
	int		i;
	int		j;
	int		count;
	char	**new;

	count = unset_count(valid_datas, envs);
	i = 0;
	while (envs[i] != NULL)
		i++;
	j = i - count + 1;
	new = (char **)malloc(sizeof(char *) * (j));
	count = j;
	i = 0;
	j = 0;
	while (count > 0)
	{
		if (j == *del_nums)
			del_nums++;
		else
			new[i++] = ft_strdup(envs[j]);
		j++;
		count--;
	}
	new[i] = NULL;
	return (new);
}

int	ft_unset(char **cmd)
{
	char	**new;
	char	**valid_datas;
	int		*del_nums;
	int		count;

	valid_datas = make_valid_datas(cmd);
	if (valid_datas == NULL)
		return (1);
	count = unset_count(valid_datas, g_mini.envs);
	del_nums = (int *)malloc(sizeof(int) * (count));
	fill_unset_numbers(valid_datas, g_mini.envs, del_nums);
	new = make_unsetted_envp(valid_datas, g_mini.envs, del_nums);
	free(del_nums);
	free_argv(valid_datas);
	free_argv(g_mini.envs);
	g_mini.envs = new;
	return (0);
}
