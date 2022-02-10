#include "../include/minishell.h"

int	replace_env(char *valid_data, char **key)
{
	int		i;

	i = 0;
	while (g_mini.envs[i] != NULL)
	{
		if (ft_envcmp(key[0], g_mini.envs[i]) == 0)
		{
			free(g_mini.envs[i]);
			g_mini.envs[i] = ft_strdup(valid_data);
			return (1);
		}
		i++;
	}
	return (0);
}

char	**env_key(char *data)
{
	char	**key;
	int		i;

	key = (char **)malloc(sizeof(char *) * 2);
	i = 0;
	while (data[i] != '\0')
	{
		if (data[i] == '=')
		{
			key[0] = ft_strndup(data, i);
			key[1] = NULL;
			return (key);
		}
		i++;
	}
	key[0] = ft_strdup(data);
	key[1] = NULL;
	return (key);
}

char	**get_new_valid_datas(char **valid_datas)
{
	char	**key;
	char	**new;
	char	**temp;
	int		i;

	i = 0;
	new = (char **)malloc(sizeof(char *));
	new[0] = NULL;
	while (valid_datas[i] != NULL)
	{
		key = env_key(valid_datas[i]);
		if (!replace_env(valid_datas[i], key))
		{
			free(key[0]);
			key[0] = ft_strdup(valid_datas[i]);
			temp = new;
			new = ft_argsjoin(new, key);
			free_argv(temp);
		}
		free_argv(key);
		i++;
	}
	return (new);
}
