#include "../include/minishell.h"

int	find_pipe(char *buf)
{
	int		i;
	char	quote;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\"' || buf[i] == '\'')
		{
			quote = buf[i];
			i++;
			while (buf[i] != quote && buf[i] != '\0')
				i++;
		}
		else if (buf[i] == '|')
			return (i);
		else
			i++;
	}
	return (-1);
}
