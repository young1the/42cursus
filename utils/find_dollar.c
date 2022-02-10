#include "../include/minishell.h"

int	find_dollar(char *string)
{
	int		index;

	index = 0;
	while (string[index] != '\0')
	{
		if (string[index] == '$')
			return (index);
		index++;
	}
	return (-1);
}
