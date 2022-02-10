#include "../include/minishell.h"

char	*find_value(char **envs, char *key)
{
	int		i;
	char	*value;

	i = 0;
	while (envs[i] != NULL)
	{
		if (ft_envcmp(key, envs[i]) == 0)
		{
			value = ft_strdup(envs[i] + ft_strlen(key) + 1);
			return (value);
		}
		i++;
	}
	value = ft_strdup("");
	return (value);
}
