#include "../include/minishell.h"

void	free_argv(char **datas)
{
	int		i;

	i = 0;
	if (datas == NULL)
		return ;
	while (datas[i] != NULL)
	{
		free (datas[i]);
		i++;
	}
	free(datas);
}
