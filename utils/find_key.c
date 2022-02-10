#include "../include/minishell.h"

char	*find_key(char *string)
{
	int		i;
	int		j;
	char	*key;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '$')
		{
			i++;
			j = i;
			if (string[i] == '?')
			{
				key = ft_strdup("?");
				return (key);
			}
			while (ft_isalnum(string[i]))
				i++;
			key = ft_strndup(string + j, i - j);
			return (key);
		}
		i++;
	}
	return (NULL);
}
