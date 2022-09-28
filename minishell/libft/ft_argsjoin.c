#include "../include/minishell.h"

char	**ft_argsjoin(char **args1, char **args2)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (args1[i] != NULL)
		i++;
	while (args2[j] != NULL)
		j++;
	new = (char **)malloc(sizeof(char *) * (i + j + 1));
	i = 0;
	j = 0;
	while (args1[i] != NULL)
	{
		new[i] = ft_strdup(args1[i]);
		i++;
	}
	while (args2[j] != NULL)
	{
		new[i + j] = ft_strdup(args2[j]);
		j++;
	}
	new[i + j] = NULL;
	return (new);
}
