#include "../include/minishell.h"

int	find_pipe(char *buf)
{
	int		i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\"')
		{
			i++;
			while (buf[i] != '\"' && buf[i] != '\0')
				i++;
		}
		else if (buf[i] == '|')
			return (i);
		else
			i++;
	}
	return (-1);
}
